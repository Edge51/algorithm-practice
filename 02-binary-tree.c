#include <stdio.h>
#include <stdlib.h>
typedef int Type;

typedef struct BinaryTreeNode{
	Type data;
	BinaryTreeNode* leftnode;
	BinaryTreeNode* rightnode;
}BinaryTreeNode;

BinaryTreeNode* createRoot(Type data);
BinaryTreeNode* insertNode(BinaryTreeNode* root, Type data);
void deleteNode(BinaryTreeNode* tree, Type data);
void breadthFirstTraverse(BinaryTreeNode* tree);
void depthFirstTraverse(BinaryTreeNode* tree);
BinaryTreeNode* createNode(Type data);

int main(){
	Type data;
	printf("Please input data:\n");
	scanf("%d", &data);
	BinaryTreeNode* root = createRoot(data);
}

BinaryTreeNode* createRoot(Type data){
	BinaryTreeNode* root = (BinaryTreeNode*) malloc(sizeof(BinaryTreeNode));
	root->data = data;
	root->leftnode = NULL;
	root->rightnode = NULL;
	return root;
}

BinaryTreeNode* createNode(Type data){
	BinaryTreeNode* node = (BinaryTreeNode*) malloc(sizeof(BinaryTreeNode));
	node->data = data;
	node->leftnode = NULL;
	node->rightnode = NULL;
	return node;
}

/*  the first version of insertNode is too complicated,
there is no need for so many if else, we just want to 
insert into the subtree that are NULL.
void insertNode(BinaryTreeNode* root, Type data){
	if(root == NULL){
		printf("Error! Root is NULL!\n");
		return ;
	}
	if(data == root->data){
		printf("Data to be inserted already exist!\n");
		return ;
	}else if(data < root->data && root->leftnode == NULL){
		root->leftnode = createNode(data);
	}else if(data < root->data && data <= root->leftnode->data){
		insertNode(root->leftnode, data);
	}else if(data <	root->data && data > root->leftnode->data){
		BinaryTreeNode* temp = createNode(data);
		temp->leftnode = root->leftnode;
		root->leftnode = temp;
	}else if(data > root->data && root->rightnode == NULL){
		root->rightnode = createNode(data);
	}else if(data > root->data && data >= root->rightnode->data){
		insertNode(root->rightnode, data);
	}else if(data > root->data && data < root->rightnode->data){
		BinaryTreeNode* temp = createNode(data);
		temp->rightnode = root->rightnode;
		root->rightnode = temp;
	}
	//only insert to one side
}
*/
/* The proper version of insertNode
* 
*/
BinaryTreeNode* insertNode(BinaryTreeNode* tree, Type data){
	if(tree == NULL){
		tree = (BinaryTreeNode*) malloc(sizeof(BinaryTreeNode));
		if(tree==NULL){
			printf("Out of space!\n");
		}else{
			tree = createNode(data);
		}
	}else if(data < tree->data){
		tree->leftnode = insertNode(tree->leftnode, data);
	}else if(data > tree->data){
		tree->rightnode = insertNode(tree->rightnode, data);
	}else{
		printf("The node to be inserted already exists in the tree!\n");
	}
	return tree;
}

/* 
 * todo write comments
**/
void deleteNode(BinaryTreeNode* tree, Type data){I
	
}
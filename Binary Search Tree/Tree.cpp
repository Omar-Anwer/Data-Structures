// tree.cpp : This file contains the 'main' function. Program emyTreeecution begins and ends there.
//

#include <iostream>
#include <queue>    // for BFS
using namespace std;

// Tree node	== Tree* pnode
// node			== (*pnode) 
// node->left	== &((*pnode)->left)
typedef int itemtype_t;

struct TreeNode
{
	itemtype_t item;
	TreeNode* left;
	TreeNode* right;
	//TreeNode* parent;
};
	typedef TreeNode* Tree;
	size_t noNodes = 0;
	size_t depth = 0;


Tree createTree(void)
{
	Tree root = new TreeNode;
	root = NULL;
	return root;
}

/*****************************Traversing Tree***********************************/
/* Depth-first Traversal*/

void inOrderTraversal(Tree node, void(pfunc)(itemtype_t))
{
	//in-Order = L-Root-R order (print between recursive calls in increasing order) 
	if (node == NULL) {
		return;
	}
	inOrderTraversal((node)->left, pfunc);
	(*pfunc)((node)->item);
	inOrderTraversal((node)->right, pfunc);

}

void postOrderTraversal(Tree node, void(pfunc)(itemtype_t))
{
	//Post-Order = LR-Root order (print after recursive calls)
	if ((node) == NULL) {
		return;
	}
	postOrderTraversal((node)->left, pfunc);
	postOrderTraversal((node)->right, pfunc);
	(*pfunc)((node)->item);
}

void preOrderTraversal(Tree node, void(pfunc)(itemtype_t))
{
	//Pre-Order = Root-LR order (print before recursive calls)
	if ((node) == NULL) {
		return;
	}
	(*pfunc)((node)->item);
	preOrderTraversal((node)->left, pfunc);
	preOrderTraversal((node)->right, pfunc);
}

/* Breadth-first Traversal*/
void levelOrderTraversal(Tree node, void(pfunc)(itemtype_t))
{
	if (node == NULL) {
		return;
	}
	queue<Tree> q;
	q.push(node);
	while (!q.empty())
	{
		Tree current = q.front();
		(*pfunc)((node)->item);
		if (current->left != NULL) {
			q.push(current->left);
		}
		if (current->right != NULL) {
			q.push(current->right);
		}
		q.pop();
	}
}

enum TreeTraversalOrder
{
	preOrder,
	inOrder,
	postOrder,
	levelOrder
};


void traverse(Tree node, void(pfunc)(itemtype_t), TreeTraversalOrder order)
{
	switch (order)
	{
		case preOrder:
			preOrderTraversal(node, pfunc);
			break;
		case inOrder:
			inOrderTraversal(node, pfunc);
			break;
		case postOrder:
			postOrderTraversal(node, pfunc);
			break;
		case levelOrder:
			levelOrderTraversal(node, pfunc);
			break;
	}
}

/**********************************************************************/
/*
Tree newNode(itemtype_t val)
{
	Tree node = new TreeNode;
	(node)->item = val;
	(node)->left = NULL;
	(node)->right = NULL;
	++noNodes;
	return (node);
}
*/

Tree insertNode(Tree node, itemtype_t val)
{

	if (node == NULL) {// empty tree
		//return newNode(val);
		Tree node = new TreeNode;
		(node)->item = val;
		(node)->left = NULL;
		(node)->right = NULL;
		++noNodes;
		return node;
	}

	if (val <= node->item) {
		node->left = insertNode(node->left, val);   /* if value is smaller or equal than the root node then insert to the left path */

	}
	else {
		node->right = insertNode(node->right, val);   /* if value is greater  than the root node then insert to the right path */
	}
	return (node);
}

Tree removeNode(Tree node)
{
	if (node == NULL) {// empty tree
		return NULL;
	}

	//--noNodes;
}

Tree searchTree(Tree node, itemtype_t val)
{
	if (node == NULL)
		return NULL;

	if (val == node->item)
		return node;

	else if (val <= node->item)
		return searchTree(node->left, val);

	else
		return searchTree(node->right, val);
}

bool isEmpty(Tree root)
{
	return(root != NULL);
}

size_t countNodes(Tree node)
{
	if (node == NULL) {
		return 0;
	}
	return 1 + countNodes((node)->left) + countNodes((node)->right);
}

size_t countDepth(Tree node)
{
	if (node == NULL)
		return 0;
	int l = countDepth(node->left);
	int r = countDepth(node->right);
	return((l > r) ? l + 1 : r + 1);

}

void printNode(itemtype_t item)
{
	cout << item << " ";
}

void printTree(Tree tree)
{
	traverse(tree, printNode, inOrder);
	cout << "\n";
}

itemtype_t minTree(Tree node)
{
	Tree n = node;
	while (n->left != NULL) {
		n = n->left;
	}
	return (n->item);
}

itemtype_t maxTree(Tree node)
{
	Tree n = node;
	while (n->right != NULL) {
		n = n->right;
	}
	return (n->item);
}




int main()
{
	Tree root = NULL;

	Tree myTree = insertNode(root, 4);
	
	insertNode(myTree, 11);
	insertNode(myTree, 6);
	insertNode(myTree, 15);
	insertNode(myTree, 3);
	insertNode(myTree, 8);
	insertNode(myTree, 13);
	insertNode(myTree, 17);
	insertNode(myTree, 1);
	insertNode(myTree, 5);
	insertNode(myTree, 12);
	insertNode(myTree, 14);
	insertNode(myTree, 19);
   
	printTree(myTree);
	cout << "nodes = " << countNodes(myTree) << "\n";
	cout << "depth = " << countDepth(myTree) << "\n";

	cout << "min is: " << minTree(myTree) << "\n";
	cout << "max is: " << maxTree(myTree) << "\n";
	//levelOrder(myTree, printNode);

	cout << "found 19 ? " << !(bool)searchTree(myTree, 19) << "\n";
	cout << "found  909 ? " << !(bool)searchTree(myTree, 909)<<"\n";






	return 0;
}


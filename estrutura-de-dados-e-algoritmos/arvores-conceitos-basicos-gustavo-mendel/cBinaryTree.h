#pragma once

#include <vector>

class cBinaryTree {

private:
	cNode *root;

	cNode* recursiveBuildTree(int nNodes);

public:

	cBinaryTree();
	cBinaryTree(int nNodes);
	cBinaryTree(const cBinaryTree& t);

	cNode* 	getRoot();
	void 	setRoot(cNode* r);

	void 	buildCompleteTree(int nNodes);

	bool	insertNode(int d);
	bool 	removeNode(int d);
	bool 	searchValue(int d);
	cNode* 	searchNode(int d);

	void 	preOrderTraversal(cNode* r);
	void 	inOrderTraversal(cNode* r);
	void 	postOrderTraversal(cNode* r);	
};

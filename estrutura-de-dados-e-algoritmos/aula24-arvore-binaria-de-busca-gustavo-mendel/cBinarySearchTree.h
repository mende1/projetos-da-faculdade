#pragma once

#include <vector>

class cBinarySearchTree {

private:
	cNode *root;

	void 	preOrderRecTraversal(cNode* r);
	void 	inOrderRecTraversal(cNode* r);
	void 	postOrderRecTraversal(cNode* r);	

	bool	insertNodeRec(cNode** r, int d);
	bool 	removeNodeRec(cNode** r, int d);
	bool 	searchValueRec(cNode* r, int d);
	cNode* 	searchNodeRec(cNode* r, int d);

public:

	cBinarySearchTree();
	cBinarySearchTree(std::vector<int> v);
	cBinarySearchTree(const cBinarySearchTree& t);

	cNode* 	getRoot();
	void 	setRoot(cNode* r);

	bool	insertNode(int d);
	bool 	removeNode(int d);
	bool 	searchValue(int d);
	cNode* 	searchNode(int d);

	void 	preOrderTraversal();
	void 	inOrderTraversal();
	void 	postOrderTraversal();	
};

#include <iostream>

#include "cNode.h"
#include "cBinaryTree.h"


// ***********************************************
// ******                                   ******
// ***********************************************
cBinaryTree::cBinaryTree() {

	root = NULL;

}

// ***********************************************
// ******                                   ******
// ***********************************************
cBinaryTree::cBinaryTree(int nNodes) {

	root = recursiveBuildTree(nNodes);

}

// ***********************************************
// ******                                   ******
// ***********************************************
void cBinaryTree::setRoot(cNode* r) {

	root = r;

}

// ***********************************************
// ******                                   ******
// ***********************************************
cNode* cBinaryTree::getRoot() {

	return root;

}

// ***********************************************
// ******                                   ******
// ***********************************************
cBinaryTree::cBinaryTree(const cBinaryTree& t) {


}

// ***********************************************
// ******                                   ******
// ***********************************************
cNode* cBinaryTree::recursiveBuildTree( int n ) {

int ne, nd;

static int k = 0;

	if (n == 0)
		return NULL;

	cNode *novoNo = new cNode(k++);

	if (novoNo) {
		ne = n / 2;
		nd = n - ne -1;

		novoNo->setLeftChild(recursiveBuildTree(ne));
		novoNo->setRightChild(recursiveBuildTree(nd));
		}

	return novoNo;	
}

// ***********************************************
// ******                                   ******
// ***********************************************

void cBinaryTree::preOrderTraversal(cNode* r) {

	if (r != NULL) {
		std::cout << r->getData() << std::endl;
		preOrderTraversal(r->getLeftChild());
		preOrderTraversal(r->getRightChild());
		}
	else 
		std::cout << "."<< std::endl;	

}

// ***********************************************
// ******                                   ******
// ***********************************************

void cBinaryTree::inOrderTraversal(cNode* r) {

	if (r != NULL) {
		inOrderTraversal(r->getLeftChild());
		std::cout << r->getData() << std::endl;
		inOrderTraversal(r->getRightChild());
		}
	else 
		std::cout << "."<< std::endl;	

}

// ***********************************************
// ******                                   ******
// ***********************************************
void cBinaryTree::postOrderTraversal(cNode* r) {

	if (r != NULL) {
		postOrderTraversal(r->getLeftChild());
		postOrderTraversal(r->getRightChild());
		std::cout << r->getData() << std::endl;
		}
	else 
		std::cout << "."<< std::endl;	
}

// ***********************************************
// ******                                   ******
// ***********************************************	
bool cBinaryTree::insertNode(int d) {

	return false;
}

// ***********************************************
// ******                                   ******
// ***********************************************	
bool cBinaryTree::removeNode(int d) {

	return false;
}

// ***********************************************
// ******                                   ******
// ***********************************************	
bool cBinaryTree::searchValue(int d) {

	return false;
}

// ***********************************************
// ******                                   ******
// ***********************************************	
cNode* cBinaryTree::searchNode(int d) {

	return NULL;

}

#include <iostream>

#include "cNode.h"
#include "cBinarySearchTree.h"


// ***********************************************
// ******                                   ******
// ***********************************************
cBinarySearchTree::cBinarySearchTree() {

	root = NULL;

}

// ***********************************************
// ******                                   ******
// ***********************************************
cBinarySearchTree::cBinarySearchTree(std::vector<int> v) {

	root = NULL;

	for (unsigned int i = 0 ; i < v.size() ; i++)
		insertNodeRec(&root, v[i]);

}

// ***********************************************
// ******                                   ******
// ***********************************************
cBinarySearchTree::cBinarySearchTree(const cBinarySearchTree& t) {


}

// ***********************************************
// ******                                   ******
// ***********************************************
void cBinarySearchTree::setRoot(cNode* r) {

	root = r;

}

// ***********************************************
// ******                                   ******
// ***********************************************
cNode* cBinarySearchTree::getRoot() {

	return root;

}

// ***********************************************
// ******                                   ******
// ***********************************************

void cBinarySearchTree::preOrderTraversal() {

	preOrderRecTraversal(root);

}

// ***********************************************
// ******                                   ******
// ***********************************************

void cBinarySearchTree::preOrderRecTraversal(cNode* r) {

	if (r != NULL) {
		std::cout << r->getData() << std::endl;
		preOrderRecTraversal(r->getLeftChild());
		preOrderRecTraversal(r->getRightChild());
		}
	else 
		std::cout << "."<< std::endl;	
}

// ***********************************************
// ******                                   ******
// ***********************************************

void cBinarySearchTree::inOrderTraversal() {

	inOrderRecTraversal(root);

}

// ***********************************************
// ******                                   ******
// ***********************************************

void cBinarySearchTree::inOrderRecTraversal(cNode* r) {

	if (r != NULL) {
		inOrderRecTraversal(r->getLeftChild());
		std::cout << r->getData() << std::endl;
		inOrderRecTraversal(r->getRightChild());
		}
	else 
		std::cout << "."<< std::endl;	
}

// ***********************************************
// ******                                   ******
// ***********************************************
void cBinarySearchTree::postOrderTraversal() {

	postOrderRecTraversal(root);
}

// ***********************************************
// ******                                   ******
// ***********************************************

void cBinarySearchTree::postOrderRecTraversal(cNode* r) {

	if (r != NULL) {
		postOrderRecTraversal(r->getLeftChild());
		postOrderRecTraversal(r->getRightChild());
		std::cout << r->getData() << std::endl;
		}
	else 
		std::cout << "."<< std::endl;	
}

// ***********************************************
// ******                                   ******
// ***********************************************	
bool cBinarySearchTree::insertNode(int d) {

	return insertNodeRec(&root, d);

}

// ***********************************************
// ******                                   ******
// ***********************************************	
bool cBinarySearchTree::insertNodeRec(cNode** r, int d) {

	std::cout << "insertNodeRec - " << std::endl;

	if ( (*r) == NULL ) {
		cNode *novoNo = new cNode(d);
		(*r) = novoNo;
		std::cout << (*r) << std::endl;
		return true;
		}
		
	if ( (*r)->getData() > d ) {
		std::cout << "L -> " << (*r)->getLeftChild() << std::endl;
		return insertNodeRec((*r)->getRefLeftChild(), d);
		}
	else {
		std::cout << "R -> " << (*r)->getLeftChild() << std::endl;
		return insertNodeRec((*r)->getRefRightChild(), d);
		}
}

// ***********************************************
// ******                                   ******
// ***********************************************	
bool cBinarySearchTree::removeNode(int d) {

	return removeNodeRec(&root, d);
}

// ***********************************************
// ******                                   ******
// ***********************************************	
bool cBinarySearchTree::removeNodeRec(cNode** r, int d) {

	return false;
}

// ***********************************************
// ******                                   ******
// ***********************************************	
bool cBinarySearchTree::searchValue(int d) {

	return searchValueRec(root, d);
}

// ***********************************************
// ******                                   ******
// ***********************************************	
bool cBinarySearchTree::searchValueRec(cNode* r, int d) {

	if (r == NULL)
		return false;

	if (r->getData() == d) 
		return true;

	if (d < r->getData())		
		return searchValueRec(r->getLeftChild(), d);
	else
		return searchValueRec(r->getRightChild(), d);
}

// ***********************************************
// ******                                   ******
// ***********************************************	
cNode* cBinarySearchTree::searchNode(int d) {

	return searchNodeRec(root, d);

}

// ***********************************************
// ******                                   ******
// ***********************************************	
cNode* cBinarySearchTree::searchNodeRec(cNode* r, int d) {

	if (r == NULL)
		return NULL;

	if (r->getData() == d) 
		return r;

	if (d < r->getData())		
		return searchNodeRec(r->getLeftChild(), d);
	else
		return searchNodeRec(r->getRightChild(), d);
}


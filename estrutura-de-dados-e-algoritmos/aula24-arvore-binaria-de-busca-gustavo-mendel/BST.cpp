#include <iostream>

#include "cNode.h"
#include "cBinarySearchTree.h"
  
// ***********************************************
// ***********************************************
// ***********************************************

int main(int argv, char** argc) {
	
std::vector<int> v = { 70, 40, 1, 90, 25, 34, 12, 100, 76, 23 };

  cBinarySearchTree t(v);
		
  printf("\n====== POS ======\n");
  t.postOrderTraversal();
  printf("\n=================\n\n\n");

  printf("\n====== IN ======\n");
  t.inOrderTraversal();
  printf("\n=================\n\n\n");

  printf("\n====== PRE ======\n");
  t.preOrderTraversal();
  printf("\n=================\n\n\n");
    
}

    


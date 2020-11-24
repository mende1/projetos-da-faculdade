#include <iostream>
#include <vector>
//#include <cstdlib>

#include "sortAlgs.h"

#define MAX 20

using namespace std;

// ********************************************************************
// ***
// ********************************************************************

void initArray(vector<int>& v, unsigned int N) {

    srand ( time(NULL) );
    for (unsigned int i=0; i < v.size(); i++) 
        v.at(i) = rand() % (N*10);        
}

// ********************************************************************
// ***
// ********************************************************************

void printArray(vector<int> v) {

	cout << "-----------------------------------------------" << endl;
    cout << "conteudo de v: " << endl << "=============" << endl;
    for (vector<int>::iterator it = v.begin() ; it != v.end(); ++it)
       cout << ' ' << *it << endl;
	cout << "-----------------------------------------------" << endl;
}

// ********************************************************************
// ********************************************************************
// ********************************************************************
// ********************************************************************
int main (int argc, char * argv[]) {

	unsigned int maxElem;

	algOrd::algOrdenacao sortAlg;

	if (argc > 1)
		maxElem = atoi(argv[1]);
	else
		maxElem = MAX;

	if (argc > 2)
		sortAlg = (algOrd::algOrdenacao) atoi(argv[2]);
	else
		sortAlg = algOrd::SELECTION_SORT;

	vector<int> v(maxElem);

	initArray(v, maxElem);

	printArray(v);    	

	switch (sortAlg) {
		case algOrd::SELECTION_SORT : 	cout << "Ordenando por Selecao" << endl;
										algOrd::selectionSort(v);
										break;

		case algOrd::INSERT_SORT 	: 	cout << "Ordenando por Insercao" << endl;
										algOrd::insertSort(v);
										break;

		case algOrd::BUBBLE_SORT 	: 	cout << "Ordenando por BubbleSort" << endl;
										algOrd::bubbleSort(v);
										break;

		case algOrd::MERGE_SORT 	: 	cout << "Ordenando por MergeSort" << endl;
										algOrd::mergeSort(v, 0, v.size()-1);
										break;

		case algOrd::QUICK_SORT 	: 	cout << "Ordenando por QuickSort" << endl;
										algOrd::quickSort(v, 0, v.size()-1);
										break;
		}

	printArray(v);
    	
 	return 0;        
}
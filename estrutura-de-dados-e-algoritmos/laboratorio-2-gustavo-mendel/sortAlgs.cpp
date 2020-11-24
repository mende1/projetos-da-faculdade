#include <vector>
#include <iostream>

#include "sortAlgs.h"

using namespace std;


/// ***********************************************************************
/// **  Ordenacao por Selecao - SelectionSort
/// ***********************************************************************

void algOrd::selectionSort (vector<int>& v) {
	
int i, j,
	n = v.size();
	
	for (i = 0 ; i < n-1 ; i++) {
		
		int min = i;
		
		for (j = i+1; j < n; j++) 
			if (v[j] < v[min]) 
				min = j;
			
		int aux = v[min];
		v[min] 	= v[i];
		v[i] 	= aux;
		}
}

/// ***********************************************************************
/// **  Ordenacao por Insercao - InsertSort
/// ***********************************************************************

void algOrd::insertSort (vector<int>& v) {

int i,
	n = v.size();
	
	for (i = 1 ; i < n ; i++) {
		
		int k = v[i];
		int j = i - 1;
		
		while ( (j >= 0) && (k < v[j]) ) {
			v[j+1] = v[j];
			j--;
			}
		v[j+1] = k;			
		}
}

/// ***********************************************************************
/// **  Ordenacao pelo Metodo da Bolha - BubbleSort
// ***********************************************************************

void algOrd::bubbleSort (vector<int>& v) { 
	
int i=0, j;
int n = v.size()-1;
bool troca = true;

	while ( (troca) && (i < n) ) { 
		troca = false;
		for (j = 0; j < (n - i); j++) 		
			if (v[j] > v[j+1]) {
				int aux = v[j];
				v[j] 	= v[j+1];
				v[j+1] 	= aux;
				troca 	= true;
				}
		i++;
		}	
}

/// ***********************************************************************
/// **  Ordenacao por Mistura - MergeSort
/// ***********************************************************************

void algOrd::mergeSort(vector<int>& v, int e, int d) {

	cout << "+==================================+" << endl; 
	cout << "+=          Em construcao         =+" << endl; 
	cout << "+==================================+" << endl; 

} 

/// ***********************************************************************
/// **  Algoritmo de Mistura - Merge
/// ***********************************************************************

void algOrd::merge (vector<int>& v, int e, int m, int d) {
	
} 

/// ***********************************************************************
/// **  Algoritmo QuickSort
/// ***********************************************************************

void algOrd::quickSort(vector<int>& v, int e, int d) {

	cout << "+==================================+" << endl; 
	cout << "+=          Em construcao         =+" << endl; 
	cout << "+==================================+" << endl; 
	
} 

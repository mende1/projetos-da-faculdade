#ifndef _METODOS_DE_ORDENACAO_
#define _METODOS_DE_ORDENACAO_

//#pragma once

namespace algOrd {

	typedef enum { 	SELECTION_SORT,
					INSERT_SORT,  
					BUBBLE_SORT,
					MERGE_SORT,
					QUICK_SORT } algOrdenacao;

	// ********************************************************************
	// *** Ordenação por Seleção 
	// ********************************************************************
	void selectionSort (std::vector<int>& v);

	// ********************************************************************
	// *** Ordenação por inserção 
	// ********************************************************************
	void insertSort (std::vector<int>& v);

	// ********************************************************************
	// *** Ordenação pelo Método da Bolha 
	// ********************************************************************
	void bubbleSort (std::vector<int>& v);

	// ********************************************************************
	// *** Ordenação pelo Método de Mistura (MergeSort) 
	// ********************************************************************
	void mergeSort (std::vector<int>& v, int e, int d);

	// ********************************************************************
	// *** Promove a mistura (merge) dos intervalos [e..m] e [m+1..d] do vetor v
	// ********************************************************************
	void merge(std::vector<int>& v, int e, int m, int d);

	// ********************************************************************
	// *** Ordenação pelo Método QuickSort 
	// ********************************************************************
	void quickSort(std::vector<int>& v, int e, int d);

}

#endif /* _METODOS_DE_ORDENACAO_ */

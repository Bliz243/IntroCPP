//============================================================================
// Name        : ex01_main.cpp
// Author      : 
// Version     :
// Copyright   :
// Description : Exercise 1 - Graphics Editor
//============================================================================

#include <iostream>
#include <string>
#include "ex01-library.h"

using namespace std;

int testMain(){

	// I am building a matrix representing a picture
	unsigned int n = 4;
	unsigned int m = 4;
	int **A = createMatrix(n,m);

	// Setting all values to 0
	initMatrix(A,n,m);
	// Setting some values in the matrix
	for(int i=0;i<n-1;i++){
		for(int j=0;j<m;j++){
			A[i][j]=i*n+j;
		}
	}
	A[1][0]=126;
	A[1][1]=127;
	A[1][2]=128;
	printMatrix(A,n,m,"main matrix");
	cout << endl;

	int **B = duplicateMatrix(A,n,m);
	printMatrix(B,n,m,"copy");

	//I change B, and I print B and A
	for(int j=0;j<m;j++){
		B[0][j]=B[0][j]+3;
	}

	printMatrix(B,n,m,"modified copy");
	printMatrix(A,n,m,"main matrix");

	//I deallocate B
	deallocateMatrix(B,n);

	int ** C = makeBitonal(A,n,m,127);
	printMatrix(C,n,m,"bi-tonal copy");

	deallocateMatrix(A,n);
	deallocateMatrix(C,n);

	return 0;
}

int testa(){
	unsigned int n = 3;
	unsigned int m = 2;
	int ** A = createMatrix(n,m);

	//Hidden code for matrix initialization
	// %%%CJ_HIDE_START%%%
	for(unsigned int i = 0; i < n; i++){
		for(unsigned int j = 0; j < m; j++){
			A[i][j] = 0;
		}
	}
	// %%%CJ_HIDE_END%%%

	printMatrix(A,n,m,"matrix of test-a");

	return 0;
}

int testb(){
	unsigned int n = 3;
	unsigned int m = 2;

	int ** A;
	//Hidden code for matrix creation and initialization
	// %%%CJ_HIDE_START%%%
	A = new int *[n];
	for(unsigned int i = 0; i<n; i++){
		A[i] = new int[m];
	}

	for(unsigned int i = 0; i < n; i++){
		for(unsigned int j = 0; j < m; j++){
			A[i][j] = 0;
		}
	}
	// %%%CJ_HIDE_END%%%

	int ** B = duplicateMatrix(A,n,m);
	A[0][0] = 2;
	A[0][1] = 2;
	A[1][0] = 2;

	printMatrix(A,n,m,"A matrix of test-b");
	printMatrix(B,n,m,"B matrix of test-b");

	return 0;
}

int testc(){
	unsigned int n = 3;
	unsigned int m = 2;

	int ** A;
	//Hidden code for matrix creation
	// %%%CJ_HIDE_START%%%
	A = new int *[n];
	for(unsigned int i = 0; i<n; i++){
		A[i] = new int[m];
	}
	// %%%CJ_HIDE_END%%%

	initMatrix(A,n,m);

	printMatrix(A,n,m,"A matrix of test-c");

	for(unsigned int i = 0; i < n; i++){
		for(unsigned int j = 0; j < m; j++){
			A[i][j] = A[i][j]+1;
		}
	}

	printMatrix(A,n,m,"A matrix of test-c");

	return 0;
}

int testd(){
	unsigned int n = 100000;
	unsigned int m = 5000;

	for(int i=0;i<50;i++){
		cout << "Iteration " << i <<"\n";
		int ** A = new int *[n];
		for(unsigned int i = 0; i<n; i++){
			A[i] = new int[m];
		}
		deallocateMatrix(A,n);
	}

	cout << "Test d completed\n";
	return 0;
}

int teste(){
	unsigned int n = 4;
	unsigned int m = 4;

	int ** A;
	//Hidden code for matrix creation
	// %%%CJ_HIDE_START%%%
	A = new int *[n];
	for(unsigned int i = 0; i<n; i++){
		A[i] = new int[m];
	}

	//Initialising the matrix
	for(unsigned int i = 0; i < n; i++){
		for(unsigned int j = 0; j < m; j++){
			A[i][j] = 0;
		}
	}
	// %%%CJ_HIDE_END%%%

	// Setting some values in the matrix
	for(int i=0;i<n-1;i++){
		for(int j=0;j<m;j++){
			A[i][j]=i*n+j;
		}
	}
	A[1][0]=126;
	A[1][1]=127;
	A[1][2]=128;
	printMatrix(A,n,m,"main matrix");
	cout << endl;

	int ** C = makeBitonal(A,n,m,127);
	printMatrix(C,n,m,"bi-tonal copy");


	return 0;
}

int main(void){
	//return testMain();
	//return testa();
	return testb();
	//return testc();
	//return testd();
	//return teste();

	//return 0;

}

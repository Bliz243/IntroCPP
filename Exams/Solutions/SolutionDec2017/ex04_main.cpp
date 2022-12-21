//============================================================================
// Name        : ex04.cpp
// Author      : 
// Version     :
// Copyright   :
// Description :
//============================================================================

#include <iostream>
#include "ex04-library.h"

using namespace std;

int testMain() {
	mydeque<int> deque;

	deque.push_front(2);
	deque.push_front(1);
	deque.push_back(3);

	deque.print();

	cout <<"\n";
	cout << "The first element is: ";
	deque.print_front();
	cout << "The last element is: ";
	deque.print_back();

	do{
		cout <<"\n";
		cout << "pop_front(): ";
		cout <<deque.pop_front() <<"\n";
		deque.print();
	}while(deque.getSize()>0);

	cout <<"\n";
	cout << "pop_front(): ";
	cout << deque.pop_front() <<"\n";

	return 0;
}

int testa(){
	mydeque<int> deque;
	deque.push_when_empty(1);
	return 0;
}

int testb(){
	mydeque<int> deque;
	deque.push_back(1);
	deque.push_back(2);
	deque.push_back(3);
	deque.print();
	return 0;
}

int testc(){
	mydeque<int> deque;
	deque.push_front(1);
	deque.push_front(2);
	deque.push_front(3);
	deque.print();
	return 0;
}

int testd(){
	mydeque<int> deque;

	deque.print_back();

	deque.push_when_empty(1);
	deque.print_back();

	deque.push_back(2);
	deque.print_back();

	return 0;
}

int teste(){
	mydeque<int> deque;

	bool res=false;

	res = deque.pop_front();
	if(res){
		cout << "pop_front on empty deque succeeded\n";
	}
	else{
		cout << "pop_front on empty deque failed\n";
	}
	deque.push_when_empty(1);

	res = deque.pop_front();
	if(res){
		cout << "pop_front on non-empty succeeded\n";
	}
	else{
		cout << "pop_front on non-empty failed\n";
	}
	deque.print();

	return 0;
}

int main(){
	//return testMain();
	//return testa();
	//return testb();
	//return testc();
	//return testd();
	return teste();
}

//============================================================================
// Name        : ex03.cpp
// Author      : 
// Version     :
// Copyright   :
// Description : Exercise 3 - Currency converter
//============================================================================

#include <iostream>
#include "ex03-library.h"

int testMain() {
	CurrencyConverter cc;
	cout << "\naddCurrency(\"EUR\",7.44416);\n";
	cc.addCurrency("EUR",7.44416);
	cc.print();

	cout << "\naddCurrency(\"EUR\",17.44416);\n";
	cc.addCurrency("EUR",17.44416);
	cc.print();

	cout << "\naddCurrency(\"USD\",16.31708);\n";
	cc.addCurrency("USD",16.31708);
	cc.print();

	cout << "\nupdateExchangeRate(\"USD\",6.31708);\n";
	cc.updateExchangeRate("USD",6.31708);
	cc.print();

	cout <<"\n\n";

	double amountDKK=100;
	double amountEUR=cc.convertFromDKK(amountDKK,"EUR");
	cout << amountDKK <<" DKK = " << amountEUR << " EUR\n";

	amountDKK = cc.convertToDKK(amountEUR,"EUR");
	cout << amountEUR <<" EUR = " << amountDKK << " DKK\n";

	return 0;
}

int testa(){
	CurrencyConverter cc;
	cc.print();

	return 0;
}

int testb(){
	CurrencyConverter cc;

	bool res = cc.addCurrency("USD",-1);
	if(res){
		cout << "Operation cc.addCurrency(\"USD\",-1) succeeded\n";
	}
	else{
		cout << "Operation cc.addCurrency(\"USD\",-1) failed\n";
	}
	cc.print();
	cout<<"\n";

	res = cc.addCurrency("USD",6.31708);
	if(res){
		cout << "Operation cc.addCurrency(\"USD\",6.31708) succeeded\n";
	}
	else{
		cout << "Operation cc.addCurrency(\"USD\",6.31708) failed\n";
	}
	cc.print();
	cout<<"\n";

	res = cc.addCurrency("USD",16.31708);
	if(res){
		cout << "Operation cc.addCurrency(\"USD\",16.31708) succeeded\n";
	}
	else{
		cout << "Operation cc.addCurrency(\"USD\",16.31708) failed\n";
	}
	cc.print();
	cout<<"\n";

	return 0;
}

int testc(){
	CurrencyConverter cc;

	bool res = cc.updateExchangeRate("DKK",2.0);
	if(res){
		cout << "Operation cc.updateExchangeRate(\"DKK\",2.0) succeeded\n";
	}
	else{
		cout << "Operation cc.updateExchangeRate(\"DKK\",2.0) failed\n";
	}
	cc.print();
	cout<<"\n";

	res = cc.updateExchangeRate("USD",2.0);
	if(res){
		cout << "Operation cc.updateExchangeRate(\"USD\",2.0) succeeded\n";
	}
	else{
		cout << "Operation cc.updateExchangeRate(\"USD\",2.0) failed\n";
	}
	cc.print();
	cout<<"\n";

	res = cc.addCurrency("USD",16.31708);
	if(res){
		cout << "Operation cc.addCurrency(\"USD\",16.31708) succeeded\n";
	}
	else{
		cout << "Operation cc.addCurrency(\"USD\",16.31708) failed\n";
	}
	cc.print();
	cout<<"\n";

	res = cc.updateExchangeRate("USD",6.31708);
	if(res){
		cout << "Operation cc.updateExchangeRate(\"USD\",6.31708) succeeded\n";
	}
	else{
		cout << "Operation cc.updateExchangeRate(\"USD\",6.31708) failed\n";
	}
	cc.print();
	cout<<"\n";

	return 0;
}

int testd(){
	CurrencyConverter cc;
	cc.addCurrency("EUR",7.44416);

	double amountEUR=100;
	double amountDKK = cc.convertToDKK(amountEUR,"EUR");
	cout << amountEUR <<" EUR = " << amountDKK << " DKK\n";

	return 0;
}

int teste(){

	CurrencyConverter cc;
	cc.addCurrency("USD",6.31708);

	double amountDKK=100;
	double amountUSD=cc.convertFromDKK(amountDKK,"USD");
	cout << amountDKK <<" DKK = " << amountUSD << " USD\n";

	return 0;
}

int main(){
	//return testMain();
	//return testa();
	//return testb();
	//return testc();
	return testd();
	//return teste();
}

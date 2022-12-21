#include <iostream>
#include "ex03-library.h"

//Do not modify
TemperatureScalesConverter::TemperatureScalesConverter() {
	//By default we add a measurement of 0 C which corresponds to 32 F.
	CTemperatures.push_back(0);
	FTemperatures.push_back(32);
}

//Exercise 3 (a) Check and correct this method
void TemperatureScalesConverter::print(){
	cout << CTemperatures.size() <<" Celsius measurements:";
	for(int i = 0; i <= CTemperatures.size()-1; i++){
		cout<< ' ' << CTemperatures[i];
	}
	cout << endl;

	cout << FTemperatures.size() <<" Fahrenheit measurements:";
	for(int i = 0; i <= FTemperatures.size()-1; i++){
		cout<< ' ' << FTemperatures[i];
	}
	cout << endl;
}

//Exercise 3 (b) Implement this method
double TemperatureScalesConverter::convertToF(double CTemperature){
	double F = CTemperature * 1.8 + 32;
	return F;
}

//Exercise 3 (c) Implement this method
double TemperatureScalesConverter::convertToC(double FTemperature){
	double C = (FTemperature - 32) * 0.56;
	return C;
}

//Exercise 3 (d) Implement this method
bool TemperatureScalesConverter::addMeasurement(string scale, double temperature){
	if(scale == "C"){
		CTemperatures.push_back(temperature);
		FTemperatures.push_back(convertToF(temperature));
		return true;
	}
	else if(scale == "F"){
		CTemperatures.push_back(convertToC(temperature));
		FTemperatures.push_back(temperature);
		return true;
	}
	else{
		return false;
	}
}
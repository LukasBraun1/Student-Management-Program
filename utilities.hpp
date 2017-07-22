/*
 * utilities.hpp
 *
 *  Created on: Nov 12, 2015
 *      Author: student
 */

#ifndef UTILITIES_HPP_
#define UTILITIES_HPP_
const int TOTALROWS = 100;
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <cctype>
#include <fstream>
#include "student.hpp"
namespace utilities {
	void clearcin(void);
	char printMenu(void);
}
//Vector sort
void bubbleSortArray(std::vector<student> &aVector, int size) {
	bool swap;
	double temp;
	do {
		swap = false;
		for (int count = 0; count < (size - 1); count++) {
			if (aVector[count].stuID > aVector[count+1].stuID) {
				temp = aVector[count].stuID;
				aVector[count].stuID = aVector[count+1].stuID;
				aVector[count+1].stuID = temp;
				swap = true;
			}
		}
	} while (swap);
	return;
}
// 2D Array sort
void bubbleSortArray(double doubleArray[][TOTALROWS], int selectedRow, int size) {
	bool swap;
	double temp;
	do {
		swap = false;
		for (int count = 0; count < (size - 1); count++) {
			if (doubleArray[selectedRow][count]
					> doubleArray[selectedRow][count + 1]) {
				temp = doubleArray[selectedRow][count];
				doubleArray[selectedRow][count] = doubleArray[selectedRow][count + 1];
				doubleArray[selectedRow][count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
	return;
}
std::string enterString(unsigned int min, unsigned int max) {
	std::string astring;
	getline(std::cin, astring);
	while (true) {
		if (astring.length() < min || astring.length() > max) {
			std::cout
					<< "error, string must be greater than " << min << " and less than " << max
					<< std::endl;
			//cout << "Enter student name# " << i << endl;
			getline(std::cin, astring);
		} else {
			break;
		}
	}
	return astring;
}
/*char enterCharArray(char* theChar, unsigned int min, unsigned int size) {
	char astring[size];
	char ch = 'a';
	std::cin.getline(astring, size);
	while (true) {
		if (strlen(astring) < min ||strlen(astring) > size) {
			std::cout
					<< "error, string must be greater than " << min << " and less than " << size
					<< std::endl;
			//cout << "Enter student name# " << i << endl;
			std::cin.getline(astring, size);
		} else {
			break;
		}
	}
	return ch;
}*/
//sort grades descending in select Sort ---- 2D array ------
void selectionSort(double doubleArray[][TOTALROWS], int selectedRow, int size) {
	int startScan, minIndex;
	double minValue;

	for (startScan = 0; startScan < (size - 1); startScan++) {
		minIndex = startScan;
		minValue = doubleArray[selectedRow][startScan];
		for (int index = startScan + 1; index < size; index++) {
			if (doubleArray[selectedRow][index] > minValue) {
				minValue = doubleArray[selectedRow][index];
				minIndex = index;
			}
		}
		doubleArray[selectedRow][minIndex] =
				doubleArray[selectedRow][startScan];
		doubleArray[selectedRow][startScan] = minValue;
	}
	return;
}
//Vector Sort
void selectionSort(std::vector<student>& aStudent, int size) {
	int startScan, minIndex;
	student minStuValue;

	for (startScan = 0; startScan < (size - 1); startScan++) {
		minIndex = startScan;
		minStuValue = aStudent[startScan];
		for (int index = startScan + 1; index < size; index++) {
			if (aStudent[index].stuID > minStuValue.stuID) {
				minStuValue = aStudent[index];
				minIndex = index;
			}
		}
		aStudent[minIndex] =
				aStudent[startScan];
		aStudent[startScan] = minStuValue;
	}
	return;
}
double enterDouble(double userDouble, int min, int max,double theArray[][TOTALROWS], int rowNum, int& grdTotal) {
	bool Exit = false;
	for (int i = 0; i < 99; i++) {
			if(Exit){
				break;
			}
			std::cout << "Enter a new Grade, -999 to quit.";
			std::cin >> userDouble;
			utilities::clearcin();
			if (userDouble == -999) {
				break;
			}
			while (true) {
				if (userDouble <= max && userDouble >= min) {
					theArray[rowNum][i] = userDouble;
					grdTotal++;
					break;
				}
				else {
					std::cout << "Grade value not valid, please enter a number from (0-100)" << std::endl;
					std::cout << "Enter a new Grade, -999 to quit.";
					std::cin >> userDouble;
					utilities::clearcin();
					if(userDouble == -999){
						Exit = true;
						break;
					}
				}
			}
		}

	return userDouble;
}
double inputDouble(double min, double max){
	double inputDoubleVal;
	std::cin >> inputDoubleVal;
	while(true){
		if(inputDoubleVal < min || inputDoubleVal > max){
			std::cout << "Invalid double, must be between " << min << " and " << max << std::endl;
			std::cin >> inputDoubleVal;
		}
		else{
			break;
		}
	}
	return inputDoubleVal;
}

char enterChar(void){
	char theChar = '\0';
	std::cin >> theChar;
	while(true){
		if(theChar == 'Y' || theChar == 'y' || theChar == 'N'|| theChar == 'n'){
			break;
		}
		else {
			std::cout << "Invalid character, try again";
			std::cin >> theChar;
		}
	}
	return theChar;
}
void printReport(int amount, double arrayName[][TOTALROWS], int rowNum,
		double average) {
	for (int i = 0; i < (amount); i++) {
		std::cout << "Grade number " << i << " is " << arrayName[rowNum][i] << std::endl;
	}
	for (int i = 0; i < (amount); i++) {
		average += arrayName[rowNum][i];
	}
	average /= amount;
	std::cout << "The average grade is: " << average << std::endl;
	return;
}
int enterInt(int min, int max){
	int theInt = 0;
	while(true){
		std::cin >> theInt;
		utilities::clearcin();
		if(theInt < min || theInt > max){
			std::cout << "error, int must be between " << min << " and " << max << std::endl;
		}
		else{
			break;
		}
	}
	return theInt;
}

void utilities::clearcin(){
	std::cin.clear();
	std::cin.ignore(32768, '\n');
}
char utilities::printMenu(void){
	char userResponse = '\0';
	while(true){
		std::cout << "Welcome to my student management program";
		std::cout << "========================================";
		std::cout << "1. Enter a student\n";
		std::cout << "3. Print Student Report\n";
		std::cout << "4. Clear student data\n";
		std::cout << "9. Exit Program\n";
		std::cout << "Please select one: ";
		std::cin >> userResponse;
		clearcin();
		if(userResponse != '1' && userResponse != '3' && userResponse != '4' && userResponse != '9')
			std::cout << "Input Error, please try again";
		else
			break;
	}
	return userResponse;
}





#endif /* UTILITIES_HPP_ */

//*****************
//Project Name: Project8
//Project Description: This Program is good
//Project Author: Braun, Lukas
//Is this an extra credit Project:  No
//Date completed: 11/24/2015
//Operating system used: Linux
//IDE Used:  Eclipse
//*****************

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <cctype>
#include <fstream>
#include "utilities.hpp"
#include "student.hpp"
using namespace std;
using namespace utilities;
void writeFile (std::vector<student>&theStudents, fstream &aFile);
void readFile(vector<student> &theStudents, fstream &aFile, int);
bool openAFile(fstream &afile, string fileName);
int main() {
	struct student cstudent;
	struct student SI;
	string fileName;
	int intGrade = 0, stuNum = 0, totalGrades = 0, studentamt = 0, studentChoice = 0, studentsInFile = 0;
	degreeMajor majornum;
	college collegenum;
	double avgGrades = 0;
	string stuFullName, studentNameTest, unneccessary,
			stringmajor;
	char ltrGrade = '\0';
	double testScores[TOTALROWS][TOTALROWS];
	double userDoubleInput = 0;
	cout << "Welcome to my grade input program" << endl;
	cout << "=================================" << endl;
	char userChoice, yn;
	char ltrGrades[TOTALROWS];
	string studentID, tmpstr, studentName;
	string thename;
	fstream stuFile;
	std::vector<student> stuvector;
	/*char* fname = '\0';
	 char* lname = '\0';
	 char* major = '\0';*/
	do {
		cout << "Student Management System" << endl; // prints !!!Hello World!!!
		cout << "=========================" << endl;

		cout << "1. Enter Student Information" << endl;
		cout << "2. Print Student options" << endl;
		cout << "3. Print Student  Grades" << endl;
		cout << "4. Clear Student Data" << endl;
		cout << "5. Write Students" << endl;
		cout << "6. Read Studnents" << endl;
		cout << "7. Bubble Sort Ascending" << endl;
		cout << "8. Select Sort Descending" << endl;
		cout << "9. Exit Program" << endl;
		cout << "Please enter a menu option";
		cin >> userChoice;
		cin.clear();
		cin.ignore(32768, '\n');

		switch (userChoice) {
		case ('1'):
			//add a new vector to the student array
			cout << "Add a new student" << endl;
			studentamt++;
			cout << "Please  enter Student ID: ";
			stuvector.push_back(SI);
			totalGrades = 0;
			avgGrades = 0;
			stuvector[(studentamt - 1)].gpa = 0;
			ltrGrade = '\0';
			stuvector[(studentamt - 1)].stuID = enterInt(1, 9999);
			cout << "Please  enter Student's last name: ";
			stuvector[(studentamt - 1)].lname = enterString(1, 30);
			cout << "Please enter students first name";
			stuvector[(studentamt - 1)].fname = enterString(1, 24);
			//fname[sizeof(fname) - 1] = 0;
			//ENTER AGE
			cout << "Please  enter Student's age in years: ";
			stuvector[(studentamt - 1)].age = inputDouble(13, 99);
			clearcin();

			//cout << "Please  enter the major for the student: ";
			/*enterCharArray(major, 1, 4);
			 strncpy(lname, SI.major.c_str(), sizeof(major));*/
			majornum = entermajor();
			clearcin();
			stuvector[(studentamt - 1)].major = majortostring(majornum);
			collegenum = entercollege();
			clearcin();
			stuvector[(studentamt - 1)].college = collegetostring(collegenum);
			enterDouble(userDoubleInput, 0, TOTALROWS, testScores, 0,
					totalGrades);
			for (int i = 0; i < totalGrades; i++) {
				avgGrades += testScores[stuNum][i];
			}
			avgGrades /= totalGrades;
			stuvector[(studentamt - 1)].gpa = avgGrades;
			cout << "Your average grade is: " << avgGrades << endl;
			intGrade = avgGrades;
			switch (intGrade) {
			case 0 ... 59:
				ltrGrade = 'F';
				break;
			case 60 ... 69:
				ltrGrade = 'D';
				break;
			case 70 ... 79:
				ltrGrade = 'C';
				break;
			case 80 ... 89:
				ltrGrade = 'B';
				break;
			case 90 ... 100:
				ltrGrade = 'A';
				break;
			}
			ltrGrades[(studentamt - 1)] = ltrGrade;
			break;
		case('2'):
			cout << "You want to print the Grades" << endl;
			//Print Grade report header
			cout << setprecision(2) << fixed;
			cout << "Student Grade Report" << endl;
			cout << "=====================" << endl;
			cout << endl;
			cout << setw(10) << "    Stu-ID" << setw(19) << "Name" << setw(10)
					<< "Average" << setw(10) << "College" << setw(10) << "Major"
					<< setw(10) << "Letter" << endl;
			cout << setw(10) << "    ======" << setw(19) << "================"
					<< setw(10) << "=======" << setw(10) << "========"
					<< setw(10) << "========" << setw(10) << "========" << endl;
			//print grades & info
			cout << setw(10);
			for (int i = 0; i < studentamt; i++) {
				stuFullName = (stuvector[i].fname + ", " + stuvector[i].lname);
				cout << setprecision(2) << fixed;
				if (i == 0) {
					cout << stuvector[i].stuID << setw(19) << right
							<< stuFullName << right << setw(10)
							<< stuvector[i].gpa << right << setw(10)
							<< stuvector[i].college << setw(10)
							<< stuvector[i].major << right << setw(10)
							<< ltrGrades[i] << endl;
				} else {
					cout << setw(10) << stuvector[i].stuID << setw(19) << right
							<< stuFullName << right << setw(10)
							<< stuvector[i].gpa << right << setw(10)
							<< stuvector[i].college << setw(10)
							<< stuvector[i].major << right << setw(10)
							<< ltrGrades[i] << endl;
				}
			}

			break;
		case ('3'):
			cout << "You want to print the Grades" << endl;
			cout << "Which student would you like to print grades for?" << endl;
			for(int i = 0; i < studentamt; i++){
				stuFullName = (stuvector[i].fname + ", " + stuvector[i].lname);
				cout << i << ". " << stuFullName << endl;
			}
			cout << "Choose a position number: ";
			cin >> studentChoice;

			//Print Grade report header
			cout << setprecision(2) << fixed;
			cout << "Student Grade Report" << endl;
			cout << "=====================" << endl;
			cout << endl;
			cout << setw(10) << "    Stu-ID" << setw(19) << "Name" << setw(10)
					<< "Average" << setw(10) << "College" << setw(10) << "Major"
					<< setw(10) << "Letter" << endl;
			cout << setw(10) << "    ======" << setw(19) << "================"
					<< setw(10) << "=======" << setw(10) << "========"
					<< setw(10) << "========" << setw(10) << "========" << endl;
			//print grades & info
			cout << setw(10);
			for (int i = 0; i < studentamt; i++) {
				stuFullName = (stuvector[i].fname + ", " + stuvector[i].lname);
				cout << setprecision(2) << fixed;
				if (i == 0) {
					cout << stuvector[i].stuID << setw(19) << right
							<< stuFullName << right << setw(10)
							<< stuvector[i].gpa << right << setw(10)
							<< stuvector[i].college << setw(10)
							<< stuvector[i].major << right << setw(10)
							<< ltrGrades[i] << setw(10) << endl;
				} else {
					cout << setw(10) << stuvector[i].stuID << setw(19) << right
							<< stuFullName << right << setw(10)
							<< stuvector[i].gpa << right << setw(10)
							<< stuvector[i].college << setw(10)
							<< stuvector[i].major << right << setw(10)
							<< ltrGrades[i] << setw(10) << endl;
				}
			}
			break;
		case ('4'):
			cout << "You want to clear student data" << endl;
			cout << "Are you sure you want to clear student data? <Y>es <n>o" << endl;
			yn = enterChar();
			if (yn == 'Y' || yn == 'y') {
				stuvector.clear();
			} else {
			}
			break;
		case ('5'):
			cout << "Writing to students.bin\n";
			writeFile(stuvector, stuFile);
			stuFile.open("students.bin", ios::in | ios::out | ios::binary);
			if(stuFile.fail()){
				cout << "Error opening file\n";
		 		break;
			}//if
			else{
				//
				//This code will check to see how many students are in the file
				stuFile.seekg(0L, ios::end);
				studentsInFile = (stuFile.tellg()/sizeof(student));
				cout << "There are " << studentsInFile << " students in the file\n";
			}
			break;
		case ('6'):
			cout << "Reading File" << endl;
		    readFile(stuvector, stuFile, studentamt);
		    break;
		case ('7'):
			cout << "You want to Bubble Sort ascending" << endl;
			bubbleSortArray(stuvector, studentamt);
			break;
		case ('8'):
			cout << "You want to Select Sort descending" << endl;
			selectionSort(stuvector, studentamt);
			break;
		case ('9'):
			break;
		default:
			cout << "Invalid menu option entered. Please try again" << endl;
		}
	} while (userChoice != '9');

	cout << endl << "Program is Ending have a nice day" << endl;
	return 0;
}
void writeFile (std::vector<student>&theStudents, fstream &aFile){
    cstudent tempcstud;
    vector<cstudent> tempStuVect;
    for (long i=0; i<theStudents.size(); i++) {
        tempcstud.stuID = theStudents[i].stuID;
        strcpy(tempcstud.lname, theStudents[i].lname.c_str());
        strcpy(tempcstud.fname, theStudents[i].fname.c_str());
       // tempcstud.attendingCollege = theStudents[i].college;
      // strcpy(tempcstud.major, theStudents[i].major.c_str());
        tempcstud.gpa = theStudents[i].gpa;
        tempcstud.age = theStudents[i].age;
        tempcstud.grades[i] = theStudents[i].grades[i];
        tempcstud.totalGrades = theStudents[i].totalGrades;
        tempStuVect.push_back(tempcstud);
    }//for
	aFile.open("students.bin", ios::out | ios::binary);
    for(long i = 0; i < tempStuVect.size(); i++){
		aFile.write(reinterpret_cast<char *>(&tempStuVect[i]), sizeof(student));
    }
	aFile.close();
}
void readFile(vector<student> &theStudents, fstream &aFile, int amount) {
    cstudent tempStudent;
    int boatsInFile = 0;
    aFile.open("students.bin", ios::in | ios::binary);
    if(aFile.fail()){
    	cout << "file open failure" << endl;
    }
    while (true) {
        aFile.read(reinterpret_cast<char *> (&tempStudent), sizeof(tempStudent));
        if (aFile.eof()) {
        	cout << "you have reached the end of file" << endl;
        	break;
        }
        else {
        	aFile.clear();
    		aFile.seekg(0L, ios::end);
    		boatsInFile = (aFile.tellg()/sizeof(cstudent));
    		cout << "There are " << boatsInFile << " boats in the file\n";/*
            for (unsigned int ctr = 0; ctr < theStudents.size(); ctr++) {
                tempStudent.stuID = theStudents[ctr].stuID;
            //    tempStudent.fname = theStudents[ctr].fname;
            //    tempStudent.lname = theStudents[ctr].lname;
              //  tempStudent.attendingCollege = theStudents[ctr].attendingCollege;
           //  	  tempStudent.major = theStudents[ctr].major;
                tempStudent.gpa = theStudents[ctr].gpa;
                tempStudent.age = theStudents[ctr].age;
                tempStudent.grades[ctr] = theStudents[ctr].grades[ctr];
                tempStudent.totalGrades = theStudents[ctr].totalGrades;
            }*/
        }//else
    }//while
    aFile.close();
    return;
}//readboats fnc

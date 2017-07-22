/*
 * student.hpp
 *
 *  Created on: Nov 13, 2015
 *      Author: Owner
 */

#ifndef STUDENT_HPP_
#define STUDENT_HPP_
#include "utilities.hpp"
const int MAXROWS = 100;
enum college {
	LPC,
	SFO,
	BRK,
	SLU,
	WASHU,
	CSC
};
enum degreeMajor {
	CS,
	CIS,
	MTH,
	MUS,
	BUIS,
	VIT,
	PHY,
	ASTR,
	ENG
};
int enterStuInt(int min, int max){
	int theInt = 0;
	while(true){
		std::cin >> theInt;
		if(theInt < min || theInt > max){
			std::cout << "error, int must be between " << min << " and " << max << std::endl;
			std::cin >> theInt;
			std::cin.clear();
			std::cin.ignore(32768, '\n');
		}
		else{
			break;
		}
	}
	return theInt;
}
degreeMajor entermajor(){
	int userIntInput = 0;
	std::cout << "0. CS \n";
	std::cout << "1. CIS \n";
	std::cout << "2. MTH \n";
	std::cout << "3. MUS \n";
	std::cout << "4. BUIS\n";
	std::cout << "5. VIT \n";
	std::cout << "6. PHY \n";
	std::cout << "7. ASTR\n";
	std::cout << "8. ENG \n ";
	std::cout << "Please enter your major: ";
	userIntInput = enterStuInt(0,8);
	return static_cast<degreeMajor>(userIntInput);
}
college entercollege(){
	int userIntInput = 0;
	std::cout << "0. LPC  \n";
	std::cout << "1. SFO \n";
	std::cout << "2. BRK \n";
	std::cout << "3. SLU \n";
	std::cout << "4. WASHU \n";
	std::cout << "5. CSC \n";
	std::cout << "Please enter your college: ";
	userIntInput = enterStuInt(0,5);
	return static_cast<college>(userIntInput);
}
struct cstudent{
 int stuID;             //8 characters long
 char lname[24];        //30 characters long
 char fname[30];        //24 characters long
 college attendingCollege;
 degreeMajor major;
 double gpa;            //0.0 - 4.0
 double age;            //14 - 90
 double grades[MAXROWS];//Each 0 - 100
 int totalGrades;
};//student
std::string majortostring(degreeMajor aMajor){
		std::string returnString;
		if(aMajor == CS){
			returnString = "CS";
			return returnString;
		}
		if(aMajor == CIS){
			returnString = "CIS";
			return returnString;
		}
		if(aMajor == MTH){
			returnString = "MTH";
			return returnString;
		}
		if(aMajor == MUS){
			returnString = "MUS";
			return returnString;
		}
		if(aMajor == BUIS){
			returnString = "BUIS";
			return returnString;
		}
		if(aMajor == PHY){
			returnString = "PHY";
			return returnString;
		}
		if(aMajor == VIT){
			returnString = "VIT";
			return returnString;
		}
		if(aMajor == ASTR){
			returnString = "ASTR";
			return returnString;
		}
		if(aMajor == ENG){
			returnString = "ENG";
			return returnString;
		}
		return returnString;
}
std::string collegetostring(college aCollege){
		std::string returnString;
		if(aCollege == LPC){
			returnString = "LPC";
			return returnString;
		}
		if(aCollege == SFO){
			returnString = "SFO";
			return returnString;
		}
		if(aCollege == BRK){
			returnString = "BRK";
			return returnString;
		}
		if(aCollege == SLU){
			returnString = "SLU";
			return returnString;
		}
		if(aCollege == WASHU){
			returnString = "WASHU";
			return returnString;
		}
		if(aCollege == CSC){
			returnString = "CSC";
			return returnString;
		}
		return returnString;
}
struct student {
	int stuID; //8 characters long
	std::string fname; //24 characters long
	std::string lname; //30 characters long
	std::string college; //12 characters long
	std::string major; //4 characters long
	double gpa; //0.0 - 4.0
	double age; //14 - 90
	double grades[TOTALROWS]; //Each 0 - 100
	int totalGrades;
};



#endif /* STUDENT_HPP_ */


#include "Patient.h"
#include <string>
#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;


/**
	Default constructor - initializes everything to null or 0;
*/
Patient::Patient() {
	patientName = "";
	patientID = 0;
	priority = 0;
	estimatedTime = 0;

}

/** Constructor that takes data to build a patient object
	
	@param name - the name of the patient
	@param idNum - the id number for the patient
	@param pri - the priority (1-10) for the patient
	@param time - the estimated time of the surgery
*/
Patient::Patient(string name, long idNum, int pri, int time) {
	patientName = name;
	patientID = idNum;
	priority = pri;
	estimatedTime = time;
}

/**
	Constructur to takes a line of input and parses the data to create a patient object

	@param input a line of input from an input file
*/
Patient::Patient(string input) {
	string token = "";

	istringstream iss(input);
	getline(iss, token, ',');
	patientName = token;
	getline(iss, token, ',');
	patientID = stol(token);	
	getline(iss, token, ',');
	priority = stoi(token);		
	getline(iss, token, ',');
	estimatedTime = stoi(token);	
}


/**
	Returns the patient's name

	@ return patient's name
*/
string Patient::getPatientName() {
	return patientName;
}

/**
	Returns the patient's id number

	@return patient's id number
*/
long Patient::getPatientID() {
	return patientID;
}


/**
	Returns the patient's priority

	@return patient's priority
*/
int Patient::getPriority() {

	return priority;
}

/**
	Returns the estimated time for the patient's surgery

	@return the estimated time for the patient's surgery
*/
int Patient::getEstimatedTime() {
	return estimatedTime;
}

/**
	Assigns the patient's name

	@param name the name of the patient
*/
void Patient::setPatientName(string name) {

	patientName = name;
}

/**
	Assigns the patient's id number

	@param idNum the patient's id number
*/
void Patient::setPatientID(long idNum) {
	patientID = idNum;
}

/**
	Assigns the priority for this patient. 1 = highest priorty, 10 = lowest

	@param pri the integer representing the priority of the surgery

*/
void Patient::setPriority(int pri) {
	priority = pri;
}

/**
	Assigns the estimated time of the patient's surgery in minutes

	@param time - the estimated time of the patient's surgery in minutes.
*/
void Patient::setEstimatedTime(int time) {
	estimatedTime = time;
}

//***********************************OVERLOADED OPERATORS **********************************/

/**
	Operator to compare the priority of one patient to another. Returns true if
	the rhs Patient has a lower priority and false otherwise.

	@param rhs - the Patient object to compare

	@return true if the rhs Patient has a lower priority and false otherwise.
*/
bool Patient::operator < (Patient& rhs) const {

	if (rhs.getPriority() < this->priority)
		return true;
	else
		return false;
}

/**
	Operator to compare the priority of one patient to another. Returns true if
	the rhs Patient has a higher priority and false otherwise.

	@param rhs - the Patient object to compare

	@return true if the rhs Patient has a higher priority and false otherwise.
*/
bool Patient::operator > (Patient& rhs) const {

	if (rhs.getPriority() > this->priority)
		return true;
	else
		return false;
}

/**
	Operator to print out the patient details

	@param rhs - the patient object to print
*/
void Patient::operator << (Patient& rhs) const {

	cout << "Patient Name: " << rhs.getPatientName() << endl;
	cout << "Patient ID Number: " << rhs.getPatientID() << endl;
	cout << "Patient priority: " << rhs.getPriority() << endl;
	cout << "Estimated Surgery Time in Mins: " << rhs.getEstimatedTime() << endl;
	cout << "**********************************************" << endl;


}


/**
	Operator to compare two Patient objects. If the name and the id number are the same, the patients are
	equivalent. Returns true if equivalent, false otherwise.

	@param rhs - the Patient object to compare

	@return - true if the objects are equivalent, false otherwise.
*/
bool Patient::operator == (Patient& rhs) const {
	bool retVal = false;

	if (!(patientName.compare(rhs.getPatientName()) == 0))
		return retVal;
	if (patientID != rhs.getPatientID())
		return retVal;
	else
		retVal = true;
	return retVal;

}

/**
	Operator to compare two Patient objects. If the name or the id number are not the same, the patients are
	not equivalent. Returns true if not equivalent, false otherwise.

	@param rhs - the Patient object to compare

	@return - true if the objects are not equivalent, false otherwise.
*/
bool Patient::operator != (Patient& rhs) const {
	bool retVal = false;

	if ((patientName.compare(rhs.getPatientName()) == 0))
		return retVal;
	if (patientID == rhs.getPatientID())
		return retVal;
	else
		retVal = true;
	return retVal;

}
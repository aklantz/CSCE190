#pragma once

#include <string>
#include <cstdlib>

using namespace std;

class Patient {

private:
	//data members
	string patientName = "";
	long patientID = 0;
	int priority = 0;
	int estimatedTime = 0;

public:
	//Constructors
	Patient(string, long, int, int);
	Patient();
	Patient(string);

	//Setters and Getters
	string getPatientName();
	long getPatientID();
	int getPriority();
	int getEstimatedTime();

	void setPatientName(string);
	void setPatientID(long);
	void setPriority(int);
	void setEstimatedTime(int);

	//Overloaded Operators
	bool operator < (Patient& rhs) const;
	bool operator > (Patient& rhs) const;
	void operator << (Patient& rhs) const;
	bool operator == (Patient& rhs) const;
	bool operator != (Patient& rhs) const;
};
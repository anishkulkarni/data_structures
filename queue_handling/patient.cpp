#include "patient.h"
#include <iostream>
#include <iomanip>

using namespace std;

patient::patient()
{
	id = -1;
	name[0] = '\0';
	weight = -1;
	bp = -1;
	patient_priority = medium;
}

void patient::enroll()
{
	int p = -1;
	do
	{
		cout << endl << "Enter the id of the patient: ";
		cin >> id;
		if (id <= 0)
			cout << "Invalid id";
	} while (id <= 0);
	cout << endl << "Enter the name of the patient: ";
	cin >> name;
	do
	{
		cout << endl << "Enter the weight of the patient: ";
		cin >> weight;
		if (weight <= 0)
			cout << "Invalid weight";
	} while (weight <= 0);
	do
	{
		cout << endl << "Enter the blood pressure of the patient: ";
	cin >> bp;
	if (bp <= 0)
		cout << "Invalid blood pressure";
	} while (bp <= 0);
	do
	{
		cout << endl << "Enter the priority of the patient\n1. high\n2. medium\n3. low\nChoice: ";
		cin >> p;
		if (p < 1 || p > 3)
			cout << "Invalid priority";
	} while (p < 1 || p > 3);
	switch (p)
	{
	case 1:
		patient_priority = high;
		break;
	case 2:
		patient_priority = medium;
		break;
	case 3:
		patient_priority = low;
		break;
	}
}

void patient::display()
{
	cout << endl << "------------------------------------------------------------------------";
	cout << endl << "|  ID  |         Name         |   Weight   | Blood Pressure | Priority |";
	cout << endl << "------------------------------------------------------------------------";
	cout << endl << "| " << setw(4) << id << " | " << setw(20) << name << " | " << setw(10) << weight << " | " << setw(14) << bp << " | ";
	switch (patient_priority)
	{
	case high:
		cout << setw(8) << "high";
		break;
	case medium:
		cout << setw(8) << "medium";
		break;
	case low:
		cout << setw(8) << "low";
		break;
	}
	cout << " |";
	cout << endl << "------------------------------------------------------------------------";
}

priority patient::get_priority()
{
	return patient_priority;
}

patient::~patient()
{
}

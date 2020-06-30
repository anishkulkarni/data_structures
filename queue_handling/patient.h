#ifndef PATIENT_H_
#define PATIENT_H_
#include"priority_list.h"

class patient
{
	int id;
	char name[20];
	float weight;
	float bp;
	priority patient_priority;
public:
	patient();
	void enroll();
	void display();
	priority get_priority();
	virtual ~patient();
};

#endif

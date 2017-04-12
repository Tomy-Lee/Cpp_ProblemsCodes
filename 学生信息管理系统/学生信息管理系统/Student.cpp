
#include "stdafx.h"
#include "Student.h"


Student::Student()
{
	id = 0; 
	name = "";
	gender = "";
}

Student::Student(int a, string s, string c)
{
	id = a;
	name = s;
	gender = c;
}

void Student::randomG()
{

	int a, b;//student id and gender
	string s;//name
	b = rand() % 2;//gender, 1 for male, 0 for female
	int len = rand() % 5 + 3;//length of name
	//generate the name
	for(int i = 0; i < len; i++)
	{
		char c = rand() % 26 + 65;
		s.append(1, c);
	}
	a = rand() % 10000 + 10380000;
	//assgin the values
	id = a;
	name = s;
	if(b) gender = "male";
	else  gender = "female";
}

int Student::getId() const
{
	return id;
}

string Student::getName() const
{
	return name;
}

string Student::getGender() const
{
	return gender;
}

void Student::setId(int x)
{
	id = x;
}

void Student::setName(string s)
{
	name = s;
}

void Student::setGender(string s)
{
	gender = s;
}

bool Student::operator >(const Student s)
{
	return id > s.id;
}

bool Student::operator <(const Student s)
{
	return id < s.id;
}

bool Student::operator ==(const Student s)
{
	return id == s.id; 
}

Student& Student::operator =(const Student& s)
{
	id = s.getId();
	name = s.getName();
	gender = s.getGender();
	return *this;
}

istream& operator >>(istream& is, Student& s)
{
	is >> s.id >> s.name >> s.gender;
	return is;
}

ostream& operator <<(ostream& os, const Student& s)
{
	os << s.id << "\t" << s.name << "\t" << s.gender << endl;
	return os;
}
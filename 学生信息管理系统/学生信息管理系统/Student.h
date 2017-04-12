
#include "stdafx.h"
#pragma once

class Student
{
public:
	friend class List;
	Student();//default constructor
	Student(int a, string s, string c);//initialize with id and name

	void randomG();//*****generate an object randomly*****

	int getId() const;          /*		   */
	string getName() const;	   /*accessors*/
	string getGender() const; /*		 */

	void setId(int x);          /*		 */
	void setName(string s);	   /*setters*/
	void setGender(string s); /*	   */

	friend istream& operator >>(istream& is, Student& s);//for input operation
	friend ostream& operator <<(ostream& os, const Student& s);//for output operation

	bool operator >(const Student s);//comparison operator overloaded
	bool operator <(const Student s);//comparison operator overloaded
	bool operator ==(const Student s);//comparison operator overloaded

	Student& operator =(const Student& s);//assignment operator overloaded
private:
	int id;
	string name;
	string gender;
};
istream& operator >>(istream& is, Student& s);
ostream& operator <<(ostream& os, const Student& s);

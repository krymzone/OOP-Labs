#include <iostream>
#include <string>
using namespace std;

enum BUDGET_TYPE 
{
	TAX = 1,
	BUDGET = 2
};

class Student
{
	char* name;
	string address;
	int id;
	int age;

public:
	Student() 
	{
		this->name = nullptr;
		this->address = "";
		this->id = -1;
		this->age = -1;
	}

	Student(char* name, string address, int id, int age)
	{
		this->id = id;
		this->age = age;
		this->address = address;
		//this->name = name;
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}

	Student(const Student& copy) 
	{
		this->id = copy.id;
		this->age = copy.age;
		this->address = copy.address;
		//this->name = name;
		this->name = new char[strlen(copy.name) + 1];
		strcpy_s(this->name, strlen(copy.name) + 1, copy.name);
	}
};

int main() 
{
	Student s1;
	Student s2((char*)"Chita Cristian", "Bucharest", 15629, 22);
	Student s3 = s2;
	Student s4(s2);
}
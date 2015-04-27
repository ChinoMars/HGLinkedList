#include "People.h"
#include <iomanip>

using namespace std;

Person::Person(string na, int ag, string gen, string id):name(na),age(ag),gender(gen),idNum(id)
{

}

Person::~Person(){}

istream& operator >>(istream &is, Person& per)
{
	is >> per.name
	   >> per.age
	   >> per.gender
	   >> per.idNum;
	   
	return is;
}

ostream& operator <<(ostream &os, const Person& per)
{
	os << per.name << ' '
	   << per.age << ' '
	   << per.gender << ' '
	   << per.idNum
	   << endl;
	   
	return os;
	   
}

void Person::disp()
{

}

string Person::getIdNum()
{
	return idNum;
}

Student::Student(string na, int ag, string gen, string id, string maj):Person(na,ag,gen,id),major(maj)
{

}

Student::~Student(){}

istream& operator >>(istream& is, Student& stu)
{
	is >> stu.name
	   >> stu.age
	   >> stu.gender
	   >> stu.idNum
	   >> stu.major;
	   
	return is;
}

ostream& operator <<(ostream& os, const Student& stu)
{
	os << stu.name << ' '
	   << stu.age << ' '
	   << stu.gender << ' '
	   << stu.idNum << ' '
	   << stu.major 
	   << endl;
	   
	return os;
	   
}

void Student::disp()
{
	
}

string Student::getIdNum()
{
	return idNum;
}

Employee::Employee(string na, int ag, string gen, string id, double sal):Person(na,ag,gen,id),salary(sal)
{

}

Employee::~Employee(){}

istream& operator >>(istream& is, Employee& emp)
{
	is >> emp.name
	   >> emp.age
	   >> emp.gender
	   >> emp.idNum
	   >> emp.salary;
	   
	return is;
}

ostream& operator <<(ostream& os, const Employee& emp)
{
	os << emp.name << ' '
	   << emp.age << ' '
	   << emp.gender << ' '
	   << emp.idNum << ' '
	   << emp.salary 
	   << endl;
	   
	return os;
	   
}

void Employee::disp()
{
	
}

string Employee::getIdNum()
{
	return idNum;
}

Ungraduate::Ungraduate(string na, int ag, string gen, string id, string maj, double engmar):Person(na,ag,gen,id),Student(na, ag, gen, id, maj),engMark(engmar)
{

}


Ungraduate::~Ungraduate(){}

istream& operator >>(istream& in, Ungraduate& ungra)
{
	in >> ungra.name
	   >> ungra.age
	   >> ungra.gender
	   >> ungra.idNum
	   >> ungra.major
	   >> ungra.engMark;
	   
	return in;
}

ostream& operator <<(ostream& os, const Ungraduate& ungra)
{
	os << ungra.name << ' '
	   << ungra.age << ' '
	   << ungra.gender << ' '
	   << ungra.idNum << ' '
	   << ungra.major << ' '
	   << ungra.engMark
	   << endl;
	   
	return os; 
}

void Ungraduate::disp()
{
	cout << "<Undegreaduate>" << '\n'
		 << "Name: " << name << '\n'
		 << "Age: " << age << '\n' 
		 << "Gender: " << gender << '\n' 
		 << "IdNumber: " << idNum << '\n'
		 << "Major: " << major << '\n'
		 << "English Score: " << engMark 
		 << endl;
}

string Ungraduate::getIdNum()
{
	return idNum;
}


Graduate::Graduate(string na, int ag, string gen, string id, string maj, string tut)
:Person(na,ag,gen,id),Student(na,ag,gen,id,maj), tutor(tut)
{

}

Graduate::~Graduate(){}

istream& operator >>(istream& in, Graduate& gra)
{
	in >> gra.name
	   >> gra.age
	   >> gra.gender
	   >> gra.idNum
	   >> gra.major
	   >> gra.tutor;
	   
	return in;
}

ostream& operator <<(ostream& os, const Graduate& gra)
{
	os << gra.name << ' '
	   << gra.age << ' '
	   << gra.gender << ' '
	   << gra.idNum << ' '
	   << gra.major << ' '
	   << gra.tutor << ' '
	   << endl;
	   
	return os; 
}

void Graduate::disp()
{
	cout << "<Graduate>" << '\n'
		 << "Name: " << name << '\n'
		 << "Age: " << age << '\n' 
		 << "Gender: " << gender << '\n' 
		 << "IdNumber: " << idNum << '\n'
		 << "Major: " << major << '\n'
		 << "Tutor: " << tutor 
		 << endl;
}

string Graduate::getIdNum()
{
	return idNum;
}

OnWorkGraduate::OnWorkGraduate(string na, int ag, string gen, string id, string maj, string tut, double sal)
:Person(na,ag,gen,id), Graduate(na,ag,gen,id,maj,tut), Employee(na,ag,gen,id,sal)
{

}

OnWorkGraduate::~OnWorkGraduate()
{

}

istream& operator >>(istream& in, OnWorkGraduate& onw)
{
	in >> onw.name
	   >> onw.age
	   >> onw.gender
	   >> onw.idNum
	   >> onw.major
	   >> onw.tutor
	   >> onw.salary;
	   
	return in;
}

ostream& operator <<(ostream& os, const OnWorkGraduate& onw)
{
	os << onw.name << ' '
	   << onw.age << ' '
	   << onw.gender << ' '
	   << onw.idNum << ' '
	   << onw.major << ' '
	   << onw.tutor << ' '
	   << onw.salary << ' '
	   << endl;
	   
	return os; 
}

void OnWorkGraduate::disp()
{
	cout << "<OnWorkGraduate>" << '\n'
		 << "Name: " << name << '\n'
		 << "Age: " << age << '\n' 
		 << "Gender: " << gender << '\n' 
		 << "IdNumber: " << idNum << '\n'
		 << "Major: " << major << '\n'
		 << "Tutor: " << tutor << '\n'
		 << "Salary: " << salary
		 << endl;
}

string OnWorkGraduate::getIdNum()
{
	return idNum;
}

Teacher::Teacher(string na, int ag, string gen, string id, double sal, string res)
:Person(na,ag,gen,id), Employee(na,ag,gen,id,sal), research(res)
{

}

Teacher::~Teacher(){}

istream& operator >>(istream& in, Teacher& tea)
{
	in >> tea.name
	   >> tea.age
	   >> tea.gender
	   >> tea.idNum
	   >> tea.salary
	   >> tea.research;
	   
	return in;
}

ostream& operator <<(ostream& os, const Teacher& tea)
{
	os << tea.name << ' '
	   << tea.age << ' '
	   << tea.gender << ' '
	   << tea.idNum << ' '
	   << tea.salary << ' '
	   << tea.research
	   << endl;
	   
	return os; 
}

void Teacher::disp()
{
	cout << "<Teacher>" << '\n'
		 << "Name: " << name << '\n'
		 << "Age: " << age << '\n' 
		 << "Gender: " << gender << '\n' 
		 << "IdNumber: " << idNum << '\n'
		 << "Salary: " << salary << '\n'
		 << "Research: " << research
		 << endl;
}

string Teacher::getIdNum()
{
	return idNum;
}

Staff::Staff(string na, int ag, string gen, string id, double sal, string pos)
:Person(na,ag,gen,id), Employee(na,ag,gen,id,sal), position(pos)
{

}

Staff::~Staff(){}

istream& operator >>(istream& in, Staff& sta)
{
	in >> sta.name
	   >> sta.age
	   >> sta.gender
	   >> sta.idNum
	   >> sta.salary
	   >> sta.position;
	   
	return in;
}

ostream& operator <<(ostream& os, const Staff& sta)
{
	os << sta.name << ' '
	   << sta.age << ' '
	   << sta.gender << ' '
	   << sta.idNum << ' '
	   << sta.salary << ' '
	   << sta.position
	   << endl;
	   
	return os; 
}

void Staff::disp()
{
	cout << "<Staff>" << '\n'
		 << "Name: " << name << '\n'
		 << "Age: " << age << '\n' 
		 << "Gender: " << gender << '\n' 
		 << "IdNumber: " << idNum << 'n'
		 << "Salary: " << salary << '\n'
		 << "Position: " << position
		 << endl;
}

string Staff::getIdNum()
{
	return idNum;
}


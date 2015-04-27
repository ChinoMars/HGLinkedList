#include <iostream>
#include <string>

using namespace std;

class Person
{
	public:
		Person(string na = "", int ag = 0, string gen = "", string id = "");
		virtual ~Person();
		
		friend istream& operator >>(istream&, Person&);
		friend ostream& operator <<(ostream&, const Person&);

		virtual void disp();
		virtual string getIdNum();
		
	protected:
		string name;
		int age;
		string gender;
		string idNum;
};

class Student : virtual public Person
{
	public:
		Student(string na = "", int ag = 0, string gen = "", string id = "", string maj = "");
		
		virtual ~Student();
		
		friend istream& operator >>(istream&, Student&);
		friend ostream& operator <<(ostream&, const Student&);

		virtual void disp();
		virtual string getIdNum();
		
	protected:
		string major;
};

class Employee : virtual public Person
{
	public:
		Employee(string na = "", int ag = 0, string gen = "", string id = "", double sal = 0);

		virtual ~Employee();

		friend istream& operator >>(istream&, Employee&);
		friend ostream& operator <<(ostream&, const Employee&);

		virtual void disp();
		virtual string getIdNum();

	protected:
		double salary;
};

class Ungraduate : public Student
{
	public:
		Ungraduate(string na = "", int ag = 0, string gen = "", string id = "", string maj = "", double engmar = 0);

		virtual ~Ungraduate();
		
		friend istream& operator >>(istream&, Ungraduate&);
		friend ostream& operator <<(ostream&, const Ungraduate&);

		virtual void disp();
		virtual string getIdNum();
		
	protected:
		double engMark;
};


class Graduate : public Student
{
	public:
		Graduate(string na = "", int ag = 0, string gen = "", string id = "", string maj = "", string tut = "");
	
		virtual ~Graduate();
		
		friend istream& operator >>(istream&, Graduate&);
		friend ostream& operator <<(ostream&, const Graduate&);

		virtual void disp();
		virtual string getIdNum();
		
	protected:
		string tutor;
};

class OnWorkGraduate : public Graduate, public Employee
{
	public:
		OnWorkGraduate(string na = "", int ag = 0, string gen = "", string id = "", string maj = "", string tut= "", double sal = 0);
	
		virtual ~OnWorkGraduate();
		
		friend istream& operator >>(istream&, OnWorkGraduate&);
		friend ostream& operator <<(ostream&, const OnWorkGraduate&);

		virtual void disp();
		virtual string getIdNum();
		
	
};

class Teacher : public Employee
{
	public:
		Teacher(string na = "", int ag = 0, string gen = "", string id = "", double sal = 0, string res = "");

		virtual ~Teacher();

		friend istream& operator >>(istream&, Teacher&);
		friend ostream& operator <<(ostream&, const Teacher&);

		virtual void disp();
		virtual string getIdNum();

	protected:
		string research;
};

class Staff : public Employee
{
	public:
		Staff(string na = "", int ag = 0, string gen = "", string id = "", double sal = 0, string pos = "");

		virtual ~Staff();

		friend istream& operator >>(istream&, Staff&);
		friend ostream& operator <<(ostream&, const Staff&);

		virtual void disp();
		virtual string getIdNum();

	protected:
		string position;
};

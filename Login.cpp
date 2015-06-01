#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;
/*##################################################   Ա����Ϣ   #####################################################*/
class Employee
{
public:
	Employee();

	Employee(std::string na, std::string se, std::string add, std::string ID,
		std::string dep, int ag, int sal, int bon, std::string hire, std::string resign)
		: name(na), sex(se), address(add), ID_Number(ID), dep_Name(dep), age(ag),
		salary(sal), bonus(bon), hiredate(hire), resign_date(resign){};

	//�������캯��
	Employee(const Employee& emp);

	//���û�����Ϣ��������
	void setInfo();  //������Ϣ
	void print()const;    //��ʾ��Ϣ
	void setName(std::string name);  //��������
	void setSex(char sex);  //�����Ա�
	void setAddress(std::string address);   //���õ�ַ
	void setIdentityNumber(std::string ID_Number);  //�������֤��
	void setDepartmentName(std::string dep_Name);  //������������
	void Setc(int age, int salary, int bonus, int hiredate, int resign_date);//�������䡢���ʡ����𡢾�ְ���ڡ���ְ���ڵķ���

	//��ȡ��Ϣget��������
	std::string get_name();
	std::string get_sex();
	std::string get_address();
	std::string get_ID_Number();
	std::string get_dep_Name();
	int get_age();
	int get_salary();
	int get_bonus();
	std::string get_hiredate();
	std::string get_resign_date();

	//����һ����ֵ�����
	Employee &operator=(Employee &emp);

private:
	std::string name;
	std::string sex;
	std::string address;
	std::string ID_Number;
	std::string dep_Name;

	int age;
	int salary;
	int bonus;
	std::string hiredate;
	std::string resign_date;
};

Employee::Employee()
{
	name = "";
	sex = "";
	address = "";
	ID_Number = "";
	dep_Name = "";
	age = 0;
	salary = 0;
	bonus = 0;
	hiredate = "";
	resign_date = "";
}

Employee::Employee(const Employee&emp)
{
	name = emp.name;
	sex = emp.sex;
	address = emp.address;
	ID_Number = emp.ID_Number;
	dep_Name = emp.dep_Name;
	age = emp.age;
	salary = emp.salary;
	bonus = emp.bonus;
	hiredate = emp.hiredate;
	resign_date = emp.resign_date;
}

Employee &Employee::operator=(Employee &emp)
{
	name = emp.name;
	sex = emp.sex;
	address = emp.address;
	ID_Number = emp.ID_Number;
	dep_Name = emp.dep_Name;
	age = emp.age;
	salary = emp.salary;
	bonus = emp.bonus;
	hiredate = emp.hiredate;
	resign_date = emp.resign_date;
	return *this;
}

void Employee::setInfo()
{
	/*������Ϣ¼��*/
	string name, sex, address, ID_Number, dep_Name;
	int age, salary, bonus;
	string hiredate, resign_date;

	cout << "����������Ա���������Ա𡢵�ַ�����֤�š��������ƣ�" << endl;
	cin >> name >> sex >> address >> ID_Number >> dep_Name;
	cout << "����������Ա�����䡢���ʡ�����" << endl;
	cin >> age >> salary >> bonus;
	cout << "����������Ա����ְ���ڡ���ְ����(����������Ӧ���ڣ���֮���Ա��δ��ְ��)��" << endl;
	cin >> hiredate >> resign_date;
	cout << endl;

	//���ø�����Ա
	this->name = name;
	this->sex = sex;
	this->address = address;
	this->ID_Number = ID_Number;
	this->dep_Name = dep_Name;
	this->age = age;
	this->salary = salary;
	this->bonus = bonus;
	this->hiredate = hiredate;
	this->resign_date = resign_date;
}

void Employee::print()const
{
	cout << "########################################################################";
	cout << "*����*:" << name << "      *�ձ�*:" << sex << "      *����*:" << age << endl;

	cout << "*����*: " << dep_Name << "      *����*: " << salary << "      *����*:" << bonus << endl;

	cout << "*��ַ*: " << address << "      *���֤��*: " << ID_Number << endl;

	cout << "*��ְ����*: " << hiredate << "      *��ְ����*: " << resign_date << endl;

	cout << "########################################################################";
}

void Employee::setName(string name)
{
	this->name = name;
}

void Employee::setSex(char sex)
{
	this->sex = sex;
}

void Employee::setAddress(string address)
{
	this->address = address;
}

void Employee::setIdentityNumber(string ID_Number)
{
	this->ID_Number = ID_Number;
}

void Employee::setDepartmentName(string dep_Name)
{
	this->dep_Name = dep_Name;
}

void Employee::Setc(int age, int salary, int bonus, int hiredate, int resign_date)
{
	this->age = age;
	this->salary = salary;
	this->bonus = bonus;
	this->hiredate = hiredate;
	this->resign_date = resign_date;
}

string  Employee::get_name()
{
	return name;
}

string Employee::get_sex()
{
	return sex;
}

string Employee::get_address()
{
	return address;
}

string Employee::get_ID_Number()
{
	return ID_Number;
}

string Employee::get_dep_Name()
{
	return dep_Name;
}

string Employee::get_hiredate()
{
	return hiredate;
}

string Employee::get_resign_date()
{
	return resign_date;
}

int Employee::get_age()
{
	return age;
}
int Employee::get_salary()
{
	return salary;
}
int Employee::get_bonus()
{
	return bonus;
}

/*###############################   ����Աʵ����ʾ�����ӡ����ҡ�ɾ�����õ���������   ######################################*/
class Addmin
{
	friend void login(Addmin&);

public:
	Addmin() = default;
	Addmin(std::string usna, std::string pwd) : username(usna), passwd(pwd), employee(new vector<Employee>){};

	//���ܺ���
	void display();//��ʾ
	void Add(Employee emp);//����
	void Search(std::string name);//����
	void Delete(std::string name);//ɾ��
	int GetCount();//��ȡ�����ķ���

private:
	//�洢������Ա��vector����
	//shared_ptr<vector<Employee>> employee = make_shared<vector<Employee>>();
	shared_ptr<vector<Employee>> employee;

	string username; //����Ա�˻���
	string passwd;   //����Ա����
};



void Addmin::display()
{
	cout << "���� " << GetCount() << "����¼." << endl;
	for (auto it = employee->cbegin(); it != employee->cend(); ++it)
		it->print();
}

void Addmin::Add(Employee emp)
{
	employee->push_back(emp);
}

void Addmin::Search(string name)
{
	if (employee->empty())
	{
		cout << "����ʧ�ܣ���Ϊ��¼Ϊ�գ�" << endl;
	}
	vector<Employee>::iterator it;
	for (it = employee->begin(); it != employee->end(); ++it)
	{
		if (it->get_name() == name)
		{
			it->print();
		}
	}
	if (it == employee->end())
	{
		cout << "����ʧ�ܣ����ݿ��в���������Ϊ " << name << "�ļ�¼!" << endl;;
	}
}

void Addmin::Delete(std::string name)
{
	vector<Employee>::iterator it;
	for (it = employee->begin(); it != employee->end(); ++it)
	{
		if (it->get_name() == name)
		{
			employee->erase(it);
			cout << "ɾ���ɹ���" << endl;
			return;
		}
	}
	cout << "ɾ��ʧ�ܣ�δ���ҵ���Ҫɾ���ļ�¼��" << endl;
}

int Addmin::GetCount()
{
	return static_cast<int>(employee->size());
}


void login(Addmin& addmin)
{
	string usna, pwd;
loop:
	cout << "�û�����";
	cin >> usna;
	cout << " ���룺";
	cin >> pwd;
	if (usna == addmin.username && pwd == addmin.passwd)
	{
		cout << "\n\n\n\n\n\n";
		cout << "                         ��************************��\n";
		cout << "                         ��.$.$..$.$..$.$..$.$..$.$��\n";
		cout << "                         ��*********************** ��\n";
		cout << "                         ��     ��  ����! ��       ��\n";
		cout << "                         ��------------------------��\n";
		cout << "                         ��  ��ӭʹ�����¹���ϵͳ  ��\n";
		cout << "                         ��------------------------��\n";
		cout << "                         ��   �ʺţ�" << usna << "       ��\n";
		cout << "                         ��------------------------��\n";
		cout << "                         ��************************��\n";

		goto L1;
	}
	else
	{
		cout << "�Բ����û����������������������." << endl;
		goto loop;
	}
L1:;
}

int main(void)
{
	Addmin addmin("oyjb", "root");
	login(addmin); //��½ϵͳ

	int choice = 0; //ѡ�����ѡ��
	while (true)
	{
		//system("cls");

		cout << "                ***********���¹���ϵͳ************\n" << endl;

		cout << "                ------********************--------" << endl;

		cout << "                &&--------1.��ʾ��Ϣ.-----------&&" << endl;

		cout << "                &&--------2.������Ϣ.-----------&&" << endl;

		cout << "                &&--------3.������Ϣ.-----------&&" << endl;

		cout << "                &&--------4.ɾ����Ϣ.-----------&&" << endl;

		cout << "                &&--------5.�޸���Ϣ.-----------&&" << endl;

		cout << "\n              ѡ��:";

		cin >> choice;
		switch (choice)
		{
		case 1:
			addmin.display();
			break;

		case 2: //switch��ɫ�»��ߣ�Error:���ƴ���������ʵ��������취������Ӵ�����{}������������������
		{
					Employee emp;
					emp.setInfo();
					addmin.Add(emp);
					break;
		}

		case 3:
		{
				  string na;
				  cout << "������Ҫ���ҵ�Ա����������";
				  cin >> na;
				  addmin.Search(na);
		}

		case 4:
		{
				  string na;
				  cout << "������Ҫɾ����Ա����������";
				  cin >> na;
				  addmin.Delete(na);
		}


		default:
			break;
		}
	}

	system("pause");
	return 0;
}

#endif
#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;
/*##################################################   员工信息   #####################################################*/
class Employee
{
public:
	Employee();

	Employee(std::string na, std::string se, std::string add, std::string ID,
		std::string dep, int ag, int sal, int bon, std::string hire, std::string resign)
		: name(na), sex(se), address(add), ID_Number(ID), dep_Name(dep), age(ag),
		salary(sal), bonus(bon), hiredate(hire), resign_date(resign){};

	//拷贝构造函数
	Employee(const Employee& emp);

	//设置基本信息方法集合
	void setInfo();  //输入信息
	void print()const;    //显示信息
	void setName(std::string name);  //设置名字
	void setSex(char sex);  //设置性别
	void setAddress(std::string address);   //设置地址
	void setIdentityNumber(std::string ID_Number);  //设置身份证号
	void setDepartmentName(std::string dep_Name);  //设置所属部门
	void Setc(int age, int salary, int bonus, int hiredate, int resign_date);//设置年龄、工资、奖金、就职日期、辞职日期的方法

	//获取信息get方法集合
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

	//重载一个赋值运算符
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
	/*基本信息录入*/
	string name, sex, address, ID_Number, dep_Name;
	int age, salary, bonus;
	string hiredate, resign_date;

	cout << "请依次输入员工姓名、性别、地址、身份证号、部门名称：" << endl;
	cin >> name >> sex >> address >> ID_Number >> dep_Name;
	cout << "请依次输入员工年龄、工资、奖金：" << endl;
	cin >> age >> salary >> bonus;
	cout << "请依次输入员工入职日期、辞职日期(若有则填相应日期，反之填“该员工未辞职”)：" << endl;
	cin >> hiredate >> resign_date;
	cout << endl;

	//设置各个成员
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
	cout << "*姓名*:" << name << "      *姓别*:" << sex << "      *年龄*:" << age << endl;

	cout << "*部门*: " << dep_Name << "      *工资*: " << salary << "      *奖金*:" << bonus << endl;

	cout << "*地址*: " << address << "      *身份证号*: " << ID_Number << endl;

	cout << "*就职日期*: " << hiredate << "      *辞职日期*: " << resign_date << endl;

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

/*###############################   管理员实现显示、增加、查找、删除、得到数量的类   ######################################*/
class Addmin
{
	friend void login(Addmin&);

public:
	Addmin() = default;
	Addmin(std::string usna, std::string pwd) : username(usna), passwd(pwd), employee(new vector<Employee>){};

	//功能函数
	void display();//显示
	void Add(Employee emp);//增加
	void Search(std::string name);//查找
	void Delete(std::string name);//删除
	int GetCount();//获取数量的方法

private:
	//存储所有人员的vector容器
	//shared_ptr<vector<Employee>> employee = make_shared<vector<Employee>>();
	shared_ptr<vector<Employee>> employee;

	string username; //管理员账户名
	string passwd;   //管理员密码
};



void Addmin::display()
{
	cout << "共有 " << GetCount() << "条记录." << endl;
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
		cout << "查找失败！因为记录为空！" << endl;
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
		cout << "查找失败！数据库中不存在姓名为 " << name << "的记录!" << endl;;
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
			cout << "删除成功！" << endl;
			return;
		}
	}
	cout << "删除失败！未查找到需要删除的记录！" << endl;
}

int Addmin::GetCount()
{
	return static_cast<int>(employee->size());
}


void login(Addmin& addmin)
{
	string usna, pwd;
loop:
	cout << "用户名：";
	cin >> usna;
	cout << " 密码：";
	cin >> pwd;
	if (usna == addmin.username && pwd == addmin.passwd)
	{
		cout << "\n\n\n\n\n\n";
		cout << "                         ★************************★\n";
		cout << "                         ★.$.$..$.$..$.$..$.$..$.$★\n";
		cout << "                         ★*********************** ★\n";
		cout << "                         ★     ★  您好! ★       ★\n";
		cout << "                         ★------------------------★\n";
		cout << "                         ★  欢迎使用人事管理系统  ★\n";
		cout << "                         ★------------------------★\n";
		cout << "                         ★   帐号：" << usna << "       ★\n";
		cout << "                         ★------------------------★\n";
		cout << "                         ★************************★\n";

		goto L1;
	}
	else
	{
		cout << "对不起！用户名或密码错误，请重新输入." << endl;
		goto loop;
	}
L1:;
}

int main(void)
{
	Addmin addmin("oyjb", "root");
	login(addmin); //登陆系统

	int choice = 0; //选择操作选项
	while (true)
	{
		//system("cls");

		cout << "                ***********人事管理系统************\n" << endl;

		cout << "                ------********************--------" << endl;

		cout << "                &&--------1.显示信息.-----------&&" << endl;

		cout << "                &&--------2.增加信息.-----------&&" << endl;

		cout << "                &&--------3.查找信息.-----------&&" << endl;

		cout << "                &&--------4.删除信息.-----------&&" << endl;

		cout << "                &&--------5.修改信息.-----------&&" << endl;

		cout << "\n              选择:";

		cin >> choice;
		switch (choice)
		{
		case 1:
			addmin.display();
			break;

		case 2: //switch红色下划线，Error:控制传输跳过的实例化解决办法就是添加大括号{}来结束变量的作用域
		{
					Employee emp;
					emp.setInfo();
					addmin.Add(emp);
					break;
		}

		case 3:
		{
				  string na;
				  cout << "请输入要查找的员工的姓名：";
				  cin >> na;
				  addmin.Search(na);
		}

		case 4:
		{
				  string na;
				  cout << "请输入要删除的员工的姓名：";
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
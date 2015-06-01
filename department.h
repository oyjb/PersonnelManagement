#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <iostream>
//员工信息
class Employee
{
public:
	Employee(){}
	//设置基本信息方法集合
	void setInfo();  //输入信息
	void print();    //显示信息
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
	int get_hiredate();
	int get_resign_date();

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
	int hiredate;
	int resign_date;
};


//定义一个能实现显示、增加、查找、删除、得到数量的类 
class CStufile
{
public:
	void display();//显示
	void Add(Employee &stu);//增加
	bool Search(std::string name);//查找
	void Delete(std::string name);//删除
	void GetCount();//获取数量的方法
};

#endif
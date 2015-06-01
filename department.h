#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <iostream>
//Ա����Ϣ
class Employee
{
public:
	Employee(){}
	//���û�����Ϣ��������
	void setInfo();  //������Ϣ
	void print();    //��ʾ��Ϣ
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
	int get_hiredate();
	int get_resign_date();

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
	int hiredate;
	int resign_date;
};


//����һ����ʵ����ʾ�����ӡ����ҡ�ɾ�����õ��������� 
class CStufile
{
public:
	void display();//��ʾ
	void Add(Employee &stu);//����
	bool Search(std::string name);//����
	void Delete(std::string name);//ɾ��
	void GetCount();//��ȡ�����ķ���
};

#endif
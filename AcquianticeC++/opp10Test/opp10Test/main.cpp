//
//  main.cpp
//  opp10Test
//
//  Created by 赵桐 on 2019/7/3.
//  Copyright © 2019 赵桐. All rights reserved.
//

#include <iostream>
#include <string>

#define N 20

using namespace std;

class Person
{
protected:
    string szName;
public:
    Person(string strName = ""):szName(strName){}
    virtual void Print()
    {
        cout << "Person "<<szName<<endl;
    }
};

class Student :virtual public Person
{
protected:
    int iNumber ;
public:
    Student(string strName = "",int _number = 0):Person(strName)
    {
        iNumber = _number;
    }
    void Print()
    {
        cout << "Student "<<Person::szName<<" " <<iNumber<<endl;
    }
};

class Teacher : public Person
{
protected:
    int iYear ;
public:
    Teacher(string strName = "",int _year = 0):Person(strName)
    {
        iYear = _year;
    }
    void Print()
    {
        cout <<"Teacher "<<Person::szName<<" " <<iYear<<endl;
    }
};

class Graduate : public Student
{
protected:
    string szResearch;
public:
    Graduate(string strName = "",int iNumber = 0,string _szResearch = ""):Student(strName,iNumber),Person(strName)
    {
        szResearch = _szResearch;
    }
    void Print()
    {
        cout << "Graduate "<<Person::szName<<" " <<Student::iNumber<<" "<<szResearch<<endl;
    }
};

void Run();
int Judge(char *);
int Power(int );

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    Run();
//    cout << Judge("49");
//    cout << "Hello, World!\n";
    return 0;
}
void Run()
{
    int peopleNumber,iYear,iNumber;
//    int peopleorder;
//    Person * peopleArr;
    char peopleorder[N];
    string order,strName,strRea;
    cin >> peopleNumber;
    Person * peopleArr[peopleNumber];
    
    //定义需要的各种变量；
    for (int i = 0 ; i < peopleNumber ; i++)
    {
        cin >> order;
        if (order == "Person")
        {
            cin >> strName;
            peopleArr[i] = new Person(strName);
        }
        if (order == "Student")
        {
            cin >> strName >> iNumber;
            peopleArr[i] = new Student(strName,iNumber);
        }
        if (order == "Teacher")
        {
            cin >> strName >> iYear;
            peopleArr[i] = new Teacher(strName,iYear);
        }
        if (order =="Graduate")
        {
            cin >> strName >> iNumber >> strRea;
            peopleArr[i] = new Graduate(strName,iNumber,strRea);
        }
    }
    
    //辨别输入各种变量；
    
    for (;;)
    {
        cin >> peopleorder;
        if (Judge(peopleorder) < peopleNumber)
        {
            peopleArr[Judge(peopleorder)]->Print();
        }
        if(Judge(peopleorder) == Judge("exit"))
            break;
    }
}
int Judge(char * a)
{
    int big=0,i,length=0;
    
    for (i=0;;i++)
    {
        if (a[i] != '\0')
            length++;
        else break;
    }
    
    for (i=0;;i++)
    {
        if (a[i] == '\0')
        {
            break;
        }
        else {
            big += (a[i] - '0')*Power(length--);
        }
    }
    
    
    return big;
}
int Power(int i)
{
    if (i == 1)
        return 1;
    else return 10*Power(i-1);
}

//
//  main.cpp
//  opp6Test
//
//  Created by 赵桐 on 2019/6/14.
//  Copyright © 2019 赵桐. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;
#define G 10
#define N 50
class Person
{
protected:
    char *Gender;
    int Age ;
public:
    char *Name;
    Person (const char * strname = "",const char * _g = "",int a = 0 )
    {
        Name = new char [N];
        Gender = new char [G];
        strcpy(Name, strname);
        strcpy(Gender, _g);
        Age = a;
        cout << "Person" << Person :: Name << "constructed" << endl;

    }
    ~Person()
    {
        cout << "Person" << Person :: Name << "destructed" << endl;

        //delete []Name;
       // delete []Gender;
    }
    void Printf()
    {
        cout << Name << endl ;
        cout << Gender<< endl ;
        cout << Age << endl ;
    }
};
 int TotalNumber = 0;
class StudentRecord : virtual public Person
{
protected:
    double Score;
public :
    int Number;
    char * ClassName;
  
    StudentRecord (const char *strName = "",const char*_g = "",int a =0,int _n = 0,const char*_cn="",double _s = 0.0):Person(strName,_g,a)
    {
        ClassName = new char [N];
        Number = _n;
        strcpy(ClassName, _cn);
       
        Score = _s;
        TotalNumber ++;
               cout << "Student" << Person :: Name << "constructed" << endl;
    }
    ~StudentRecord()
    {
       // Person::~Person();
        //delete ClassName;
        cout << "Student" << Person :: Name << "destructed" << endl;

    }
    void Printf()
    {
        Person::Printf();
        cout << Number << endl;
        cout << ClassName << endl;
        //cout << TotalNumber << endl;
        cout << Score << endl;
    }
};
class TeacherRecord :virtual public Person
{
protected:
    int Years;
public:
    char * CollegeName;
    char * DepartmentName;
    TeacherRecord (const char *strName = "",const char*_g = "",int a =0,const char * _cn = "",const char * _dn = "",int _y = 0):Person(strName,_g,a)
    {
        CollegeName = new char [N];
        DepartmentName = new char [N];
        strcpy(CollegeName, _cn);
        strcpy(DepartmentName, _dn);
        Years  = _y;
               cout << "teacher" << Person :: Name << "constructed" << endl;
    }
    ~TeacherRecord()
    {
        //Person::~Person();
        //some thing
        cout << "teacher" << Person :: Name << "destructed" << endl;

    }
    void Printf()
    {
        Person::Printf();
        cout << CollegeName << endl;
        cout << DepartmentName << endl;
        //cout << TotalNumber << endl;
        cout << Years << endl;
    }
};

class TeachingAssistant :virtual public StudentRecord ,virtual public TeacherRecord
{
public:
    char * LectureName;
    TeachingAssistant (const char *strName = "",const char*_g = "",int a =0,int _n = 0,const char*_ClassName="",double _s = 0.0,const char * _CollegeName = "",const char * _dn = "",int _y = 0,const char * _ln = ""):Person(strName,_g,a), StudentRecord(strName,_g,a,_n,_ClassName,_s), TeacherRecord(strName,_g,_n,_CollegeName,_dn,_y)
    {
        LectureName = new char [N];
        strcpy(LectureName, _ln);
               cout << "teachingassistant" << Person :: Name << "constructed" << endl;
    }
    ~TeachingAssistant()
    {
        cout << "teachingassistant" << Person :: Name << "destructed" << endl;
    }
    void Printf ()
    {//Name:郑七 Gender:男 Age:22 Number:2010123 ClassName:软20101 TotalCount:1 Score:8
       // 9 CollegeName:信息 DepartmentName:软件 Year:1 LectureName:数据结构
        cout << "Name:"<<Person::Name<<" Gender:"<<Person::Gender<<" Age:"<<Person::Age<<" Number:"<<StudentRecord::Number<<" ClassName:"<<StudentRecord::ClassName<<" TotalCount:"<<TotalNumber << " Score:"<<StudentRecord::Score<<" CollegeName:"<<TeacherRecord::CollegeName<<" DepartmentName:"<<TeacherRecord::DepartmentName<<" Year:"<<TeacherRecord::Years<<" LectureName:"<<TeachingAssistant::LectureName<<endl;
    }
    void SetName(const char * _Name)
    {
        strcpy(Person::Name, _Name);
    }
};
void Run();
int main(int argc, const char * argv[]) {
    // insert code here...

    //tr1.Printf();
//    StudentRecord sr1("zhaotong","man",20,2018012995,"CS1802",69.0);
//    sr1.Printf();
    
//    std::cout << "Hello, World!\n";
    Run();
    return 0;
}
void Run()
{
    TeachingAssistant TA1("郑七","男",22,2010123,"软20101",89,"信息","软件",1,"数据结构");
    TA1.Printf();
    TA1.SetName("郑八");
    TA1.Printf();
}

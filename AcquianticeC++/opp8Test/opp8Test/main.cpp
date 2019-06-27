
//
//  main.cpp
//  opp8Test
//
//  Created by 赵桐 on 2019/6/15.
//  Copyright [表情] 2019 赵桐. All rights reserved.
//

#include <iostream>
using namespace std;

class StudentRecord
{
public:
    string stuName;
    int stuNo;
    StudentRecord(string _strName = "",int _Number = 0)
    {
        stuName = _strName;
        stuNo = _Number;
    }
    void printf()
    {
        cout << "Name: "<<stuName<<",Number: "<<stuNo<<endl;
        
    }
};


class StudentNode
{
public:
    
    StudentRecord date;
    StudentNode * next;
    //    StudentNode operator = (StudentNode & lsn)
    //    {
    //        StudentNode temp;
    //        temp.date = lsn.date;
    //        temp.next = lsn.next;
    //        return temp;
    //    }
};
int StuNumber = 0;


class LinkList
{
private:
    StudentNode *h ;
public:
    LinkList():h(0) {}
    void HeadPend(StudentNode  &lsn)
    {
        lsn.next = h;
        h = &lsn;
        StuNumber ++;
        //        StudentNode temp = lsn;
        //        lsn = *h;
        //        h = &temp;
    }
    void TailPend(StudentNode & lsn)
    {
        StudentNode* temp = h;
        for (int i=0; i<StuNumber; i++)
            //        {
            //            temp = (*temp).next;
            //        }
            //        (*temp).next = &lsn;
            //        lsn.next = 0;
            
            
        {
            if (((*temp).next )==0)
            {
                (*temp).next = (&lsn);
                lsn.next = 0;
                StuNumber ++;
                break;
                
                
            }
            temp = (*temp).next;
            StuNumber++;
        }
    }
    void HeadDel()
    {
        h = (*h).next;
        StuNumber--;
    }
    void TailDel()
    {
        StudentNode* temp = h;
        for (int i=0; i<StuNumber-1; i++)
        {
            temp = (*temp).next;
        }
        (*temp).next = 0;
    }
    void Traversal(void *(pf)(StudentNode*))
    {
        StudentNode* temp = h;
        for (int i = 0; i<StuNumber; i++)
        {
            pf(temp);
            temp = (*temp).next;
        }
    }
    StudentNode * GetH(){return h;}
    void SetH(StudentNode* _h)
    {
        h = _h;
    }
};
class LinkedStak : public LinkList
{
public:
    void Push(StudentRecord record)
    {
        stack StudentNode st_1;
        st_1.date  = record;
        LinkList::TailPend(st_1);
    }
    bool Pop(StudentRecord &record)
    {
        if (GetH() ==0)
            return 1;
        StudentNode st_1;
        st_1.date  = record;
        LinkList::HeadDel();
        return 0;
    }
};
class LinkedQueue : public LinkList
{
public:
    void EnQueue(StudentRecord record)
    {
        StudentNode st_1;
        st_1.date  = record;
        LinkList::HeadPend(st_1);
    }
    bool DeQueue(StudentRecord &record)
    {
        StudentNode st_1;
        st_1.date  = record;
        LinkList::TailDel();
        return 1;
    }
    
};

int Judge();
int Run(int);

int main(int argc, const char * argv[])
{
    // insert code here...
    for(;;)
    {
      if(  Run(Judge()))
          break;
    }
    
    //    LinkedQueue queue;
    //    LinkedStak stak;
    
    
    //    StudentRecord s1("zhaotong",2018012995);
    //    s1.printf();
    //cout << "Hello, World!\n";
    return 0;
}
int Judge()
{
    string str;
    cin >> str;
    if (str == "Push")
        return 1;
    else if (str == "Pop")
        return 2;
    else if (str == "EnQueue")
        return 3;
    else if (str == "DeQueue")
        return 4;
    else if (str =="Exit")
        return 5;
    else
        return 6;
}
int Run(int instr)
{
    LinkedQueue queue;
    LinkedStak stak;
    StudentRecord sr_1;
    if (instr == 1)
    {
        string strName;
        int StNO;
        cin >> strName >> StNO;
        sr_1.stuName = strName;
        sr_1.stuNo = StNO;
        stak.Push(sr_1);
        return 0;
    }
    else if (instr == 2)
    {
        if (stak.Pop(sr_1))
            return 0;
        else
        {
            cout << "Stack is empty!"<<endl;
        }
    }
    else if (instr == 3)
    {
        string strName;
        int StNO;
        cin >> strName >> StNO;
        sr_1.stuName = strName;
        sr_1.stuNo = StNO;
        ////////////////////////////ajsoidjfonag
        return 0;
    }
    else if (instr == 4)
    {
        string strName;
        int StNO;
        cin >> strName >> StNO;
        sr_1.stuName = strName;
        sr_1.stuNo = StNO;
        return 0;
    }
    else if (instr == 5)
    {
        return 1;
    }
    else
    {
        cout << "Input error!"<<endl;
        return 0;
    }
}

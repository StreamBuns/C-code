
//
//  main.cpp
//  opp8Test
//
//  Created by 赵桐 on 2019/6/15.
//  Copyright [表情] 2019 赵桐. All rights reserved.
//stack last_in first_out
//queue last_in last_out

#include <iostream>
#include <stack>
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
        cout << "Name: "<<stuName<<", Number: "<<stuNo<<endl;
        
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
int QueueNumber = 0;

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
    void QueueHeadPend(StudentNode  &lsn)
    {
        lsn.next = h;
        h = &lsn;
        QueueNumber ++;
        //        StudentNode temp = lsn;
        //        lsn = *h;
        //        h = &temp;
    }
    void TailPend(StudentNode & lsn)
    {
        StudentNode* temp = h;
        if(StuNumber ==0)
        {
            h = &lsn;
            StuNumber++;
        }
        else for (int i=0; i<StuNumber; i++)
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
        (*h).date.printf();
        h = (*h).next;
        StuNumber--;
    }
    void TailDel()
    {
        StudentNode* temp = h;
        temp = new StudentNode;
        if(QueueNumber ==1)
        {
            (*h).date.printf();
            h=0;
            QueueNumber --;
        }
        else if(QueueNumber==2)
        {
            (*((*h).next)).date.printf();
            (*h).next = 0;
            QueueNumber--;
        }
        else{
        {
            for (int i=0; i<QueueNumber-1; i++)
        {
            temp = (*temp).next;
        }
        (*(*temp).next).date.printf();
        (*temp).next = 0;
            QueueNumber--;}}
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
        StudentNode *st_1;
        st_1 = new StudentNode;
        (*st_1).date  = record;
        LinkList::HeadPend(*st_1);
    }
    bool Pop(StudentRecord &record)
    {
        if (GetH() ==0)
            return 1;
//        StudentNode st_1;
//        st_1.date  = record;
        LinkList::HeadDel();
        return 0;
    }
};
class LinkedQueue : public LinkList
{
public:
    void EnQueue(StudentRecord record)
    {
        StudentNode *st_1;
        st_1 = new StudentNode;
        (*st_1).date  = record;
        LinkList::QueueHeadPend(*st_1);
    }
    bool DeQueue(StudentRecord &record)
    {
//        StudentNode st_1;
//        st_1.date  = record;
        if (GetH() ==0)
            return 1;
        LinkList::TailDel();
        return 0;
    }
    
};

int Judge();
int Run(int);

LinkedQueue queue;
LinkedStak stak;
StudentRecord *pstak;
StudentRecord *pqueue;

int main(int argc, const char * argv[])
{
    // insert code here...
    for(;;)
    {
      if(Run(Judge())== 1)
          break;
    }
//    Run(Judge());
    
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
//    LinkedQueue queue;
//    LinkedStak stak;
//    StudentRecord sr_1;
    if (instr == 1)
    {
        string strName;
        int StNO;
        cin >> strName >> StNO;
        StudentRecord *sr_1;
        sr_1 = new StudentRecord;
        (*sr_1).stuName = strName;
        (*sr_1).stuNo = StNO;
        pstak = sr_1;
        stak.Push(*sr_1);
        return 0;
    }
    else if (instr == 2)
    {
        if (stak.Pop(*pstak)==0)
            return 0;
        else
        {
            cout << "Stack is empty!"<<endl;
        }
    }
    else if (instr == 3)
    {
//        string strName;
//        int StNO;
//        cin >> strName >> StNO;
//        sr_1.stuName = strName;
//        sr_1.stuNo = StNO;
        string strName;
        int StNO;
        cin >> strName >> StNO;
        StudentRecord *sr_2;
        sr_2 = new StudentRecord;
        (*sr_2).stuName = strName;
        (*sr_2).stuNo = StNO;
        pqueue = sr_2;
        queue.EnQueue(*sr_2);
        return 0;
        ////////////////////////////ajsoidjfonag
        //return 0;
    }
    else if (instr == 4)
    {
        if (queue.DeQueue(*pqueue)==0)
            return 0;
        else
        {
            cout << "Queue is empty!"<<endl;
        }
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
    return 0;
}

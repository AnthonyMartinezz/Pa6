#include <iostream>
#include <string>
#include <cstring>
#include <Windows.h>


using namespace std; 


class ListNode
{
  friend class List;
public:

private:
string studentNumber;	
string name;
string idNumber;
string email;
string units;
string major;
string grade;

ListNode *pNext;
};
//***********
class List
{
  friend class ListNode;
public:

void readIn ();

private:
ListNode *pHead;
};


void mainMenu ();

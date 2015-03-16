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
string studentNumber (string information); // 1
string getId (string information); // 2
string getName (string information);
string getEmail (string information);// 3
string getUnits (string information);// 4

string getProgram (string information);// 6
string getlevel (string information);// 5

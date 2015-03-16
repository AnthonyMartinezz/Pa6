#include <iostream>
#include <string>
#include <cstring>
#include <Windows.h>


using namespace std; 


class ListNode
{
  friend class List;
  friend void readIn ();
public:
	ListNode (string studentNumber, string id, string name, string email, string units, string prgram, string level);
	ListNode (ListNode &object);

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
ListNode *makeNode (string studentNum, string idNum, string name, string email, string unit, string program, string level);
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

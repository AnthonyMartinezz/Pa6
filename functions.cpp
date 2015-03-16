#include "Pa6_header.h"
//REMEMBER YOU NEED <WINDOWS> LIBRARY

//Detailed information for petris
void mainMenu ()
{
	string mainMenu[4] = {"Import Records","Mark Absences","Generate Report", "Exit"};
	int points = 0, index = 0;

	while(true)//Run while no input..
	{
		system ("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);//High light the text below with color 15
		cout << "Main Menu" << endl;// This is now highlighted color 15 because of SetConsoleTextAttribute

		for (index = 0; index < 4; index++)
		{
			if (index == points)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);//This is the currently selected option set to windows color 11
				cout << mainMenu[index] << endl;
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);// Back to highliting the text that is currently not selected
				cout << mainMenu[index] << endl;
			}
		}
		while (true)//Now get primary key pressed.. using getAsyncstate (Windows function to read in a key from a keyboard_ Works with windows systems only)
		{
			if(GetAsyncKeyState(VK_UP) != 0)// Get the UP ARROW KEY now and check immediatly
			{
				points = points - 1;// Move down a line segment
				if (points == -1)
				{
					points = 3;//Move back to top of lists.. and set highlight the top text once again..
				}
				break;//Send to top of loop clear screen and print with new thing selected
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)// get down arrow key input
			{
				points = points +1;//Move up a line segment
				if (points == 4)// max option
				{
					points = 0;// Overlapped botten and set points to 0 to highlight mainmenu[0] to highlight again .. 
				}
				break;//Send back to top  of loop
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)//Last check for the enter coloumb
			{
				switch (points)//Test the case you want.. select option
				{
				case 0:// points == 0 // Import Recordes
					system ("cls");
					cout << "Option IMPORT RECORDS" <<endl;
					system ("pause");
					break;
				case 1:// points == 1 // MARK abscenses
					system ("cls");
					cout << "Option MAKE ABSCENSES" <<endl;
					system ("pause");
					break;
				case 2:// points == 2// Generate Report
					system ("cls");
					cout << "Option GENERATE REPORT" <<endl;
					system ("pause");
					break;
				case 3:// points == 3 // EXIT
					return;
					break;

				}
			}
		}
		Sleep (150);// Sleep is like system ("pause"); but in the sense it lets the program have time to read the input 
		
	}
}


void List::readIn ()
{
	ifstream infile;
	string filename, information;

	cout << "Please enter the file name to enter here:" << endl;
	cin >> filename;

	infile.open (filename, std::ios::in);
	infile >> information;
	
	while (!infile.eof ())
	{

		pMem = NULL;
		pCur = NULL;

		information.clear();
		infile >> information;


		//NEED MAKE NODE
		//makeNode (name,idNum,email,units);
		name = getName (information); //2
		idNum = getId (information); //3
		email = getEmail (information); // 4
		units = getUnits (information); // 5
		program = getProgram (information); // 6
		level = getlevel (information); //7
		studentNum = studentNumber (information);

		pMem = makeNode (studentNum, idNum, name, email, units, program, level);
		name.clear();
		idNum.clear ();
		email.clear ();
		units.clear ();
		program.clear ();
		level.clear ();
		studentNum.clear ();
		//pHead->pNext = nullptr; 

	}
}


ListNode *List::makeNode (string studentNum, string idNum, string name, string email, string unit, string program, string level)
{
	ListNode *pMem = NULL;

	pMem = new ListNode (studentNum, idNum, name, email, unit, program, level);//,idNum,name,email,unit,program,level);
	pMem->pNext = NULL;
	return pMem;
}

ListNode::ListNode (string studentNumber, string id, string name, string email, string units, string prgram, string level)
{
	this->studentNumber = studentNumber;
	this->idNumber = id;
	this->name = name;
	this->email = email;
	this->units = units;
	this->major = prgram;
	this->grade = level;
	//this->pNext = NULL;
}



string studentNumber (string information) // 1
{
	char valuedInfo[10];
	//string valuedInfo;
	int index = 0;



	do
	{


		valuedInfo[index] = information[index];
		//strcpy(valuedInfo[index],information[index]);
		index++;
	}while(information[index] != ',');

	valuedInfo[index] = '\0';
	return valuedInfo;
}
string getId (string information) // 2
{
	int index = 0, index2 = 0;
	char valuedInfo[10];

	for (index = 0;information[index] != ',';index++);
	//index = 0;
	index++;
	do
	{
		valuedInfo[index2] = information[index];
		index2++;
		index++;
	}while (information[index] != ',');

	valuedInfo[index2] = '\0';
	return valuedInfo;
}
string getName (string information)
{
	//2,8147,"Beck,Sara",sara@cpts122.edu,4,EE,Junior
	int index1 = 0, index2 = 0;
	char valuedInfo[20];

	for (index1 = 0;information[index1] != '"'; index1++);
	index1++;
	do
	{

		valuedInfo[index2] = information[index1];
		index2++;
		index1++;
	}while (information[index1] != '"');

	valuedInfo[index2] = '\0';

	return valuedInfo;
}
string getEmail (string information)// 3
{
	//2,8147,"Beck,Sara",sara@cpts122.edu,4,EE,Junior
	char valuedInfo[40];
	int index = 0, index2 = 0;
	//char trash;

	for(index = 0;information[index] != '"'; index++);
	index++;
	for(index;information[index] != '"'; index++);
	index = index+2;
	do
	{
		valuedInfo[index2] = information[index];
		index2++;
		index++;
	}while (information [index] != ',');

	valuedInfo[index2] = '\0';

	return valuedInfo;
}
string getUnits (string information)// 4
{
	//2,8147,"Beck,Sara",sara@cpts122.edu,4,EE,Junior
	char valuedInfo[50];
	int index = 0, index2 = 0;

	for (index = 0; information[index] != '@'; index++);
	for (index; information[index] != ','; index++);
	index++;
	do
	{
		valuedInfo[index2] = information[index];
		index2 ++;
		index++;
	}while (information[index] != ',');

	valuedInfo[index2] = '\0'; 
	return valuedInfo;
}

string getProgram (string information)// 6
{
	//2,8147,"Beck,Sara",sara@cpts122.edu,4,EE,Junior
	char valuedInfo[40];
	int index = 0, index2 = 0;

	for (index = 0; information[index] != '@'; index++);
	for (index; information[index] != ','; index++);
	index++;
	for (index; information[index] != ','; index++);
	index++;

	do
	{
		valuedInfo[index2] = information[index];
		index2++;
		index++;
	}while (information[index] != ',');

	valuedInfo[index2] = '\0';

	return valuedInfo;
}
string getlevel (string information)// 5
{
	//2,8147,"Beck,Sara",sara@cpts122.edu,4,EE,Junior
	char valuedInfo[30];
	int index = 0, index2 = 0;

	for (index = 0; information[index] != '@'; index++);
	for (index; information[index] != ','; index++);
	index++;
	for (index; information[index] != ','; index++);
	index++;
	for (index; information[index] != ','; index++);
	index++;

	do
	{
		valuedInfo[index2] = information[index];
		index2++;
		index++;
	}while (information[index] != '\0');

	valuedInfo[index2] = '\0';

	return valuedInfo;
}

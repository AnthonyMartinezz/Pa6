#include "Pa6_header.h"
//REMEMBER YOU NEED <WINDOWS> LIBRARY

//Detailed information for petris
void mainMenu ()
{
	string mainMenu[5] = {"Menu","Import Records","Mark Absences","Generate Report", "Exit"};
	int points = 0, index = 0;

	while(true)//Run while no input..
	{
		system ("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);//High light the text below with color 15
		cout << "Main Menu" << endl;// This is now highlighted color 15 because of SetConsoleTextAttribute

		for (index = 0; index < 5; index++)
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
					points = 4;//Move back to top of lists.. and set highlight the top text once again..
				}
				break;//Send to top of loop clear screen and print with new thing selected
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)// get down arrow key input
			{
				points = points +1;//Move up a line segment
				if (points == 5)// max option
				{
					points = 0;// Overlapped botten and set points to 0 to highlight mainmenu[0] to highlight again .. 
				}
				break;//Send back to top  of loop
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)//Last check for the enter coloumb
			{
				switch (points)//Test the case you want.. select option
				{
				case 0:// points == 0 // OPTION 0 MENU no use yet?
					system ("cls");
					cout << "Option MENU" <<endl;
					system ("pause");
					break;
				case 1:// points == 1 // Import Recordes
					system ("cls");
					cout << "Option IMPORT RECORDS" <<endl;
					system ("pause");
					break;
				case 2:// points == 2 // MARK abscenses
					system ("cls");
					cout << "Option MAKE ABSCENSES" <<endl;
					system ("pause");
					break;
				case 3:// points == 3// Generate Report
					system ("cls");
					cout << "Option GENERATE REPORT" <<endl;
					system ("pause");
					break;
				case 4:// points == 4 // EXIT
					return;
					break;

				}
			}
		}
		Sleep (150);// Sleep is like system ("pause"); but in the sense it lets the program have time to read the input 
		
	}
}

/**************************************************************
 * Filename: testDeque.cc
 * Updated by: Apurva Gandhi
 * Author: CSCI 132 Instructor
 * Date: 02/18/2019
 * Course: CSCI 132-01
 * Purpose: Test deque functions
 **************************************************************/
#include <iostream>
#include "deque.h"

using namespace std;

char get_command();
void help();
bool do_command(char, Deque &);

/* Post: Accepts commands from user as a menu-driven demonstration program
   for the class deque.
   Uses: The class deque and the functions introduction, get_command,
   and do_command.
*/
int main() 
{
	Deque test_deque;
	help();
	while (do_command(get_command(), test_deque));
} // end main( )

/*
  Post: A help screen for the program is printed, giving the meaning of each
  command that the user may enter.
*/
void help()
{
	cout << endl
         << "This program allows the user to enter one command" << endl
         << "(but only one)on each input line." << endl
         << "For example, if the command S is entered, then" << endl
         << "the program will serve the front of the queue." << endl
         << endl
         << " The valid commands are:" << endl
         << "A - Append the next input character to the rear." << endl
         << "P - Push the next input character to the front." << endl
         << "S - Serve the front of the queue" << endl
         << "X - Extract the rear of the queue" << endl
         << "R - Retrieve and print the front entry." << endl
         << "W - Retrieve and write the rear entry." << endl
         << "H - This help screen" << endl
         << "Q - Quit" << endl
         << "Press <Enter> to continue." << flush;
        
	char c;
	do 
	{
		cin.get(c);
	} while (c != '\n');
}  //end help( )

/*
  Pre: c represents a valid command.
  Post: Performs the given command c on the Deque test_deque.
  Returns false if c == 'q', otherwise returns true.
  Uses: The class Deque.
*/
bool do_command(char c, Deque &test_deque)
{
	bool continue_input = true;
	Queue_entry x;
	switch (c)
	{
	case 'h': help();
		break;

	case 'q':
		cout << "Deque demonstration finished." << endl;
		continue_input = false;
		break;

	case 'a':
		cout << "enter a new key to insert: ";
		cin >> x;
		if(test_deque.append_rear(x) == overflow)
            cout << "Append rear failed because deque is full." << endl;
		else 
			cout << x << " appends to rear of deque." << endl;
        cout << endl;
		break;

	case 'p':
		cout << "enter a new key to insert: ";
		cin >> x;
		if (test_deque.append_front(x) == overflow)
			cout << "Append front failed because deque is full." << endl;
		else
			cout << x << " appends to front of deque." << endl;
        cout << endl;
		break;

	case 's':
		if (test_deque.serve_front() == underflow)
			cout << "Serve front failed, the deque is empty." << endl;
		else
			cout << "Successfully served the front of the deque." << endl;
        cout << endl;
		break;

	case 'x':
		if (test_deque.serve_rear() == underflow)
			cout << "Serve rear failed, the deque is empty." << endl;
		else
			cout << "Successfully served the rear of the deque." << endl;
        cout << endl;
		break;

	case 'r':
		if (test_deque.retrieve_front(x) == underflow)
			cout << "Deque is empty." << endl;
		else
			cout << "The first entry is: " << x << endl;
        cout << endl;
		break;

	case 'w':
		if (test_deque.retrieve_rear(x) == underflow)
			cout << "Deque is empty." << endl;
		else
			cout << "The last entry is: " << x << endl;
        cout << endl;
		break;
	} //end switch on deque option

	return continue_input;
} //end do_command()

/*
  Post: Gets a valid command from the user and,
  after converting it to lower case if necessary,
  returns it.
*/
char get_command()
{
	char c = 0;

	//Ask to enter a character 
	cout << "Select command and press <Enter>: ";
	cin >> c;

    c = char(tolower(c));
    // checks if the entered character is valid
	while (c !='a' && c != 'p' && c != 's' && c != 'x' && c != 'r'&& c != 'w' && c != 'h' && c != 'q' && c != 'g')
	{
		cout << "You entered invalid command, Please enter valid command and press <Enter>: ";
		cin >> c;
		c = char(tolower(c));
	}
	return c;
} //end get_command
//end of testDeque.cc

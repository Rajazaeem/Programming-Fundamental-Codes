#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void word_count()
{
	ifstream infile("pf lab a4.txt");
}
void copy_content()
{
}
string longrst_world()
{
}
int line_count()
{
}
string replace_word()
{
}
string reverse_order()
{
}
int number_sorting()
{
}
int vowel_count()
{
}
char find_line()
{
}
void merge_files()
{
}
int main()
{
	string user_response;
	do
	{
		cout << "/t ---Welcome to Assignment #4----" << endl
			 << "Please select from the following: " << endl
			 << "1. Count words from file." << endl
			 << "2. Copy content from one file to another file." << endl
			 << "3. Find the longest word in the file." << endl
			 << "4. Find the number of lines in the file." << endl
			 << "5. Display content of file in reverse order." << endl
			 << "6. Sort numbers in file in ascending order." << endl
			 << "7. Count vowels used in the file." << endl
			 << "8. Find a specific line in the file." << endl
			 << "9. Merge to files." << endl;

		cout << endl;

		int choice;
		cout << "Please enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			word_count();
			break;
		case 2:
			copy_content();
			break;
		case 3:
			longrst_world();
			break;
		case 4:
			line_count();
			break;
		case 5:
			replace_word();
			break;
		case 6:
			reverse_order();
			break;
		case 7:
			number_sorting();
			break;
		case 8:
			vowel_count();
			break;
		case 9:
			find_line();
			break;
		case 10:
			merge_files();
			break;
		default:
			cout << "Exiting the program. Bye Bye!" << endl;
		}
		cout << endl
			 << "Would you like to continue (Yes/No): ";
		cin >> user_response; // Ask to continue
	} while (user_response == "Yes" || user_response == "yes" || user_response == "YES" || user_response == "y" || user_response == "Y");

	return 0;
}
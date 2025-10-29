#include <iostream>
#include <string>
using namespace std;

void writeProverb(int number);

int main ()
{
	int wordCode;
	
	cout << "Given the phrase:" << endl
         << "Now is the time for all good men to come to the aid of their ___"<< endl
	    << "Input a 1 if you want the sentence to be finished with par"<< endl
	    << "Input any other number for the word country" << endl;
        do{
            
	    cout<< "Please input your choice now" << endl;
	cin >> wordCode;
	cout << endl;
    if(wordCode!=1 && wordCode!=2){
        cout <<"I am sorry but that is incorrect choice! please enter 1 or 2:\n";

    }

        }while( wordCode != 1  && wordCode != 2);
	writeProverb(wordCode);

	return 0;
}


void writeProverb (int number)
{
    
if (number == 1) {
        cout << "Now is the time for all good men to come to the aid of their party." << endl;
    } 
    else
     {
        cout << "Now is the time for all good men to come to the aid of their country." << endl;
     }
}

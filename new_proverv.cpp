#include <iostream>
#include <string>
using namespace std;

void writeProverb(string word);

int main ()
{
	string word;
	
	cout << "Given the phrase:" << endl
         << "Now is the time for all good men to come to the aid of their ___"<< endl
        << "Please input your string now" << endl;
	cin >> word;
	cout << endl;    
	writeProverb(word);

	return 0;
}


void writeProverb (string word)
{
    cout<<" Now is time for all good mean to come to the aid of there "<<word<<endl;
}

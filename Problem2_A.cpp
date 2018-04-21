#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string result;
	string line;
	
	cout << "Please enter several lines of text.  This program will sort the words into alphabetical order." << endl;
	while (line.length() != 0){
		cout << "Please enter a line of text (Enter empty line to end):" << endl;
		getline(cin, line);
		result += line;
	}
	int arrSize = result.length() / 2 + 1;
	char ** arr = new char *[arrSize];
	vector<char> temp;
	for (int i = 0; i < result.length(); i++)
	{
		for (int j = 0; j < result.length(); j++)
		{
			
		}
	}
}
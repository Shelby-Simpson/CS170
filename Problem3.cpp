/*Problem3
  Assignment 2
  Shelby Simpson
  4/15/2018
  This program recursively prints out the reverse of an inputted integer with two different functions.
  The first function displays the last digit followed by the other digits in reverse order.
  The second function displays the first digit after the reverse of the second and all following digits.*/
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

void reverseDisplay1(int value);
void reverseDisplay2(int value);

int main()
{
	int num;																				//num is the inputted number to be reversed.
	cout << "This function prints out the reverse of an integer you enter.";
	cout << "Please enter a positive integer that you would like reversed:" << endl;
	cin >> num;
	while (cin.fail() || num < 0)
	{
		cout << "Please try again:" << endl;
		cin >> num;
	}
	reverseDisplay1(num);
	reverseDisplay2(num);
	system("pause");
}

//The reverseDisplay1 function prints the last digit followed by the other digits in reverse order.
void reverseDisplay1(int value)
{
	if (value < 10) cout << value << endl;
	else
	{
		int temp;		
		temp = value % 10;
		cout << temp;
		reverseDisplay1(value / 10);
	}
}

//The reverseDisplay2 function displays the first digit after the reverse of the second and all following digits.
void reverseDisplay2(int value)
{
	vector <int> digitVector;
	int tempValue = value;
	int digitCount = 0;
	int tempDigitCount = 0;
	int power = 1;
	if (value < 10) cout << value;
	else
	{
		while (tempValue > 10)
		{
			tempValue = tempValue / 10;
			digitCount++;
		}
		digitCount++;
		for (int i = 1; i < digitCount; i++)
		{
			power *= 10;
		}
		value = value % (tempValue * power);
		digitVector.push_back(tempValue);
		tempValue = value;
		while (tempValue > 0)
		{
			tempValue = tempValue / 10;
			tempDigitCount++;
		}
		for (int i = tempDigitCount; i < digitCount - 1; i++)					//This for loop pushes 0's into an array based on the difference in expected and actual digits.  
		{
			digitVector.push_back(0);
		}
		reverseDisplay2(value);
		for (int i = digitVector.size() - 1; i >= 0; i--)
		{
			cout << digitVector[i];
		}
	}

}
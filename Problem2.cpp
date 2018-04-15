/*Assignment 2
  Problem2
  Shelby Simpson
  4/15/2018
  This program calculates the sum of between 1 and 10 integers using iteration and recursion
  and then plots asterisks corresponding to the sum with each asterisks equal to 0.1.
  The sumSequence1 function calculates the sum with iteration while
  the sumSequence2 function calculates the sum with recursion.
  The plot function plots with correct amount of asterisks.*/
#include <iostream>
#include <vector>

using namespace std;

void plot(int (*sumSequence)(int), int min, int max);
int sumSequence1(int num);
int sumSequence2(int num);

int main(){
	int countMin, countMax;
	cout << "This program calculates the sum of between 1 and 10 integers using iteration and recursion." << endl;
	cout << "Please enter the minimum integer value of count: \n(Must be between 1 and 10)" << endl;
	cin >> countMin;
	while (cin.fail() || countMin < 1 || countMin > 10)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "You did not enter an acceptable value.  Please try again:" << endl;
		cin >> countMin;
	}
	cout << "please enter the maximum integer value of count: \n(Must be between 1 and 10 and greater than or equal to min" << endl;
	cin >> countMax;
	while (cin.fail() || countMax < 1 || countMax > 10 || countMax < countMin)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "You did not enter an acceptable value.  Please try again:" << endl;
		cin >> countMax;
	}
	cout << endl;
	cout << "The following sums are calculated using iteration:" << endl;
	plot(&sumSequence1, countMin, countMax);											//We call plot with sumSequence1 as an argument.
	cout << "The following sums are calculated using recursion:" << endl;
	plot(&sumSequence2, countMin, countMax);											//We call plot with sumSequence2 as an argument.
	system("pause");
}

//The sumSequence1 function sums up a set of numbers with iteration.
int sumSequence1(int num)
{
	int sum = 0;
	int numArray[10] = { 1, 2, -2, 4, 5, -1, 7, -7, 9, 10 };
	cout << "This is the sequence of numbers being summed together:" << endl;
	for (int i = 0; i < num; i++)
	{
		sum += numArray[i];
		cout << numArray[i] << ",";
	}
	cout << endl;
	return sum;
}

//The sumSequence2 function sums up a set of numbers with recursion.
int sumSequence2(int num)
{
	
	int numArray[10] = { 1, 2, -2, 4, 5, -1, 7, -7, 9, 10 };
	if (num <= 1)
	{
		return numArray[0];
	}
	else {
		return numArray[num - 1] + sumSequence2(num - 1);
	}
}

//The plot function plots the number of asterisks corresponding to the sum.
void plot(int (*sumSequence)(int), int min, int max)
{
	for (int i = min; i <= max; i++)
	{
		cout << '\n';
		double numAst = (*sumSequence)(i) * 10;
		cout << "The sum of this iteration is " << numAst / 10 << endl;
		for (int i = 1; i <= (int)numAst; i++){
			cout << "*";
		}
		cout << '\n' << endl;
	}
	
	return;
}


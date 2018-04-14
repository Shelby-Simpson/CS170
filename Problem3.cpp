#include <iostream>
#include <string>

using namespace std;

void reverseDisplay1(int value);
void reverseDisplay2(int value);

int main()
{
	int num;
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

void reverseDisplay2(int value)
{
	if (value < 10) cout << value;
	else
	{
		int temp = value;
		int count = 0;
		int newValue = value;
		while (newValue > 10)
		{
			newValue = newValue / 10;
			count++;
		}
		int power = newValue * pow(10, count);
		int powerCheck = (newValue - 1) * pow(10, count);
		if (value % (power*10) < power - powerCheck)
		{
			reverseDisplay2(value % power);
			cout << 0;
		}
		else {
			reverseDisplay2(value % power);
			cout << newValue;
		}
	}
}

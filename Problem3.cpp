#include <iostream>
#include <string>

using namespace std;

void reverseDisplay1(int value);
int reverse(int value);

int main()
{
	int num = 5678;
	reverseDisplay1(num);
	system("pause");
}

void reverseDisplay1(int value)
{
	cout << reverse(value) << endl;
}

int reverse(int value)
{

}
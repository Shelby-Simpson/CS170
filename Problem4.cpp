/*Assignment 2
  Problem 4
  Shelby Simpson
  4/15/2018
  This program creates a magic square from a user-inputted positive odd integer.
  This is done with an array of arrays in the magicSquare function.*/
#include <iostream>
#include <iomanip>

using namespace std;

void magicSquare(int num);

int main()
{
	int num;
	cout << "This program creates a magic square of an odd order." << endl;
	cout << "Please enter a positive odd integer n for an n x n magic square:" << endl;
	cin >> num;
	while (cin.fail() || num < 0 || num % 2 == 0)
	{
		cout << "Please try again:" << endl;
		cin >> num;
	}
	magicSquare(num);
	system("pause");
}

void magicSquare(int num)
{
	int count = num * num;								//count is the largest number in the square.
	int counter = 0;									//counter sets the printing width of each number.
	int row = num - 1;									//we initialize row to the last row.
	int col = ((num - 1) / 2);							//we initialize col to the middle column.
	int** arr = new int*[num];							//arr is the 2-dimensional array storing the magic square.
	for (int i = 0; i < num; i++)
		arr[i] = new int[num];
	for (int i = 0; i < num; i++)						//This loop initializes all positions in the array to 0.
	{
		for (int j = 0; j < num; j++)
		{
			arr[i][j] = 0;
		}
	}
	arr[row][col] = 1;									//We place 1 in the midle of the bottom row.
	for (int i = 1; i < count; i++)
	{
		while (arr[row][col] > 0){
			if (row + 1 > num - 1 && col + 1 > num - 1) row = row - 1;
			else {
				if (row + 1 > num - 1) row = 0;
				else row = row + 1;
				if (col + 1 > num - 1) col = 0;
				else col = col + 1;
				if (arr[row][col] > 0)
				{
					if (row == 0) row = num - 1;
					else row = row - 1;
					if (col == 0) col = num - 1;
					else col = col - 1;
					row = row - 1;
				}
			}
		}
		arr[row][col] = i + 1;
	}
	while (count > 10)
	{
		count = count / 10;
		counter++;
	}
	for (int i = 0; i < num; i++)						//This loop prints out the magic square.
	{
		for (int j = 0; j < num; j++)
		{
			cout << setw(counter+2) << left << arr[i][j];
		}
		cout << endl;
	}

	for (int i = 0; i < num; i++)						//This loop deletes the array.
		delete[] arr[i];
	delete[] arr;

}
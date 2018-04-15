#include <iostream>

using namespace std;

void magicSquare(int num);

int main()
{
	magicSquare(5);
}

void magicSquare(int num)
{
	int** arr = new int*[num];
	for (int i = 0; i < num; i++)
		arr[i] = new int[num];
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			arr[i][j] = 0;
		}
	}
	int count = num*num;
	int row = num - 1;
	int col = ((num - 1) / 2) + 1;
	arr[row][col] = 1;
	for (int i = 1; i < count; i++)
	{
		while (arr[row][col] > 0){
			if (row + 1 > num - 1 && col + 1 > num - 1) row = row - 1;
			else {
				if (row + 1 > num - 1) row = 0;
				else row = row + 1;
				if (col + 1 > num - 1) col = 0;
				else col = col + 1;
				if (arr[row + 1][col + 1] > 0)
				{
					if (row = 0) row = num - 1;
					else row = row - 1;
					if (col = 0) row = num - 1;
					else col = col - 1;
					row = row - 1;
				}
			}
		}
		arr[row][col] = i + 1;
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}

	for (int i = 0; i < num; i++)
		delete[] arr[i];
	delete[] arr;

}
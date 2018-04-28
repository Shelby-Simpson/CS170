#include <iostream>

using namespace std;

int main()
{
	char string1[30] = {};
	char string2[30] = {};
	char string3[30] = {};
	char *arr[45] = {};
	int count = 0;
	bool spaceTest = false;
	cout << "Please enter 3 lines of text that are at most 30 characters long each(^Z to end early...noob):" << endl;
	cin.getline(string1,30);
	cin.getline(string2,30);
	cin.getline(string3,30);
	int string1Length = strlen(string1);
	int string2Length = strlen(string2);
	int string3Length = strlen(string3);
	cout << string1Length << string2Length << string3Length << endl;

	if (!isspace(string1[0]))
	{
		arr[count] = &string1[0];
		count++;
	}
	for (int i = 1; i < 30; i++)
	{
		if (isspace(string1[i]))
		{
			spaceTest = true;
			continue;
		}
		else
		{
			if (spaceTest)
			{
				arr[count] = &string1[i];
				count++;
				spaceTest = false;
			}

		}
	}
	if (!isspace(string2[0]))
	{
		arr[count] = &string2[0];
		count++;
	}
	for (int i = 1; i < 30; i++)
	{
		if (isspace(string2[i]))
		{
			spaceTest = true;
			continue;
		}
		else
		{
			if (spaceTest)
			{
				arr[count] = &string2[i];
				count++;
				spaceTest = false;
			}

		}
	}
	if (!isspace(string3[0]))
	{
		arr[count] = &string3[0];
		count++;
	}
	for (int i = 1; i < 30; i++)
	{
		if (isspace(string3[i]))
		{
			spaceTest = true;
			continue;
		}
		else
		{
			if (spaceTest)
			{
				arr[count] = &string3[i];
				count++;
				spaceTest = false;
			}

		}
	}
	for (int i = 0; i < count; i++)
	{
		cout << *arr[i] - *arr[i+1] << " ";
	}
	system("pause");

	/*
	int lineCount = 0;
	bool spaceTest = true;
	char ** arr = new char *[45];
	cout << "Please enter 3 lines of text that are at most 30 characters long each(^Z to end early...noob):" << endl;
	
	while (true)
	{
		cin.getline(arr[43], 30);
		if (cin.eof()) break;
		cin.getline(arr[44], 30);
		if (cin.eof()) break;
		cin.getline(arr[45], 30);
	}
	for (int i = 0; i < 45; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if (isspace(j))
			{
				spaceTest = true;
				break;
			}
			else
			{
				spaceTest = false;
				arr[i][count] = j;
			}
			if (!spaceTest) count++;
		}
	}*/
}




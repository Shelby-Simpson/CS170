#include <iostream>

using namespace std;

int main()
{
	char string1[30] = {};
	char string2[30] = {};
	char string3[30] = {};
	char *arr[45] = {};
	int word[45] = {};
	int count = 0, letter = 0;
	bool spaceTest = false;
	cout << "Please enter 3 lines of text that are at most 30 characters long each(^Z to end early...noob):" << endl;
	cin.getline(string1,30);
	cin.getline(string2,30);
	cin.getline(string3,30);
	int string1Length = strlen(string1);
	int string2Length = strlen(string2);
	int string3Length = strlen(string3);
	cout << string1Length << string2Length << string3Length << endl;

	if (strlen(string1) > 0){
		if (!isspace(string1[0]))
		{
			arr[count] = &string1[0];
			count++;
			letter++;
		}
		for (unsigned int i = 1; i < strlen(string1); i++)
		{
			if (isspace(string1[i]))
			{
				word[count - 1] = letter;
				letter = 0;
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
				letter++;
			}
			
		}
	}

	if (strlen(string2) > 0){
		letter = 0;
		if (!isspace(string2[0]))
		{
			arr[count] = &string2[0];
			count++;
			letter++;
		}
		for (unsigned int i = 1; i < strlen(string2); i++)
		{
			if (isspace(string2[i]))
			{
				word[count - 1] = letter;
				letter = 0;
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
	}
	
	if (strlen(string1) > 0){
		letter = 0;
		if (!isspace(string3[0]))
		{
			arr[count] = &string3[0];
			count++;
			letter++;
		}
		for (unsigned int i = 1; i < strlen(string3); i++)
		{
			if (isspace(string3[i]))
			{
				word[count - 1] = letter;
				letter = 0;
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
	}
	for (int i = 0; i < count; i++)
	{
		cout << *arr[i] << " ";
	}

	for (int i = 0; i < count; i++)
	{
		cout << word[i] << " ";
	}

	system("pause");

}




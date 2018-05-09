/*Problem1
  Assignment 3
  Shelby Simpson
  5/8/2018
  This program asks the user to input 3 lines of text (at most 30 characters each), sorts the inputted words alphabetically,
  and prints the count of how many times each word was inputted by the user.*/

#include <iostream>

using namespace std;

int compare_function(const void *name1, const void *name2);

int main()
{

	char string1[30] = {};									//There is one cstring per line of text the user can input.
	char string2[30] = {};
	char string3[30] = {};
	char *arr[45] = {};										//arr stores pointers to each first letter
	char wordComparer[30], wordComparerTemp[30];			//There char arrays are used to find the count of words
	int wordCounter = 0, letterCounter = 0;
	int count = 0;
	bool spaceTest = false;


	cout << "Please enter 3 lines of text that are at most 30 characters long each(^Z to end early):" << endl;
	cin.getline(string1,30);
	cin.getline(string2,30);
	cin.getline(string3,30);

	/*The following for loop creates a pointer to the beginning of each word in the first line of text.
	There is a condition in the beginning to test the first character in the line.*/
	if (strlen(string1) > 0){
		if (!isspace(string1[0]))
		{
			string1[0] = tolower(string1[0]);
			arr[count] = &string1[0];
			count++;
		}
		for (unsigned int i = 1; i < strlen(string1); i++)
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
					string1[i] = tolower(string1[i]);
					arr[count] = &string1[i];
					count++;
					spaceTest = false;
				}
			}
			
		}
	}

	/*The following for loop creates a pointer to the beginning of each word in the second line of text.
	There is a condition in the beginning to test the first character in the line.*/
	if (strlen(string2) > 0){
		if (!isspace(string2[0]))
		{
			string2[0] = tolower(string2[0]);
			arr[count] = &string2[0];
			count++;
		}
		for (unsigned int i = 1; i < strlen(string2); i++)
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
					string2[i] = tolower(string2[i]);
					arr[count] = &string2[i];
					count++;
					spaceTest = false;
				}
			}
		}
	}

	/*The following for loop creates a pointer to the beginning of each word in the third line of text.
	There is a condition in the beginning to test the first character in the line.*/
	if (strlen(string3) > 0){
		if (!isspace(string3[0]))
		{
			string3[0] = tolower(string3[0]);
			arr[count] = &string3[0];
			count++;
		}
		for (unsigned int i = 1; i < strlen(string3); i++)
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
					string3[i] = tolower(string3[i]);
					arr[count] = &string3[i];
					count++;
					spaceTest = false;
				}
			}
		}
	}

	qsort(arr,count,sizeof(char *),compare_function);						//qsort sorts the words into alphabetical order.
	
	cout << endl;

	/*The following for loop compares the words to see if there are more than one of each and prints the words.*/
	for (int i = 0; i < count; i++)
	{
		while ((*arr[i]) != ' ' && (*arr[i]) != '\0')
		{
			wordComparer[letterCounter] = *arr[i];
			arr[i] = arr[i] + 1;
			letterCounter++;
		}
		if (i == 0)
		{
			for (int index = 0; index < letterCounter; index++)
			{
				cout << wordComparer[index];
			}
			cout << endl;
			wordCounter++;
		}
		else
		{
			for (int k = 0; k < letterCounter; k++)
			{
				if (wordComparerTemp[k] != wordComparer[k])
				{
					cout << "Total count " << wordCounter << '\n' << endl;
					for (int index = 0; index < letterCounter; index++)
					{
						cout << wordComparer[index];
					}
					cout << endl;
					wordCounter = 0;
					break;
				}
			}
			wordCounter++;
		}
		for (int l = 0; l < sizeof(wordComparerTemp); l++)
		{
			wordComparerTemp[l] = '\0';
		}
		for (int j = 0; j < letterCounter; j++)
		{
			wordComparerTemp[j] = wordComparer[j];
		}
		letterCounter = 0;
	}
	cout << "Total count " << wordCounter << '\n' << endl;
	system("pause");

}

/*The compare_function is used by qsort to compare the words.*/
int compare_function(const void *name1, const void *name2)
{
	const char *name1_ = *(const char **)name1;
	const char *name2_ = *(const char **)name2;
	return strcmp(name1_, name2_);
}




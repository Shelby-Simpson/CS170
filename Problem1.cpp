/*Problem1
  Assignment 2
  Shelby Simpson
  4/11/2018
  This program uses functions with variable numbers of arguments consisting of a sequence of type double numbers.
  The program then checks if the sequence is in ascending order.
  If the program is in ascending order, the program returns true.
  If not, the user is asked if they would like the sequence to be sorted into order.*/

#include <iostream>
#include <cstdarg>
#include <vector>
using namespace std;

bool ordered(int count, double seq1 ...);					//The ordered function checks if the sequence is in ascending order.
					
void bubbleSort(vector<double> &sequence, int count);		//The bubbleSort function sorts the sequence into ascending order using the bubble sort algorithm.


int main(){
	cout << "This program checks if a sequence of numbers is in ascending order." << endl;
	system("pause");
	cout << ordered(3, 5.0, 6.0, 5.0) << endl;				//This call tests the program if the sequence is not in ascending order.  
	cout << ordered(4, 1.0, 2.0, 2.3, 3.5) << endl;			//This call tests the program if the sequence is already in ascending order.  
	cout << ordered(1, 1.0) << endl;						//This call tests the program if there is only one number in the sequence.
}

/*This is the ordered function.  
  It creates two identical variable lists from the function arguments.
  One list is used to test if the sequence is in ascending order.
  The other list is pushed into a vector which becomes an argument of the bubbleSort function.*/

bool ordered(int count, double seq1 ...)					  
{
	va_list sequence, sequence2;
	va_start(sequence, count);
	va_copy(sequence2, sequence);
	va_start(sequence2, count);
	char answer;
	double temp1, temp2;
	vector<double> sequenceVector;
	if (count <= 1) return true;
	else {
		temp1 = va_arg(sequence, double);
		temp2 = va_arg(sequence, double);
		for (int i = 2; i <= count; i++)
		{
			if (temp1 > temp2)
			{
				cout << "The sequence is not in the correct order.\n"
					<< "Would you like to sort it? (Y/N)\n";
				cin >> answer;

				if (cin.fail() || (toupper(answer) != 'Y' && toupper(answer) != 'N')) 
				{
					while (cin.fail() || (toupper(answer) != 'Y' && toupper(answer) != 'N')) 
					{
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "Please enter Y for yes or N for no.\n";
						cin >> answer;
					}
				}
			    if (toupper(answer) == 'Y') 
				{
					for (int i = 0; i < count; i++)
					{
						sequenceVector.push_back(va_arg(sequence2, double));    //The vector sequenceVector is created for the bubbleSort function.
					}
					bubbleSort(sequenceVector, count);
					cout << "\n";
					return true;
				}
				else if (toupper(answer) == 'N') return false;
				else {
					cout << "There was an error. ";
					return false;
				}

				
			}
			else {
				temp1 = temp2;
				temp2 = va_arg(sequence, double);
			}	
		}
		return true;
	}
}

/*This is the bubbleSort function.
  It uses the bubble sort algorithm to sort the sequence into ascending order.
  The sequence was pushed into the vector sequenceVector and it is passed as an argument to the bubbleSort function.*/

void bubbleSort(vector<double> &sequence, int count)
{
	int endLoc, index;
	double temp;
	for (endLoc = count - 1; endLoc >= 0; endLoc--)
	{
		bool swapped = false;
		for (index = 0; index < endLoc; index++)
			if (sequence[index] > sequence[index + 1]) 
			{
				// swap the values at index and index + 1
				temp = sequence[index];
				sequence[index] = sequence[index + 1];
				sequence[index + 1] = temp;
				// and note that there was a swap
				swapped = true;
			}
		if (!swapped)
			break;
	}
	for (int i = 0; i < count; i++) 
	{
		cout << sequence[i] << ", ";						//The sorted sequence is printed.  
	}
}
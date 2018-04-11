#include <iostream>
#include <cstdarg>
#include <vector>
using namespace std;

bool ordered(int count, double seq1 ...);
bool sort(int count, double seq1 ...);

int main(){
	cout << ordered(3, 5.0, 6.0, 7.0) << endl;
	cout << ordered(5, 3.0, 6.0, 8.2) << endl;
	cout << ordered(2, 5.0, 6.0) << endl;
	cout << ordered(2, 5, 6.0) << endl;
	system("pause");
}

bool ordered(int count, double seq1 ...){
	va_list sequence;
	va_start(sequence, count);
	char answer;
	double temp1, temp2;
	vector<double> sequenceVector;
	if (count <= 1) return true;
	else {
		temp1 = va_arg(sequence, double);
		temp2 = va_arg(sequence, double);
		for (int i = 2; i <= count; i++){
			if (temp1 > temp2) {
				cout << "The sequence is not in the correct order.\n"
					<< "Would you like to sort it? (Y/N)\n";
				cin >> answer;
				while (cin.fail()) {
					cin.clear();
					cin.ignore(10000, '\n');
					"Please enter Y for yes or N for no.\n";
					cin >> answer;
				}
				if (answer == 'Y') {
					for (int i = 0; i <= count; i++) {
						sequenceVector.push_back(i);
					}
					bubbleSort(&sequenceVector, count);
				}
			}
			else {
				temp1 = temp2;
				temp2 = va_arg(sequence, double);
			}
			return true;
		}
	}
}

void bubbleSort(vector<double> &sequence, int count)
{
	int endLoc, index, temp;
	for (endLoc = count - 1; endLoc >= 0; endLoc--)
	{
		bool swapped = false;
		for (index = 0; index < endLoc; index++)
			if (sequence[index] > sequence[index + 1]) {
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
	for (int i = 0; i <= count; i++) {
		cout << sequence[i] << ", ";
	}
}
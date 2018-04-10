#include <iostream>
#include <cstdarg>
#include <vector>
using namespace std;

bool ordered(int num, double seq1 ...);

int main(){
	cout << ordered(3, 5, 6, 7) << endl;
	system("pause");
}

bool ordered(int num, double seq1 ...){
	va_list sequence;
	va_start(sequence, num);
	double temp1, temp2;
	if (num <= 1) return true;
	else {
		temp1 = va_arg(sequence, double);
		temp2 = va_arg(sequence, double);
		for (int i = 0; i <= num; i++){
			if (temp1 > temp2) return false;
			else {
				temp1 = temp2;
				temp2 = va_arg(sequence, double);
			}
			return true;
		}
	}
}
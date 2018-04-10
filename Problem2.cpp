#include <iostream>
#include <vector>

using namespace std;

void plot(double num);
int sumSequence(vector<double> &vec);

int main(){
	vector<double> sequence;
	double temp;
	for (int i = 0; i >= 0; i++){
		cout << "Please enter integer " << i + 1 << " in the sequence: \n(Enter anything other than an integer to end)\n" << endl;
		cin >> temp;
		if (cin.fail()) break;
		else sequence.push_back(temp);
	}
	plot(sumSequence(sequence));
	system("pause");
}

int sumSequence(vector<double> &vec){
	int sum = 0;
	double size = vec.size() - 1;
	for (int i = 0; i <= (int) size; i++){
		sum = sum + (int) vec[i];
	}
	return sum;
}
void plot(double num){
	double numAst = num * 10;
	for (int i = 1; i <= (int) numAst; i++){
		cout << "*";
	}
	return;
}
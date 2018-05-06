#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Tool
{
	int record;
	char name[20];
	int quantity;
	float cost;
};

int position(Tool tool);
istream& operator >> (istream& in, Tool tool);
ostream& operator << (ostream& out, Tool tool);

int main()
{
	char deleteTool[20], updateTool[20];
	int input, input2, count = 0;
	Tool createTool = { 0, '\0', 0, 0 };
	Tool tempTool;
	fstream toolRecord;
	toolRecord.open("hardware.dat", ios::in | ios::out | ios::binary | ios::trunc);
	
	if (!toolRecord)
    {
        cout << "\nCannot open Tool Record";
    	exit(1);
    }
	
	Tool toolEmpty = {0, '\0', 0, 0};
	
	for (int i = 0; i < 100; i++)
	{
		toolRecord.write((char*) &toolEmpty, sizeof(toolEmpty));
	}
	
	Tool wrench = {83, "Wrench", 34, 7.50};
	Tool electricSander = {3, "Electric Sander", 7, 57.98};
	Tool hammer = {17, "Hammer", 76, 11.99};
	Tool jigSaw = {24, "Jig Saw", 21, 11.00};
	Tool lawnMower = {39, "Lawn Mower", 3, 79.50};
	Tool powerSaw = {56, "Power Saw", 18, 99.99};
	Tool screwdriver = {68, "Screwdriver", 106, 6.99};
	Tool sledgeHammer = {77, "Sledge Hammer", 11, 21.50};
	
	toolRecord.seekp(0, ios::beg);
	toolRecord.seekp(position(wrench), ios::beg);
	toolRecord.write((char*) &wrench, sizeof(wrench));
	count++;
	toolRecord.seekp(position(electricSander), ios::beg);
	toolRecord.write((char*) &electricSander, sizeof(electricSander));
	count++;
	toolRecord.seekp(position(hammer), ios::beg);
	toolRecord.write((char*) &hammer, sizeof(hammer));
	count++;
	toolRecord.seekp(position(jigSaw), ios::beg);
	toolRecord.write((char*) &jigSaw, sizeof(jigSaw));
	count++;
	toolRecord.seekp(position(lawnMower), ios::beg);
	toolRecord.write((char*) &lawnMower, sizeof(lawnMower));
	count++;
	toolRecord.seekp(position(powerSaw), ios::beg);
	toolRecord.write((char*) &powerSaw, sizeof(powerSaw));
	count++;
	toolRecord.seekp(position(screwdriver), ios::beg);
	toolRecord.write((char*) &screwdriver, sizeof(screwdriver));
	count++;
	toolRecord.seekp(position(sledgeHammer), ios::beg);
	toolRecord.write((char*) &sledgeHammer, sizeof(sledgeHammer));
	count++;
	
	toolRecord.seekg(0, ios::beg);
	while (toolRecord.read((char *) &tempTool, 32))
	{
		if (tempTool.record == 0) continue;
		else 
		{
			cout << tempTool << endl;
		}
	}
	Tool tempTool2 = { 0, '\0', 0, 0 };
	
	
	cout << "Please select an option:" << endl;
	cout << "1. Create Records" << endl;
	cout << "2. Read Records" << endl;
	cout << "3. Update Records" << endl;
	cout << "4. Delete Records" << endl;
	cin >> input;
	
	switch (input)
	{
		case 1: 
			cout << "Create Records" << endl;
			cout << "Please enter the values of the record you would like to create. \n"
			<< "(Record Number) (Name <= 20 characters) (Quantity) (Cost)" << endl;
			cin >> createTool;
			toolRecord.write((char*) &createTool, (sizeof(createTool)));
			count++;
		case 2: 
			cout << "Read Records" << endl;
			
		case 3: 
		cout << "Update Records" << endl;
		cout << "Please enter the name of the tool whose record you would like to update:" << endl;
		cin >> updateTool;
		toolRecord.seekg(0, ios::beg);
		while (toolRecord.read((char *)&tempTool2, 32))
		{
			if (tempTool.name == updateTool) 
			{
				cout << "Please select which field you would like to edit:" << endl;
				cout << "1. Record number" << endl;
				cout << "2. Name" << endl;
				cout << "3. Quantity" << endl;
				cout << "4. Cost" << endl;
				cin >> input2;

				switch (input2)
				{
				case 1:
					cout << "Update record number" << endl;
					cout << "Please enter the new value of the record number:" << endl;
					cin >> tempTool2.record;
				case 2:
					cout << "Update tool name" << endl;
					cout << "Please enter the new value of the tool name (<= 20 characters):" << endl;
					cin >> tempTool2.name;
				case 3:
					cout << "Update quantity" << endl;
					cout << "Please enter the new quantity:" << endl;
					cin >> tempTool2.quantity;
				case 4:
					cout << "Update cost" << endl;
					cout << "Please enter the new cost:" << endl;
					cin >> tempTool2.cost;
				}
			}
			else continue;
		}
		break;
		case 4: 
		cout <<  "Delete Records" << endl;
		cout << "Please enter the name of the tool you would like to remove:" << endl;
		cin >> deleteTool;
		toolRecord.seekg(0, ios::beg);
		while (toolRecord.read((char *) &tempTool, 32))
		{
			if (tempTool.name == deleteTool)
				tempTool = { 0, '\0', 0, 0 };
		}
		
	}
	toolRecord.seekg(0, ios::beg);
	while (toolRecord.read((char *)&tempTool, 32))
	{
		if (tempTool.record == 0) continue;
		else
		{
			cout << tempTool << endl;
		}
	}
	system("pause");
}

int position(Tool tool)
{
	int value = tool.record*32;
	return value;
}
istream& operator >> (istream& in, Tool tool)
{
	in >> tool.record >> tool.name >> tool.quantity >> tool.cost;
	return in;
}

ostream& operator << (ostream& out, Tool tool)
{
	out << left << setw(4) << tool.record << setw(20) << tool.name 
	<< setw(4) << tool.quantity << setw(7) << tool.cost << endl;
	return out;
}
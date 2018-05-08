#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

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
	int input, input2, size = 0, oldRecord;;
	char mainMenu;
	bool tryAgain = true;
	Tool createTool = { 0, '\0', 0, 0 };
	Tool tempTool;
	fstream toolRecord;
	toolRecord.open("hardware.dat", ios::in | ios::out | ios::binary);
	
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
	
	toolRecord.seekp(position(wrench) - sizeof(wrench), ios::beg);
	toolRecord.write((char*) &wrench, sizeof(wrench));
	
	toolRecord.seekp(position(electricSander) - sizeof(electricSander), ios::beg);
	toolRecord.write((char*) &electricSander, sizeof(electricSander));
	
	toolRecord.seekp(position(hammer) - sizeof(hammer), ios::beg);
	toolRecord.write((char*) &hammer, sizeof(hammer));
	
	toolRecord.seekp(position(jigSaw) - sizeof(jigSaw), ios::beg);
	toolRecord.write((char*) &jigSaw, sizeof(jigSaw));
	
	toolRecord.seekp(position(lawnMower) - sizeof(lawnMower), ios::beg);
	toolRecord.write((char*) &lawnMower, sizeof(lawnMower));
	
	toolRecord.seekp(position(powerSaw) - sizeof(powerSaw), ios::beg);
	toolRecord.write((char*) &powerSaw, sizeof(powerSaw));
	
	toolRecord.seekp(position(screwdriver) - sizeof(screwdriver), ios::beg);
	toolRecord.write((char*) &screwdriver, sizeof(screwdriver));
	
	toolRecord.seekp(position(sledgeHammer) - sizeof(sledgeHammer), ios::beg);
	toolRecord.write((char*) &sledgeHammer, sizeof(sledgeHammer));
	
	
	
	while (tryAgain)
	{
		cout << "Please select an option:" << endl;
		cout << "1. Read Records" << endl;
		cout << "2. Update Records" << endl;
		cout << "3. Delete Records" << endl;
		cin >> input;
		
		switch (input)
		{
			case 1: 
				cout << "Read Records" << endl;
				toolRecord.seekg(0, ios::end);
			size = (int)toolRecord.tellg();
			toolRecord.seekg(0, toolRecord.beg);
			while (toolRecord.tellg() < size)
			{
				toolRecord.read((char *) &tempTool.record, sizeof(tempTool.record));
				toolRecord.read((char *) &tempTool.name, sizeof(tempTool.name));
				toolRecord.read((char *) &tempTool.quantity, sizeof(tempTool.quantity));
				toolRecord.read((char *) &tempTool.cost, sizeof(tempTool.cost));
				if (tempTool.record == 0) continue;
				else cout << tempTool << endl;
			}
			break;
				
			case 2: 
			cout << "Update Records" << endl;
			cout << "Please enter the name of the tool whose record you would like to update:" << endl;
			cin >> updateTool;
			toolRecord.seekg(0, ios::end);
			size = (int)toolRecord.tellg();
			toolRecord.seekg(0, toolRecord.beg);
			while (toolRecord.tellg() < size)
			{
				toolRecord.read((char *) &tempTool.record, sizeof(tempTool.record));
				toolRecord.read((char *) &tempTool.name, sizeof(tempTool.name));
				toolRecord.read((char *) &tempTool.quantity, sizeof(tempTool.quantity));
				toolRecord.read((char *) &tempTool.cost, sizeof(tempTool.cost));
				if ((string)tempTool.name == (string)updateTool)
				{
					toolRecord.seekp(-32, toolRecord.cur);
					cout << "Please select which field you would like to edit:" << endl;
					cout << "1. Record number" << endl;
					cout << "2. Name" << endl;
					cout << "3. Quantity" << endl;
					cout << "4. Cost" << endl;
					cin >> input2;

					switch (input2)
					{
					case 1:
						oldRecord = tempTool.record;
						cout << "Update record number" << endl;
						cout << "Please enter the new value of the record number:" << endl;
						cin >> tempTool.record;
						toolRecord.seekp(tempTool.record*32, ios::beg);
						toolRecord.write((char *) &tempTool.record, sizeof(tempTool.record));
						toolRecord.write((char *) &tempTool.name, sizeof(tempTool.name));
						toolRecord.write((char *) &tempTool.quantity, sizeof(tempTool.quantity));
						toolRecord.write((char *) &tempTool.cost, sizeof(tempTool.cost));
						tempTool = {0, '\0', 0, 0};
						toolRecord.seekp((oldRecord*32) - sizeof(tempTool), ios::beg);
						toolRecord.write((char *) &tempTool, sizeof(tempTool));
						cout << updateTool << " has been updated." << endl;
						break;
					case 2:
						cout << "Update tool name" << endl;
						cout << "Please enter the new value of the tool name (<= 20 characters):" << endl;
						cin >> tempTool.name;
						toolRecord.write((char *) &tempTool, sizeof(tempTool));
						cout << updateTool << " has been updated." << endl;
						break;
					case 3:
						cout << "Update quantity" << endl;
						cout << "Please enter the new quantity:" << endl;
						cin >> tempTool.quantity;
						toolRecord.write((char *) &tempTool, sizeof(tempTool));
						cout << updateTool << " has been updated." << endl;
						break;
					case 4:
						cout << "Update cost" << endl;
						cout << "Please enter the new cost:" << endl;
						cin >> tempTool.cost;
						toolRecord.write((char *) &tempTool, sizeof(tempTool));
						cout << updateTool << " has been updated." << endl;
						break;
					}
					break;
				}
				else continue;
			}
			
			break;
			case 3: 
			cout <<  "Delete Records" << endl;
			cout << "Please enter the name of the tool you would like to remove:" << endl;
			cin >> deleteTool;
			toolRecord.seekg(0, ios::end);
			size = (int)toolRecord.tellg();
			toolRecord.seekg(0, toolRecord.beg);
			while (toolRecord.tellg() < size)
			{
				toolRecord.read((char *) &tempTool.record, sizeof(tempTool.record));
				toolRecord.read((char *) &tempTool.name, sizeof(tempTool.name));
				toolRecord.read((char *) &tempTool.quantity, sizeof(tempTool.quantity));
				toolRecord.read((char *) &tempTool.cost, sizeof(tempTool.cost));
				if ((string)tempTool.name == (string)deleteTool)
				{
					tempTool  = {0, '\0', 0, 0};
					toolRecord.seekp(-32, toolRecord.cur);
					toolRecord.write((char *) &tempTool, sizeof(tempTool));
					cout << deleteTool << " has been deleted." << endl;
				}
				else continue;
			}
			break;
		}
		cout << "Would like to go back to the main menu? (y/n)" << endl;
			cin >> mainMenu;
			if (tolower(mainMenu) == 'y')
			{
				tryAgain = true;
			}
			else tryAgain = false;
	}
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
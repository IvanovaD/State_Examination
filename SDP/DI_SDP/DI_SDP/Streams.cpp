#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;


ostream& pretty_hex(ostream& os)
{
	return os << setw(20) << left << setfill('_') << showbase;
}

int main()
{
cout  << hex << 42 << endl;
cout << showbase << hex << 42 << endl;
int n;
cin >> hex >> n;

cout << n << endl;
cout << pretty_hex << n << endl;

/*
	ofstream myFile;
	myFile.open("notExistingFile.txt");
	//myFile << "Writing output into the file\n";
	myFile.close(); //always close
	
	ifstream myFile2;
	myFile2.open("notExistingFile!.txt");
	if (myFile2.fail())
	{
		cerr << "Error opening file";
		system("pause");
		exit(1);
	}
	string item;
	int count = 0;
	while(!myFile2.eof())
	{
		myFile2 >> item;
		count++;
	}

	myFile2.close();*/
	system("pause");
}
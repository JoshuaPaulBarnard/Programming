#include<fstream> //ifstream, ofstream
#include<string> //string
#include<iostream> //cin, cout
using namespace std;

int main()
{
	//Start Variables//
	ifstream inputFile; //accepts file input
	ofstream outData; //writes to file
	char encodedText;
	string inputFileName; //user input file name
	int numOfChar = 0;
	//End Variables//


	//User specifies file name
	cout << "Enter the name of the file you would like to open: ";
	cin >> inputFileName; //accept file name from console


	//open files
	inputFile.open(inputFileName.c_str()); //opens user specified file
	outData.open("output.txt"); //creates a file named "output.txt"


	//convert to lower case and output to new file
	while (!inputFile.eof()) //loops until end of user specified file
	{
		inputFile.get(encodedText); //gets char from input file
		outData << (char)tolower(encodedText); //converts char to lowercase, outputs to outData file ("output.txt")
	}


	//close input file
	inputFile.close();
	outData.close();


	//Program finished
	cout << endl << "The program completed successfully." << endl;

	return 0;
}

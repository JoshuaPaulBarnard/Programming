#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//Struct definition
struct letterType
{
	char letter;
	int letterCount;
};

//Function to open I/O files
void openFile(ifstream& inFile, ofstream& outFile);

//Function to fill the array of structs and keep track of the amount of uppercase/lowercase letters
void count(ifstream& inFile, letterType letterList[], int& totalBig, int& totalSmall);

//Function to print the letters, the occurences, and the percentages
void printResult(ofstream& outFile, letterType letterList[], int totalBig, int totalSmall);

int main()
{
	ifstream input; //object to read the text
	ofstream output; //object to write the results
	int totalCapital = 0; //variable to store the total number of uppercase
	int totalLower = 0; //variable to store the total number of lowercase
	letterType letterObj[52]; //array of structs of type letterType to hold the information
	
	//Input and process data
	openFile(input, output);
	count(input, letterObj, totalCapital, totalLower);
	printResult(output, letterObj, totalCapital, totalLower);

	//Close files
	input.close();
	output.close();

	return 0;
}

void openFile(ifstream& inFile, ofstream& outFile)
{
	string inFileName;
	string outFileName;

	cout << "Enter the name of the input file: ";
	cin >> inFileName;
	inFile.open(inFileName.c_str());
	cout << endl;

	cout << "Enter the name of the output file: ";
	cin >> outFileName;
	outFile.open(outFileName.c_str());
	cout << endl;
}

void count(ifstream& inFile, letterType letterList[], int& totalBig, int& totalSmall)
{
	char ch;
	
	//Loop to initialize the array of structs; set letterCount to zero
	for(int index = 0; index < 26; index++)
	{
		//This segment sets the uppercase letters
		letterList[index].letter = static_cast<char>(65 + index);
		letterList[index].letterCount = 0;
		
		//This segment sets the lowercase letters
		letterList[index + 26].letter = static_cast<char>(97 + index);
		letterList[index + 26].letterCount = 0;
	}
	
	//read first character
	inFile >> ch;

	//Keep reading until end of file is reached
	while(!inFile.eof())
	{
		//If uppercase letter or lowercase letter is found, update data
		if('A' <= ch && ch <= 'Z')
		{
			letterList[static_cast<int>(ch) - 65].letterCount++;
			totalBig++;
		}
		else if('a' <= ch && ch <= 'z')
		{
			letterList[static_cast<int>(ch) - 71].letterCount++;
			totalSmall++;
		}
		
		//read the next character
		inFile >> ch;

	} //end while
} //end function

void printResult(ofstream& outFile, letterType letterList[], int totalBig, int totalSmall)
{
	outFile << fixed << showpoint << setprecision(2);
	outFile << "Letter    Occurences     Percentage" << endl;

	for(int index = 0; index < 52; index++)
	{
		if(0 <= index && index <= 25)
		{
			outFile << setw(4) << letterList[index].letter << setw(12) << letterList[index].letterCount << " ";
			outFile << setw(15) << 100 * (letterList[index].letterCount / static_cast<double>(totalBig)) << "%" << endl;
		}
		else
		{
			outFile << setw(4) << letterList[index].letter << setw(12) << letterList[index].letterCount << " ";
			outFile << setw(15) << 100 * (letterList[index].letterCount / static_cast<double>(totalSmall)) << "%" << endl;
		}
	} //end for
} //end function 

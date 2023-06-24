
#include<iostream.h>
#include<ctype.h>
#include<fstream.h>


#define NUM_LETTERS 26



// I have ch there to keep track of count i.e. which char has what count.

//check the last part of main where I am printing, you will get it.

struct Letter_Stats

{

	int count;

	char ch;

};



int main()

{

	ifstream inputfile;

	char ch;

	int i;

	Letter_Stats stats[NUM_LETTERS];

	inputfile.open("108.txt", ios::in);

	if (inputfile.fail())

	{

		cout << "error - bailing out";

		return 1;

	}

	//initialize the array of structures

	for (i = 0; i<NUM_LETTERS; i++)

	{

		stats[i].count = 0;

		stats[i].ch = ('a' + i);

	}

	//do till file ends

	while (!inputfile.eof())

	{
		inputfile.get(ch);

		//increment counter for appropriate character



		if ('a' <= tolower(ch) && tolower(ch) <= 'z')

			stats[ch - 'a'].count++;

	}

	inputfile.close();

	//print characters and count if it is more than 0

	for (i = 0; i<NUM_LETTERS; i++)

	{

		if (stats[i].count>0)

		{

			cout << stats[i].ch << " occured " << stats[i].count << " times" << endl;

		}

	}



	return 0;

}
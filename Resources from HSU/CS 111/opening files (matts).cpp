//---Matthew Mitchell
//---This finds median values of as set of numbers from a data file.
//---opening files.cpp

#include<iostream>
#include<fstream>
using namespace std;

void
sort(int array[], int count)
{
	int temp, i, outer;
	for(outer=1; outer<count; outer++)
	{
		for(i=0; i<count-1; i++)
		{
			if(array[i]>array[i+1])
			{
				temp = array[i];
				array[i] = array[i+1];
				array[i+1] = temp;
			}
		}
	
	}
	
}

float
median(int a[], int count)
{
	int middle; 
	int remainder;
	float middle1;
	
	  remainder = count % 2;
	if (remainder != 0)
	{
		middle = count / 2;
		middle = a[middle];
		return middle;
	}
	else
	{
		middle = count / 2;
		middle = a[middle] + a[middle-1];
		middle1 = (float)middle/(float)2;
		 
		 return middle1;
	}
}

int
main()
{
	float answer;
	int value, data[25], count, i;
	fstream datafile;
	datafile.open("data1.dat", ios::in);

	count = 0;
	i = 0;

	while(!datafile.eof())
	{
		datafile >> value;
		count++;
		data[i] = value;
		i++;
	}
	sort(data, count);

	answer = median(data, count);

	cout << "The median value for the data set is: " << answer;
	datafile.close();
	/*
	for(i=0; i<=count-1; i++)
	{
		cout << data[i] << " ";
	}
	*/	
	return 0;	
}

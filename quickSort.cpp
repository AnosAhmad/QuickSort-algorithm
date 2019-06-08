#include "utility.h"
#include "quickSort.h"
#include "Timerr.h"
#include <vector>

/**
* Trigger the sorting and compute the running time.
* @param first - The start of the sequence.
* @param last - The end of the sequence.
*/
void quickSort::triggerSort(int first, int last)
{
	timerobj.reset();
	quicksort(first, last);
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(3);
	cout << "\n*** Running Time is : " << runningTime << endl;
}

/**
* Quicksort.
* @param first - The start of the sequence.
* @param last - The end of the sequence.
*/
void quickSort::quicksort(int first, int last)
{
	int pivotElement;
	if (first < last)
	{
		pivotElement = partation(first, last);
		quicksort(first, pivotElement - 1);
		quicksort( pivotElement + 1, last);
	}
	else
	{
		runningTime = timerobj.elapsed_timee();	
		writeFile();
		
	}
}

/**
* Find and return the index of pivot element.
* @param first - The start of the sequence.
* @param last - The end of the sequence.
* @return - the pivot element index.
*/
int quickSort::partation(int first, int last)
{
	int pivot = arrayofint[last];
	int i = first - 1, temp;
	for (int j = first; j <= last - 1; j++)
	{
		if (arrayofint[j] <= pivot)
		{
			i = i + 1;
			temp = arrayofint[i];
			arrayofint[i] = arrayofint[j];
			arrayofint[j] = temp;
		}
	}
	temp = arrayofint[i+1];
	arrayofint[i+1] = arrayofint[last];
	arrayofint[last] = temp;
	return (i +1);
}

/**
* Check to sure that The vector of short int are sorted.
* @return - bool value.
*/
bool quickSort::SortCheck()
{
	bool sorted = true;
	for (int i = 0; i < arrayofint.size()-1; i++)
	{
		if(arrayofint[i] <= arrayofint[i+1])
		{
			continue;
		}
		else
		{
			sorted = false;
			break;
		}
	}
	return sorted;
}

/**
* Read the series of integers from the Text file
* @param filename - The file name which contains the integer numbers.
*/
void quickSort::read(string filename)
{
	/* Local variables */
	ifstream openfile;
	string linee;
	vector<short int> arrayofint;
	int num;

	/* Open the file and Check if it exists */
	openfile.open(filename);
	if (openfile.fail()) {
		std::cout << "No data file" << endl;
		exit(1);
	}
	/* If file exist in the Dir start reading */
	else {
		while (!openfile.eof()) {
			getline(openfile, linee);
			num = atoi(linee.c_str());
			arrayofint.push_back(num);
		}
		openfile.close();

		/* print out the Integer values */
		print();
	}
}

/**
* Print an array.
*/
void quickSort::print()
{
	std::cout << std::boolalpha;
	cout << SortCheck()<<"]"<<endl;
	cout << "\nA = [";
	for (int i = 0; i < arrayofint.size(); i++)
	{
		cout << "  " << arrayofint.at(i);
	}
	cout << " ]\n" << endl;
}

/**
* Set value for private memeber.
* @param arrayofint - The vector.
*/
void quickSort::setarrayofint(vector<short int> a)
{
	arrayofint.swap( a);
}

/**
* Write arrayofint values into a text file.
*/
void quickSort::writeFile()
{
	if (SortCheck())
	{
		ofstream myfile;
		myfile.open("Sorted_File.txt");
		for (int i = 0; i < arrayofint.size(); i++)
		{
			myfile << arrayofint[i] << "\n";
		}
		myfile.close();
	}
}
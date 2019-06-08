#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "utility.h"
#include <vector>
#include "Timerr.h"

class quickSort
{
public:
	void triggerSort(int first, int last);
	void quicksort(int first, int last);	
	int partation(int first, int last);
	bool SortCheck();	
	void read(string filename);
	void print();
	void writeFile();	
	void setarrayofint(vector<short int> a);

private:
	vector<short int> arrayofint;
	double runningTime;
	Timerr timerobj;
};

#endif //QUICKSORT_H
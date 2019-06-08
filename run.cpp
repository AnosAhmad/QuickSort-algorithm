# include"quickSort.h"
#include "utility.h"

void main()
{
	quickSort quicksortobj;
	vector<short int> A;
	srand(int(time(NULL)));
	for (int i = 0; i < 10; i++)
	{
		A.push_back( rand() % 20);
	}
	
	cout << "\n*** [A] Before sorting [";
	quicksortobj.setarrayofint(A);
	quicksortobj.print();

	quicksortobj.triggerSort(0, A.size() - 1);
	cout << "\n*** [A] After sorting [";	
	quicksortobj.print();
	
	
}
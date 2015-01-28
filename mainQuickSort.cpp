#include <iostream>

using namespace std;

int Partition(int* list, int start, int end)
{
	int pivort = 0;
	int i = 0;
	int j = 0;
	int x = 0;

	x = list[end];
	i = start - 1;

	for (j = start; j < end; j++)
	{
		if (list[j] < x)
		{
			i++;
			swap(list[i], list[j]);
		}
	}

	swap(list[i+1], list[end]);
	pivort = i + 1;

	return pivort;
}

void swap(int& a, int& b)
{
	int temp = 0;

	temp = a;
	a = b;
	b = temp;
}

void QuickSort(int* list, int start, int end)
{
	int pivort = 0;

	if (start < end)
	{
		pivort = Partition(list, start, end);
		QuickSort(list, start, pivort - 1);
		QuickSort(list, pivort + 1, end);
	}
	
}

void Print(int* list, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		cout << list[i] << " ";
	}
	cout << endl;
}

int main(void)
{
	int myList[20] = {-21, 2, 3, 5, 11, -1, 3, 9, 29, 33, 2, 1, 5, 99, 1, 7, 22, 556, 93, 10};
	int pivort = 0;
	int start = 0;
	int end = 19;

	cout << "Array before sorting: " << endl;
	Print(myList, end + 1);

	QuickSort(myList, start, end);

	cout << "Array after sorting" << endl;
	Print(myList, end + 1);

	
	return 0;
}
/*This is the optimised bubble sort program. For regular bubble sort, remove boolean variable from the bubbleSort() function*/
#include <iostream>
#include <limits>
#include <new>
using namespace std;

int integerInput();
int getSize();
void bubbleSort(int[], int);
void displayArray(int[], int);

int main()
{
	int size, * arr;

	cout << "Enter the size of the array: ";
	size = getSize();
	arr = new (nothrow) int[size];
	if (arr == nullptr)
	{
		cout << endl << "Failed to allocate memory! Please restart the application.";
		exit(0);
	}

	cout << endl << "Enter all the elements of the array: ";
	for (int i = 0; i < size; i++)
	{
		arr[i] = integerInput();
		cout << "Elements remaining to be entered: " << size - i - 1 << endl;
	}

	bubbleSort(arr, size);
	displayArray(arr, size);

	return 0;
}

int integerInput()
{
	int n;

	while (!(cin >> n))
	{
		cin.clear();
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
		cout << endl << "Invalid integer input! Please try again with correct input: ";
	}

	return n;
}

int getSize()
{
	int size = integerInput();

	if (size <= 0)
	{
		cout << endl << "Invalid size! Please try again: ";
		size = getSize();
	}

	return size;
}

void bubbleSort(int arr[], int size)
{
	int swap;
	bool isSorted;
	
	for (int i = 0; i < size; i++)
	{
		isSorted = true;
		for (int j = 0; j < size - 1 - i; j++)	// Size - 1 - i because in each iteration you have moved the largest value to the end of the array and you no longer need to iterate all the way to end of the array
		{
			if (arr[j] > arr[j + 1])
			{
				isSorted = false;
				swap = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = swap;
			}
		}
		if (isSorted)		// Exiting the loop as soon as the array is sorted
			break;
	}
}

void displayArray(int arr[], int size)
{
	cout << endl << "The sorted array is: ";

	for (int i = 0; i < size; i++)
	{
		cout << "|" << arr[i] << "|";
	}
}
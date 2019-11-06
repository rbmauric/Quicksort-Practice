//Ryan Mauricio
//Quicksort Practice
//10/25/19

#include <iostream>
using namespace std;

void swap(int *a, int *b); //swap two elements of an array
int partition(int *myarray, int l, int h); //find the partition element
void quickSort(int *myarray, int l , int h); //sort the array

int main() {
	int myarray[5];
	int part = 0;

	cout << "Enter 5 integers for the array: ";
	for (int i = 0; i < 5; i++)
		cin >> myarray[i];

	cout << "\nThe array is: ";
	for (int i = 0; i < 5; i++)
		cout << myarray[i] << " ";

	quickSort(myarray, 0, 5);

	cout << "\nThe sorted array is: ";

	for (int i = 0; i < 5; i++)
		cout << myarray[i] << " ";

	return 0;
}

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int *myarray, int l, int h) {
	int pivot = myarray[l];
	int a = l;
	int b = h;

	while (a < b) {
		do
			a++; 
		while (myarray[a] <= pivot);

		do
			b--;
		while (myarray[b] > pivot);

		if (a < b)
			swap(myarray[a], myarray[b]);
	}
	
	swap(myarray[l], myarray[b]);
	return b;
}	

void quickSort(int* myarray, int l, int h) {
	if (l < h) {
		int j = partition(myarray, l, h);
		quickSort(myarray, l, j);
		quickSort(myarray, j + 1, h);
	}
}
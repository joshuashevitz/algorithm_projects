#include <iostream>
#include <ctime>
#include <cmath>
#include <chrono>
#include "quicksort.h"

using namespace std;

void print(int arr[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
void swap(int* a, int* b) {
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
int partition(int arr[], int low, int high) {
		int j, i = low + 1;

		for (j = low + 1; j < high; j++)
		{
			
			if (arr[j] <= arr[low])
			{
				swap(arr[j], arr[i]);
				i++;
			}
		}
		swap(arr[i - 1], arr[low]);
		return i;
}

void quicksort(int arr[], int low, int high) {
	if (low < high) {
		int part = partition(arr, low, high);
		quicksort(arr, low, part - 1);
		quicksort(arr, part + 1, high);
	}
}

int main() {
	time_t start, end;
	int size, n, power1, power2, range;
	cout << "10 to what power for size? only choose between 2 and 6 inclusive: " << endl;
	cin >> power1;
	size = pow(10, power1);
	cout << "10 to what power for range? only choose between 2 and 12 inclusive: " << endl;
	cin >> power2;
	range = pow(10, power2);
	int* arr = (int*)malloc(size * sizeof(int)); 
	double takentime;

	srand(time(0));

	for (int i = 0; i < size; i++) {
		arr[i] = rand() % range+1;
		
	}
	time(&start);
	quicksort(arr, 0, size-1);
	
	time(&end);
	//print(arr, size);
	takentime = double(end - start);
	cout << "total time: " << fixed << takentime << "seconds: " <<  end;
}
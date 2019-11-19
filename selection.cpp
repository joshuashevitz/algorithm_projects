#include <iostream>
#include <cmath> 
#include <time.h>

using namespace std;
void print(int arr[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	 
	for (i = 0; i < n - 1; i++)
	{  
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		
		swap(&arr[min_idx], &arr[i]);
	}
}

int main() {
	time_t start, end;
	int size, power1, range, power2;
	cout << "enter exponent for size: " << endl;
	cin >> power1;
	cout << "enter exponent for range " << endl;
	cin >> power2;
	size = pow(10, power1);
	range = pow(10, power2);
	int *arr = (int *)malloc(size * sizeof(int));
	srand(time(0));
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % range + 1;
	}

	time(&start);
	selectionSort(arr, size);
	time(&end);
	print(arr, size);
	int timetaken = double(end - start);
	cout << "time taken: " << fixed << timetaken << " seconds" << endl;
	
	system("pause");
	return 0;
}
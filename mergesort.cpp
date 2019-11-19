#include <iostream> 
#include <cmath>
#include <ctime>
#include <chrono>

using namespace std;

void merge(int arr[], int left, int right, int *temp) {
	if (right == left + 1) { 
		return;
	}
	else {
		int i = 0; 
		int length = (right - left);
		int m = length / 2;
		int l = left;
		int r = l + m;
		merge(arr, l, r, temp);
		merge(arr, r, right, temp);
		for (i = 0; i < length; i++) {
			if (l < left + m && (r == right || arr[r] > arr[l])) {
				temp[i] = arr[l]; 
					l++;
			}
			else {
				temp[i] = arr[r];
				r++;
			}
		}
		for (i = left; i < right; i++) {
			arr[i] = temp[i - left];
		}
	}
}

int mergesort(int arr[],int size) {
	
	int *temp = (int *)malloc(size * sizeof(int));
	if (temp != NULL) {
		merge(arr, 0, size, temp);
		return -1;
	}
	return 0;
	
}
void print(int arr[], int size) {
	int i; 
	for (i = 0; i < size; i++) {
		printf("%d ", arr[i]);
		
	}
	printf("\n");
}

int main() {
	int size, power1, range, power2;
	time_t t1, t2;
	srand(time(0)); 
	cout << "enter the number you want to raise 10 to for array size. \n stay between 2 and 6 inclusive: " << endl;
	cin >> power1;
	size = pow(10, power1);
	cout << "enter the number you want to raise 10 to for the range of numbers.\n stay with 2 to 12 inclusive: " << endl;
	cin >> power2;
	range = pow(10, power2);
	int *n = (int *)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) {
		n[i] = rand() % range + range - 1;
	}
	time(&t1);
	mergesort(n, size);
	print(n, size);
	time(&t2);
	double timetaken = double(t2 - t1);
	cout << "time taken in: " << fixed << timetaken << " seconds" << endl;
	system("pause");
	return 0;
}
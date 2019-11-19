#include <iostream>
#include <ctime>
using namespace std;

void print(int arr[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void insertion(int arr[],int size) {
	int i, j, key;
	for (i = 1; i < size; i++) {
		key = arr[i];
		j = i;
		while (j > 0 && arr[j-1] > key) {
			arr[j] = arr[j - 1];
			j--;
			}
		arr[j] = key;
		}
}

int main() {
	time_t start, end;
	int size, power1, range, power2;
	cout << "exponent for size: " << endl;
	cin >> power1;
	cout << "exponent for range" << endl;
	cin >> power2;
	size = pow(10, power1);
	range = pow(10, power2);

	int *arr = (int *)malloc(size * sizeof(int));
	int srand(time(0));

	for (int i = 0; i < size; i++) {
		arr[i] = rand() % range + 1;
	}
	time(&start);
	insertion(arr, size);
	time(&end);
	int timetaken = double(end - start);
	cout << "time taken: " << fixed << timetaken << " seconds" << endl;
	print(arr, size);

	system("pause");
	return 0;
}
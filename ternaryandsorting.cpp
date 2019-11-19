#include <iostream> 

using namespace std; 

void swap(int* a, int* b) {
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void insertion(int arr[], int n) {
	int i, j;
	for (i = 1; i < n; i++) {
		j = i;
		while (j > 0 && arr[j] < arr[j - 1]) {
			swap(arr[j], arr[j - 1]);
				j--;
		}
	}
}
int ternary(int arr[], int x, int l, int r) {
	int m1, m2;

	if (l < r) {
		m1 = l + (r - l) / 3;
		m2 = r - (r - l) / 3;
		if (arr[m1] == x)
			return x;
		if (arr[m2] == x)
			return m2;
		if (arr[m1] > x)
			return ternary(arr, x, l, m1 - 1);
		if (arr[m2] < x)
			return ternary(arr, x, m2 + 1, r);
		else
			return ternary(arr, x, m1 + 1, m2 - 1);
		return -1;
	}
	
}
void printarray(int arr[], int n) {
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}
int main() {
	int arr[] = { 2,4,66,3,22,5,7,1,88 }, x = 7, l = 0, r = sizeof(arr) - 1;
	int n = sizeof(arr) / sizeof(arr[0]);

	printarray(arr, n);
	insertion(arr, n);
	printarray(arr, n);
	cout << ternary(arr, x, l, r);



}
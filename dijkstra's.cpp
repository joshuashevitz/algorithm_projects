#include <iostream>
#include <climits>
#include <set>

using namespace std;

#define N 5

int mindis(int dist[], bool set[]) {
	int min = INT_MAX, main_index;
	for (int v = 0; v < N; v++) {
		if (set[v] == false && dist[v] <= min) {
			min = dist[v], main_index = v;

		}
	}
	return main_index;
}
void print(int dist[], int src) {
	cout << "vertex distance" << endl;
	for (int i = 0; i < N; i++) {
		cout <<"\t\t \n" <<i << " \t\t " << dist[i];
	}
}
void dijkstra(int G[N][N], int n) {
	int dist[N];
	bool set[N];
	for (int i = 0; i < N; i++) {
		dist[i] = INT_MAX, set[i] = false;
	}
	dist[n] = 0;
	for (int c = 0; c < N - 1; c++) {
		int u = mindis(dist, set);
		set[u] = true;
		for (int v = 0; v < N; v++) {
			if (!set[v] && G[u][v] && dist[u] != INT_MAX && dist[u] + G[u][v] < dist[v]) {
				dist[v] = dist[u] + G[u][v];
			}
		}
	}
	print(dist, N);
}
int main() {
	int g[N][N] = { { 0, 4, 0, 0, 0 },
	  { 4, 0, 7, 0, 0 },
	  { 0, 8, 0, 9, 0 },
	  { 0, 0, 7, 0, 6 },
	  { 0, 2, 0, 9, 0 } };

	dijkstra(g, 0);
	return 0;
}
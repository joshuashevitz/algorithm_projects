//==============================================================
	// Shortest Path Program
	//==========================================================
	// <Joshua Shevitz>
	// <336-001>
	// <11/7/2019>
//==============================================================
#include <iostream>

using namespace std;
#define N 7
#define E 12
#define V 8
int mindis(int dist[], bool set[]) {
	int min = INT_MAX, main_index;
	for (int i = 0; i < N; i++) {
		if (dist[i] <= min && set[i] == false) {
			min = dist[i];
			main_index = i;
		}
	}
	return main_index;
}
void print(int dist[]) {
	cout << "vertex distance for dijkstra's: " << endl;
	for (int i = 0; i < N; i++) {
		cout << "\t\t \n" << i << "\t\t" << dist[i];
	}
}
void dijkstra(int g[N][N], int src) {
	int dist[N];
	bool set[N];
	for (int i = 0; i < N; i++) {
		dist[i] = INT_MAX;
		set[i] = false;
	}
	dist[src] = 0;
	for (int c = 0; c < N - 1; c++) {
		int u = mindis(dist, set);
		set[u] = true;
		for (int v = 0; v < N; v++) {
			if (!set[v] && g[u][v] && dist[u] != INT_MAX && g[u][v] + dist[u] < dist[v]) {
				dist[v] = g[u][v] + dist[u];
			}
		}
	}
	print(dist);
}
struct edge {
	int src;
	int dest;
	int wt;
};

void bellman(int nv,struct edge e[], int source, int ne) {
	int u, v, weight, i, j = 0;
	int dist[V];
	

	for (i = 0; i < nv; i++) {
		dist[i] = INT_MAX;
		
	}
	dist[source] = 0;
	
	for (i = 0; i < nv - 1; i++) {
	
		for (j = 0; j < ne; j++) {
			u = e[j].src;
			v = e[j].dest;
			weight = e[j].wt;
			
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
				dist[v] = dist[u] + weight;
			}
		
			}
		}
	
	for (j = 0; j < ne; j++) {
		u = e[j].src;
		v = e[j].dest;
		weight = e[j].wt;
		if (dist[u] + weight < dist[v]) {
			cout << "there is a negative cycle: ";
				return;
		}
	}
	cout << "vertex distance for Bellman's: " << endl;
	for (i = 1; i < nv; i++) {
		cout << "\t\t \n" << i << "\t\t" << dist[i];
	}
}
int main() {
	
	int g[N][N] = {
	{0,2,0,1,0,0,0},
	{0,0,0,3,10,0,0},
	{4,0,0,0,0,5,0},
	{0,0,2,0,2,8,4},
	{0,0,0,0,0,0,6},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,1,0} };
	
	dijkstra(g, 0);
	
	cout <<"\n\n" <<endl;

	edge e[E];
	e[0].src = 1; e[0].dest = 2;e[0].wt = 2;
	e[1].src = 1; e[1].dest = 4;e[1].wt = -1;
	e[2].src = 2; e[2].dest = 4;e[2].wt = 3;
	e[3].src = 2; e[3].dest = 5; e[3].wt = 10;
	e[4].src = 3; e[4].dest = 1; e[4].wt = 4;
	e[5].src = 3; e[5].dest = 6; e[5].wt = 5;
	e[6].src = 4; e[6].dest = 3; e[6].wt = 2;
	e[7].src = 4; e[7].dest = 5; e[7].wt = -2;
	e[8].src = 4; e[8].dest = 6; e[8].wt = 8;
	e[9].src = 4; e[9].dest = 7; e[9].wt = 4;
	e[10].src = 5; e[10].dest = 7; e[10].wt = 6;
	e[11].src = 7; e[11].dest = 6; e[11].wt = -1;

	bellman(V, e, 1, E);
	cout << endl;
	
	system("pause");
	return 0;

}


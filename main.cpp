#include<iostream>

using namespace std;

#define m 1000000007

int vis[101] = {0};
int vis2[101] = {0};

int main() {
	int n, k, d; 
	cin >> n >> k >> d;

	// first fact
	// This is not a tree
	// it is actually a graph with multiple paths to a vertex
	// if you lable vertices with the weight sums in the tree and dedup you
	// should realise this, hence dfs is valid too, if in a valid branch and you visit n
	// then increment a counter

	// vis[n] and vis2[n] tells us number of way to get to n
	// vis[0] is 0
	// however vis2 only uses weights till d ie [1, d - 1]
	// so vis2[n] didn't use weight above d even once

	// if u can visit a vertex in k ways, then a new link adds k ways to reach the next

	vis[0] = 1;
	
	for (int j = 0; j <= n; j++) { 
		for (int i = 1; i <= k && j <= n - i; i++) {
			vis[j + i] = (vis[j + i] + vis[j]) % m;
		}
	}

	vis2[0] = 1;
	for (int j = 0; j <= n; j++) { 
		for (int i = 1; i < d && j <= n - i; i++) {
			vis2[j + i] = (vis2[j + i] + vis2[j]) % m;
		}
	}

	cout << (((vis[n] - vis2[n]) % m + m) % m);
	cerr << '\n' << vis[n] << ' ' << vis2[n];
}

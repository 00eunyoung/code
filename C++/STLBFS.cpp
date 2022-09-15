#include<iostream>
#include<queue>
using namespace std;

int n, m; 
int s, e; 
vector<vector<int>> adjArray; 
vector<int> visited;
queue<int> Q;

void AddEdge(int start, int end) {
	adjArray[start].push_back(end);
	adjArray[end].push_back(start);
}
void printGraph() {
	for (int i = 1; i <= n; i++) {
		cout << i << ": ";
		for (int j = 0; j < adjArray[i].size(); j++)
			cout << adjArray[i][j] << " ";
		cout << endl;
	}
}

void aBFS(int v) {
	visited[v] = 1;
	Q.push(v);

	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();
		printf("%d", x);
		for (int i = 0; i < adjArray[x].size(); i++) {
			int p = adjArray[x][i];
			if (!visited[p]) {
				
				Q.push(p);
				visited[p] = 1;
			}
		}
	}
}

void BFS() {
	for (int v = 1; v <= n; v++)
		visited[v] = 0;

	for (int v = 1; v <= n; v++) {
		if (visited[v] == 0) {
			aBFS(v);
		}
	}
}

int main() {
	cin >> n >> m;
	adjArray.resize(n + 1);
	visited.resize(n + 1);

	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		AddEdge(s, e);
	}
	printGraph();
	BFS();
}

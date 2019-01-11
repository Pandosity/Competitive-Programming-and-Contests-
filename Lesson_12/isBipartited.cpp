/*This algorithm, space wise, uses only a vector color to store colors of the vectors we process(initially a blank color 0, and then alternating
between colors 1 and 2 as we process the vertexes) and a queue Q in which each vertex is pushed and popped exactly once as we meet them performing a BFS. 
Therefrore the algorithm runs in O(V+E) time (we know this from the theory of BFS).*/

bool isBipartite(int G[][MAX],int V) {
	vector<int> color(V,0);
	queue<int> Q;
	for (int i = 0; i < V ; ++i) {
		if (!color[i]) {
			color[i] = 1;
			Q.push(i);
			while (!Q.empty()) {
				int current = Q.front();
				Q.pop();
				for (int j = 0; j < V; j++) if (G[current][j]) {
					if (!color[j]) Q.push(j);
					if (color[current] == color[j]) return false;
					color[j] = 3-color[current];
				}
			}
		}
	}
	return true;
}

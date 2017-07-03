
//												shortest path by Floyd-Warshall
// 	O(V^3)
//
// Floyd-Warshall gives us the shortest paths from all source to all target nodes. 
// There are other uses for Floyd-Warshall as well;
// it can be used to find connectivity in a graph (known as the Transitive Closure of a graph).
// Note: No negative wei

// Dynamic Programming: f(i,j) = min(f(i,j), f(i,k) + f(k,j)): k = [1,V] is an intermediate node to cal dist(i,j)

/*----------------------------------------- Floyd-Warshall for adjlist ---------------------------------------------------------------------------------------*/
const int MAXV = 100 + 1;
int V, E;
vector<int> e[MAXV];
vector<int> wei[MAXV];

int dist[MAXV][MAXV];
void floydWarshall() {
	//Base cases
	for (int i = 1; i <= V; ++i) {
		fill(dist[i] + 1, dist[i] + V + 1, inf);
		dist[i][i] = 0;
	}
		
	for (int v = 1; v <= V; ++v)
		for (int i = 0; i < e[v].size(); ++i)
			dist[v][e[v][i]] = wei[v][i];

	//DP
	for (int k = 1; k <= V; ++k)
		for (int i = 1; i <= V; ++i)
			for (int j = 1; j <= V; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

/*----------------------------------------- Floyd-Warshall for adjmatrix ---------------------------------------------------------------------------------------*/
const int MAXV = 100 + 1;
int V, E;

int dist[MAXV][MAXV];
void floydWarshall() {
	for (int k = 1; k <= V; ++k)
		for (int i = 1; i <= V; ++i)
			for (int j = 1; j <= V; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
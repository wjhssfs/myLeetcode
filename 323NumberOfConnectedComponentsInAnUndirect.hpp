// 323. Number of Connected Components in an Undirected Graph

// Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

// Example 1:
//      0          3
//      |          |
//      1 --- 2    4
// Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.

// Example 2:
//      0           4
//      |           |
//      1 --- 2 --- 3
// Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.

// Note:
// You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

class Solution {
public:
	int countComponents(int n, vector<pair<int, int>>& edges) {
		vector<list<int>> adjList(n);
		int nComponents = 0;
		vector<bool> visited(n);
		for (auto &&edge : edges) {
			adjList[edge.first].push_front(edge.second);
			adjList[edge.second].push_front(edge.first);
		}
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				++nComponents;
				dfs(adjList, i, visited);
			}
		}
		return nComponents;
	}

	void dfs(vector<list<int>>& adjList, int i, vector<bool> &visited) {
		visited[i] = true;
		for (int n : adjList[i]) {
			if (!visited[n]) {
				dfs(adjList, n, visited);
			}
		}
	}
};

class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        p.resize(n);
        iota(p.begin(), p.end(),0);
        for(auto && edge : edges){
            unite(edge.first, edge.second);
        }
        unordered_set<int> s;
        for(int i = 0; i < n; i++){
            s.insert(find(i));
        }
        
        return (int)s.size();
    }
private:
    vector<int> p;
    int find(int i){
        if(p[i] == i)
            return i;
        p[i] = find(p[i]);
        return p[i];
    }
    
    void unite(int a, int b){
        p[find(a)] = find(b);
    }
};
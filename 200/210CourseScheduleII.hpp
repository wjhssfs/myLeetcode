// 210 Course Schedule II 
// There are a total of n courses you have to take, labeled from 0 to n - 1.
// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
// Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
// There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.
// For example:
// 2, [[1,0]]
// There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]
// 4, [[1,0],[2,0],[3,1],[3,2]]
// There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2.
// Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].
// Note:
// The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
class Solution {
    vector<bool> visited;
    vector<int> path; 
    vector<bool> rec;
    vector<list<int>> graph;

public:

    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) 
    {
        vector<int> cycle();

        if(prerequisites.empty())
        {
            for(int i = 0; i < numCourses; ++i)
            {
                path.push_back(i);
            }
            return path;
        }

        graph.assign(numCourses, list<int>());
        visited.assign(numCourses, false);
        rec.assign(numCourses, false);

        for(int i = 0; i < prerequisites.size(); ++i)
        {
            graph[prerequisites[i].first].push_back(prerequisites[i].second);
        }

        for(int i = 0; i < graph.size(); ++i)
        {
            if(visited[i]) continue;
            if(isCycle(i)) return vector<int>();
        }

        return path;
    }

    bool isCycle(int course)
    {
        visited[course] = true;
        rec[course] = true;

        for(auto it = graph[course].begin(); it!=graph[course].end(); ++it)
        {
            if(!visited[*it])
            {
                if(isCycle(*it)) return true;
            }
            if(rec[*it]) return true;
        }
        rec[course] = false;
        path.push_back(course);
        return false;
    }
};

// https://leetcode.com/discuss/42548/20-lines-c-bfs-dfs-solutions
// BFS
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<int> degrees = compute_indegree(graph);
        queue<int> zeros;
        for (int i = 0; i < numCourses; i++)
            if (!degrees[i]) zeros.push(i);
        vector<int> toposort;
        for (int i = 0; i < numCourses; i++) {
            if (zeros.empty()) return {};
            int zero = zeros.front();
            zeros.pop();
            toposort.push_back(zero);
            for (int neigh : graph[zero]) {
                if (!--degrees[neigh])
                    zeros.push(neigh);
            }
        }
        return toposort;
    }
private:
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto pre : prerequisites)
            graph[pre.second].insert(pre.first);
        return graph; 
    }
    vector<int> compute_indegree(vector<unordered_set<int>>& graph) {
        vector<int> degrees(graph.size(), 0);
        for (auto neighbors : graph)
            for (int neigh : neighbors)
                degrees[neigh]++;
        return degrees;
    }
};

// DFS
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<int> toposort;
        vector<bool> onpath(numCourses, false), visited(numCourses, false);
        for (int i = 0; i < numCourses; i++)
            if (!visited[i] && dfs(graph, i, onpath, visited, toposort))
                return {};
        reverse(toposort.begin(), toposort.end());
        return toposort;
    }
private:
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto pre : prerequisites)
            graph[pre.second].insert(pre.first);
        return graph;
    }
    bool dfs(vector<unordered_set<int>>& graph, int node, vector<bool>& onpath, vector<bool>& visited, vector<int>& toposort) { 
        if (visited[node]) return false;
        onpath[node] = visited[node] = true; 
        for (int neigh : graph[node])
            if (onpath[neigh] || dfs(graph, neigh, onpath, visited, toposort))
                return true;
        toposort.push_back(node);
        return onpath[node] = false;
    }
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        map<int, set<int>> in, out;
        set<int> starts;
        for (int i = 0; i < numCourses; ++i) starts.insert(i);
        for (auto && p : prerequisites) {
            in[p.first].insert(p.second);
            out[p.second].insert(p.first);
            starts.erase(p.first);
        }
        vector<int> res;
        while (starts.size()) {
            int cur = *starts.begin();
            starts.erase(starts.begin());
            res.push_back(cur);
            for (auto ic : out[cur]) {
                in[ic].erase(cur);
                if (in[ic].empty()) starts.insert(ic);
            }
        }
        return res.size() == numCourses ? res : vector<int>();
    }
};
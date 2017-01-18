// 207 Course Schedule
// There are a total of n courses you have to take, labeled from 0 to n - 1.
// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
// Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
// For example:
// 2, [[1,0]]
// There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.
// 2, [[1,0],[0,1]]
// There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
// Note:
// The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
// Hints:
// This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
// Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
// https://class.coursera.org/algo-003/lecture/52
// Topological sort could also be done via BFS.
// http://en.wikipedia.org/wiki/Topological_sorting#Algorithms
class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<vector<int>> dependantList(numCourses);
		vector<int> numRequired(numCourses);
		for_each(prerequisites.begin(), prerequisites.end(), [&](const pair<int, int> & pre){
			numRequired[pre.first]++;
			dependantList[pre.second].push_back(pre.first);
		});

		while (1)
		{
			auto it = find(numRequired.begin(), numRequired.end(), 0);
			if (it == numRequired.end())
			{
				return find_if(numRequired.begin(), numRequired.end(), [](int i){ return i > 0; }) == numRequired.end();
			}
			else
			{
				*it = -1;
				auto && ref = dependantList[it - numRequired.begin()];
				for (auto && dependant : ref)
				{
					numRequired[dependant]--;
				}
			}
		}
	}
};
// 695. Max Area of Island

// Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

// Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

// Example 1:
// [[0,0,1,0,0,0,0,1,0,0,0,0,0],
//  [0,0,0,0,0,0,0,1,1,1,0,0,0],
//  [0,1,1,0,1,0,0,0,0,0,0,0,0],
//  [0,1,0,0,1,1,0,0,1,0,1,0,0],
//  [0,1,0,0,1,1,0,0,1,1,1,0,0],
//  [0,0,0,0,0,0,0,0,0,0,1,0,0],
//  [0,0,0,0,0,0,0,1,1,1,0,0,0],
//  [0,0,0,0,0,0,0,1,1,0,0,0,0]]
// Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
// Example 2:
// [[0,0,0,0,0,0,0,0]]
// Given the above grid, return 0.
// Note: The length of each dimension in the given grid does not exceed 50.

class Solution {
	void dfs(vector<vector<int>>& grid, int i, int j, int& curArea) {
		if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return;
		if (grid[i][j] != 1) return;
		++curArea;
		grid[i][j] = 2;
		int d[] = { -1, 0, 1, 0, -1 };
		for (int k = 0; k < 4; ++k) {
			dfs(grid, i + d[k], j + d[k + 1], curArea);
		}
	}

public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int maxArea = 0;
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[0].size(); ++j) {
				int curArea = 0;
				dfs(grid, i, j, curArea);
				maxArea = max(curArea, maxArea);
			}
		}
		return maxArea;
	}
};


#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 55;
bool u[SIZE][SIZE];
int an;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
PII bfs[SIZE*SIZE];
void f(int x,int y,int n,int m,vector<vector<int>>& grid){
    bfs[0]=MP(x,y);
    u[x][y]=1;
    int rr=1;
    REP(i,rr){
        REP(k,4){
            int nx=bfs[i].F+dx[k];
            int ny=bfs[i].S+dy[k];
            if(nx<0||ny<0||nx>=n||ny>=m||grid[nx][ny]!=1||u[nx][ny])continue;
            u[nx][ny]=1;
            bfs[rr++]=MP(nx,ny);
        }
    }
    an=max(an,rr);
}
class Solution {
public:
   int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=SZ(grid);
        if(!n)return 0;
        an=0;
        int m=SZ(grid[0]);
        MS0(u);
        REP(i,n)REP(j,m){
            if(grid[i][j]==1&&!u[i][j]){
                f(i,j,n,m,grid);
            }
        }
        return an;
    }
};
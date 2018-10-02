// 765. Couples Holding Hands
// N couples sit in 2N seats arranged in a row and want to hold hands. We want to know the minimum number of swaps so that every couple is sitting side by side. A swap consists of choosing any two people, then they stand up and switch seats.

// The people and seats are represented by an integer from 0 to 2N-1, the couples are numbered in order, the first couple being (0, 1), the second couple being (2, 3), and so on with the last couple being (2N-2, 2N-1).

// The couples' initial seating is given by row[i] being the value of the person who is initially sitting in the i-th seat.

// Example 1:

// Input: row = [0, 2, 1, 3]
// Output: 1
// Explanation: We only need to swap the second (row[1]) and third (row[2]) person.
// Example 2:

// Input: row = [3, 2, 0, 1]
// Output: 0
// Explanation: All couples are already seated side by side.
// Note:

// len(row) is even and in the range of [4, 60].
// row is guaranteed to be a permutation of 0...len(row)-1.

Class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        unordered_map<int, int> m;
        for (int i = 0; i < row.size(); i += 2) {
            m[row[i]] = row[i + 1];
            m[row[i + 1]] = row[i];
        }
        int result = 0;
        unordered_set<int> visited;
        for (int i = 0; i < row.size(); i += 2) {
            if (visited.count(i)) continue;
            int next = i + 1;
            while (m[next] != i) {
                next = m[next];
                next = (next % 2 == 0) ? next + 1 : next - 1;
                visited.insert(next & ~1UL);
                ++result;
            }
        }
        return result;
    }
};

void insert_helper(unordered_map<int, int>& m, int v1, int v2) {
  auto k = min(v1, v2), v = max(v1, v2);
  if (k != v) { // track wrong couple
    if (m.count(k) > 0) insert_helper(m, m[k], v);
    else m[k] = v;
  }
}
int minSwapsCouples(vector<int>& row) {
  unordered_map<int, int> m;
  for (auto i = 0; i < row.size(); i += 2) insert_helper(m, row[i] / 2, row[i + 1] / 2);
  return m.size();
}

class Solution {
    public int minSwapsCouples(int[] row) {
        int N = row.length / 2;
        //couples[x] = {i, j} means that
        //couple #x is at couches i and j (1 indexed)
        int[][] couples = new int[N][2];
        
        for (int i = 0; i < row.length; ++i)
            add(couples[row[i]/2], i/2 + 1);
        
        //adj[x] = {i, j} means that
        //x-th couch connected to couches i, j (all 1 indexed) by couples
        int[][] adj = new int[N+1][2];
        for (int[] couple: couples) {
            add(adj[couple[0]], couple[1]);
            add(adj[couple[1]], couple[0]);
        }
        
        // The answer will be N minus the number of cycles in adj.
        int ans = N;
        // For each couch (1 indexed)
        for (int r = 1; r <= N; ++r) {
            // If this couch has no people needing to be paired, continue
            if (adj[r][0] == 0 && adj[r][1] == 0)
                continue;
            
            // Otherwise, there is a cycle starting at couch r.
            // We will use two pointers x, y with y faster than x by one turn.
            ans--;
            int x = r, y = pop(adj[r]);
            // When y reaches the start 'r', we've reached the end of the cycle.
            while (y != r) {
                // We are at some couch with edges going to 'x' and 'new'.
                // We remove the previous edge, since we came from x.
                rem(adj[y], x);
                
                // We update x, y appropriately: y becomes new and x becomes y.
                x = y;
                y = pop(adj[y]);
            }
        }
        return ans;
    }
    
    // Replace the next zero element with x.
    public void add(int[] pair, int x) {
        pair[pair[0] == 0 ? 0 : 1] = x;
    }
    
    // Remove x from pair, replacing it with zero.
    public void rem(int[] pair, int x) {
        pair[pair[0] == x ? 0 : 1] = 0;
    }
    
    // Remove the next non-zero element from pair, replacing it with zero.
    public int pop(int[] pair) {
        int x = pair[0];
        if (x != 0) {
            pair[0] = 0;
        } else {
            x = pair[1];
            pair[1] = 0;
        }
        return x;
    }
}
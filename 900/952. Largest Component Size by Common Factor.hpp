// 952. Largest Component Size by Common Factor
// Given a non-empty array of unique positive integers A, consider the following graph:

// There are A.length nodes, labelled A[0] to A[A.length - 1];
// There is an edge between A[i] and A[j] if and only if A[i] and A[j] share a common factor greater than 1.
// Return the size of the largest connected component in the graph.

 

// Example 1:

// Input: [4,6,15,35]
// Output: 4

// Example 2:

// Input: [20,50,9,63]
// Output: 2

// Example 3:

// Input: [2,3,6,7,4,12,21,39]
// Output: 8

// Note:

// 1 <= A.length <= 20000
// 1 <= A[i] <= 100000


class UnionFindSet {
public:
    UnionFindSet(int n) : _parent(n) {
        for (int i=0; i<n; i++) {
            _parent[i] = i;
        }
    }
    
    void Union(int x, int y) {
        _parent[Find(x)] = _parent[Find(y)];
    }
    
    int Find(int x) {
        if (_parent[x] != x) {
            _parent[x] = Find(_parent[x]);
        }
        return _parent[x];
    }
    
private:
    vector<int> _parent;
};

class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        int n = *max_element(A.begin(), A.end());
        UnionFindSet ufs(n+1);
        for (int &a : A) {
            for (int k = 2; k <= sqrt(a); k++) {
                if (a % k == 0) {
                    ufs.Union(a, k);
                    ufs.Union(a, a / k);
                }
            }
        }
        
        unordered_map<int, int> mp;
        int ans = 1;
        for (int &a : A) {
            ans = max(ans, ++mp[ufs.Find(a)]);
        }
        return ans;
    }
};

class Solution {
    
    int find(vector<int>&p, int i) {
        if (p[i] == i) return i;
        return p[i] = find(p, p[i]);
    }
    int combine(vector<int>&sz, vector<int>&p, int x, int y) {
        int px = find(p, x);
        int py = find(p, y);
        if (px == py) return px;
        if (sz[px] < sz[py]) swap(px, py);
        sz[px] += sz[py];
        p[py] = px;
        return px;
    }
public:
    int largestComponentSize(vector<int>& A) {
        vector<char> isPrime(314, 1); // 313 * 313 > 100000
        unordered_set<int> primes;
        for (int i = 2; i < 314; ++i) {
            if (!isPrime[i]) continue;
            primes.insert(i);
            for (int j = i + i; j < 314; j += i) isPrime[j] = 0;
        }
        vector<int> sz(A.size(), 1), parent(A.size());
        for (int i = 0; i < A.size(); ++i) parent[i] = i;
        vector<int> parentForPrime(100001, -1);
        for (int i = 0; i < A.size(); ++i) {
            int n = A[i];
            for (auto p : primes) {
                if (primes.count(n)) p = n;
                if (n % p == 0) {
                    if (parentForPrime[p] != -1)
                        parentForPrime[p] = combine(sz, parent, i, parentForPrime[p]);
                    else parentForPrime[p] = i;
                    while (n % p == 0) n /= p;
                }
                if (n == 1) break;
            }
            if (n != 1) {
                 if (parentForPrime[n] != -1)
                        parentForPrime[n] = combine(sz, parent, i, parentForPrime[n]);
                    else parentForPrime[n] = i;
            }
        }
        return *max_element(begin(sz), end(sz));
    }
};
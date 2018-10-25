// 96 Unique Binary Search Trees 
// Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
// For example,
// Given n = 3, there are a total of 5 unique BST's.
// 
//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3
// 
class Solution {
public:
    int numTrees(int n) {  
        if (n <= 2) return n;
		int sum = 2 * numTrees(n-1);
		for (int i = 1; i < n - 1; i++){
			sum += numTrees(i) * numTrees(n-i-1);
		}
		return sum;
    }
};

// https://leetcode.com/problems/unique-binary-search-trees/discuss/31666/DP-Solution-in-6-lines-with-explanation.-F(i-n)-G(i-1)-*-G(n-i)
public int numTrees(int n) {
    int [] G = new int[n+1];
    G[0] = G[1] = 1;

    for(int i=2; i<=n; ++i) {
        for(int j=1; j<=i; ++j) {
            G[i] += G[j-1] * G[i-j];
        }
    }

    return G[n];
}

// G[n] = C(n, 2n) / (n + 1) https://en.wikipedia.org/wiki/Catalan_number
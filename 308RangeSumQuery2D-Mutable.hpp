// 308 Range Sum Query 2D - Mutable

// Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

// Range Sum Query 2D
// The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

// Example:
// Given matrix = [
//   [3, 0, 1, 4, 2],
//   [5, 6, 3, 2, 1],
//   [1, 2, 0, 1, 5],
//   [4, 1, 0, 1, 7],
//   [1, 0, 3, 0, 5]
// ]

// sumRegion(2, 1, 4, 3) -> 8
// update(3, 2, 2)
// sumRegion(2, 1, 4, 3) -> 10
// Note:
// The matrix is only modifiable by the update function.
// You may assume the number of calls to update and sumRegion function is distributed evenly.
// You may assume that row1 ≤ row2 and col1 ≤ col2.


class NumMatrix {
	struct Node {
		int val, row1, col1, row2, col2;
		Node *parent, *first, *second;
		Node(int v, int r1, int c1, int r2, int c2) :val(v), row1(r1), col1(c1), row2(r2), col2(c2), parent(nullptr), first(nullptr), second(nullptr) {}
	};
	vector<vector<Node *>> endNodes;
	Node *root;

public:
	NumMatrix(vector<vector<int>> &matrix) {
		int m = matrix.size(), n = m ? matrix[0].size() : 0;
		endNodes.resize(m);
		for (auto &&r : endNodes) r.resize(n);
		if (n) {
			root = preProcess(matrix, 0, 0, m - 1, n - 1, true);
		}
		else
			root = nullptr;
	}

	void update(int row, int col, int val) {
		Node *curNode = endNodes[row][col];
		int diff = val - curNode->val;
		while (curNode) {
			curNode->val += diff;
			curNode = curNode->parent;
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return sumRegionRecursive(row1, col1, row2, col2, root);
	}

	int sumRegionRecursive(int row1, int col1, int row2, int col2, Node *curNode) {
		if (!curNode) 
			return 0;
		if (row1 > curNode->row2 || row2 < curNode->row1 || col1 > curNode->col2 || col2 < curNode->col1) return 0;
		if (row1 <= curNode->row1 && col1 <= curNode->col1 && row2 >= curNode->row2 && col2 >= curNode->col2)
			return curNode->val;
		int valFirst = sumRegionRecursive(row1, col1, row2, col2, curNode->first);
		int valSecond = sumRegionRecursive(row1, col1, row2, col2, curNode->second);
		return valFirst + valSecond;
	}

	Node* preProcess(vector<vector<int>> &matrix, int row1, int col1, int row2, int col2, bool vertical) {
		if (row1 == row2 && col1 == col2) {
			Node *newNode = new Node(matrix[row1][col1], row1, col1, row2, col2);
			endNodes[row1][col1] = newNode;
			return newNode;
		}

		Node *first = nullptr, *second = nullptr;
		if (vertical) {
			first = preProcess(matrix, row1, col1, row2, (col1 + col2) / 2, !vertical);
			second = col1 != col2 ? preProcess(matrix, row1, (col1 + col2) / 2 + 1, row2, col2, !vertical) : nullptr;
		}
		else {
			first = preProcess(matrix, row1, col1, (row1 + row2) / 2, col2, !vertical);
			second = row1 != row2 ? preProcess(matrix, (row1 + row2) / 2 + 1, col1, row2, col2, !vertical) : nullptr;
		}
		
		Node *curNode = new Node((first ? first->val : 0) + (second ? second->val : 0), row1, col1, row2, col2);
		curNode->first = first; curNode->second = second;
		if(first)
			first->parent = curNode; 
		if(second)
			second->parent = curNode;
		return curNode;
	}
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);


public class NumMatrix {

    int[][] tree;
    int[][] nums;
    int m;
    int n;

    public NumMatrix(int[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0) return;
        m = matrix.length;
        n = matrix[0].length;
        tree = new int[m+1][n+1];
        nums = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                update(i, j, matrix[i][j]);
            }
        }
    }

    public void update(int row, int col, int val) {
        if (m == 0 || n == 0) return;
        int delta = val - nums[row][col];
        nums[row][col] = val;
        for (int i = row + 1; i <= m; i += i & (-i)) {
            for (int j = col + 1; j <= n; j += j & (-j)) {
                tree[i][j] += delta;
            }
        }
    }

    public int sumRegion(int row1, int col1, int row2, int col2) {
        if (m == 0 || n == 0) return 0;
        return sum(row2+1, col2+1) + sum(row1, col1) - sum(row1, col2+1) - sum(row2+1, col1);
    }

    public int sum(int row, int col) {
        int sum = 0;
        for (int i = row; i > 0; i -= i & (-i)) {
            for (int j = col; j > 0; j -= j & (-j)) {
                sum += tree[i][j];
            }
        }
        return sum;
    }
}
// time should be O(log(m) * log(n))
Explanation of Binary Indexed Tree : https://www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/
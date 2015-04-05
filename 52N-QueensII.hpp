// 52 N-Queens II 
// Follow up for N-Queens problem.
// 
// Now, instead outputting board configurations, return the total number of distinct solutions.


class Solution {
public:
	/* backtrace program using bit-wise operation to speed up calculation.
	* 'limit' is all '1's.
	* 'h'  is the bits all the queens vertically projected on a row. If h==limit, then it's done, answer++.
	* 'r'   is the bits all the queens anti-diagonally projected on a row.
	* 'l'   is the bits all the queens diagonally projected on a row.
	* h|r|l  is all the occupied bits. Then pos = limit & (~(h|r|l)) is all the free positions.
	* p = pos & (-pos)  gives the right most '1'. pos -= p means we will place a queen on this bit
	*                             represented by p.
	* 'h+p'  means one more queue vertically projected on next row.
	* '(r+p)<<1'  means one more queue anti-diagonally projected on next row. Because we are
	*                   moving to next row and the projection is skew from right to left, we have to
	*                   shift left one position after moved to next row.
	* '(l+p)>>1'  means one more queue diagonally projected on next row. Because we are
	*                  moving to next row and the projection is skew from left to right, we have to
	*                  shift right one position after moved to next row.
	*/
	int totalNQueens(int n) {
		ans = 0;
		limit = (1 << n) - 1;
		dfs(0, 0, 0);
		return ans;
	}
	void dfs(int h, int r, int l) {
		if (h == limit) {
			ans++;
			return;
		}
		int pos = limit & (~(h | r | l));
		while (pos) {
			int p = pos & (-pos);
			pos -= p;
			dfs(h + p, (r + p) << 1, (l + p) >> 1);
		}
	}
	int ans, limit;
};


class Solution2 {
public:
	int totalNQueens(int n) {
		vector<int>qPerMute;
		if (n <= 1) return n;
		int count = 0;
		for (int i = 0; i < n; i++){ qPerMute.push_back(i); }
		while (next_permutation(qPerMute.begin(), qPerMute.end())){
			bool conflict = false;
			for (int i = 1; i < n; i++){
				for (int j = 0; j < i; j++){
					if (abs(i - j) == abs(qPerMute[i] - qPerMute[j])) {
						conflict = true;
						break;
					}
				}
				if (conflict) break;
			}
			if (!conflict) count++;
		}
		return count;
	}
};

/*
Solution: 1. Recursion.
           2. Recursion + bit version. (fast)
              The idea is from http://www.matrix67.com/blog/archives/266 (in chinese).
           3. Iteration.
*/

class Solution3 {
public:
    int totalNQueens(int n) {
        return totalNQueens_2(n);
    }
    
    // solution 1: recursion
    int totalNQueens_1(int n) 
    {
        int board[n];
        memset(board, -1, sizeof(board));
        int res = 0;
        totalNQueensRe(n, 0, board, res);
        return res;
    }
    
    void totalNQueensRe(int n, int row, int board[], int &res)
    {
        if (row  == n)
        {
            res++;
            return;
        }
        for (int i = 0; i < n; ++i)
        {
            if (isValid(board, row, i))
            {
                board[row] = i;
                totalNQueensRe(n, row + 1, board, res);
                board[row] = -1;
            }
        }
    }
    
    bool isValid(int board[], int row, int col)
    {
        for (int i = 0; i < row; ++i)
            if (board[i] == col || row - i == abs(col - board[i]))
                return false;
        return true;
    }
    
    // solution 2: bit version
    int totalNQueens_2(int n) {
        int res = 0;
        totalNQueensRe_2(n, 0, 0, 0, res);
        return res;
    }

    void totalNQueensRe_2(int n, int row, int ld, int rd, int &res)
    {
        if (row == (1 << n) - 1)
        {
            res++;
            return;
        }
        int avail = ~(row | ld | rd);
        for (int i = n - 1; i >= 0; --i)
        {
            int pos = 1 << i;
            if (avail & pos)
                totalNQueensRe_2(n, row | pos, (ld | pos) << 1, (rd | pos) >> 1, res);
        }
    }
    
    // solution 3: iterative solution
    int totalNQueens_3(int n) 
    {
        int board[n];
        memset(board, -1, sizeof(board));
        int row = 0;
        int res = 0;
        while (row != -1)
        {
            if (row == n)
            {
                res++;
                row--;
            }
            int i = board[row] == -1 ? 0 : board[row] + 1;
            for (; i < n; ++i)
            {
                if (isValid(board, row, i))
                {
                    board[row] = i;
                    row++;
                    break;
                }
            }
            if (i == n)
            {
                board[row] = -1;
                row--;
            }
        }
        return res;
    }
};

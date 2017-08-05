// 631. Design Excel Sum Formula
// Your task is to design the basic function of Excel and implement the function of sum formula. Specifically, you need to implement the following functions:

// Excel(int H, char W): This is the constructor. The inputs represents the height and width of the Excel form. H is a positive integer, range from 1 to 26. It represents the height. W is a character range from 'A' to 'Z'. It represents that the width is the number of characters from 'A' to W. The Excel form content is represented by a height * width 2D integer array C, it should be initialized to zero. You should assume that the first row of C starts from 1, and the first column of C starts from 'A'.


// void Set(int row, char column, int val): Change the value at C(row, column) to be val.


// int Get(int row, char column): Return the value at C(row, column).


// int Sum(int row, char column, List of Strings : numbers): This function calculate and set the value at C(row, column), where the value should be the sum of cells represented by numbers. This function return the sum result at C(row, column). This sum formula should exist until this cell is overlapped by another value or another sum formula.

// numbers is a list of strings that each string represent a cell or a range of cells. If the string represent a single cell, then it has the following format : ColRow. For example, "F7" represents the cell at (7, F).

// If the string represent a range of cells, then it has the following format : ColRow1:ColRow2. The range will always be a rectangle, and ColRow1 represent the position of the top-left cell, and ColRow2 represents the position of the bottom-right cell.


// Example 1:
// Excel(3,"C"); 
// // construct a 3*3 2D array with all zero.
// //   A B C
// // 1 0 0 0
// // 2 0 0 0
// // 3 0 0 0

// Set(1, "A", 2);
// // set C(1,"A") to be 2.
// //   A B C
// // 1 2 0 0
// // 2 0 0 0
// // 3 0 0 0

// Sum(3, "C", ["A1", "A1:B2"]);
// // set C(3,"C") to be the sum of value at C(1,"A") and the values sum of the rectangle range whose top-left cell is C(1,"A") and bottom-right cell is C(2,"B"). Return 4. 
// //   A B C
// // 1 2 0 0
// // 2 0 0 0
// // 3 0 0 4

// Set(2, "B", 2);
// // set C(2,"B") to be 2. Note C(3, "C") should also be changed.
// //   A B C
// // 1 2 0 0
// // 2 0 2 0
// // 3 0 0 6
// Note:
// You could assume that there won't be any circular sum reference. For example, A1 = sum(B1) and B1 = sum(A1).
// The test cases are using double-quotes to represent a character.
// Please remember to RESET your class variables declared in class Excel, as static/class variables are persisted across multiple test cases. Please see here for more details.

// https://discuss.leetcode.com/topic/93812/c-3-ms-concise-and-easy-to-understand

class Excel {
public:
    Excel(int H, char W) {
        // initialization. Because r starts from 1, I used H+1 instead of H.
        Exl = vector<vector<int>> (H+1, vector<int>(W-'A'+1, 0));
        fward.clear();
        bward.clear();
    }
    
    void set(int r, char c, int v) {
        int col = c-'A', key = r*26+col;
        // update its value and all the sum related
        update(r, col, v);
        // This is a reset, so break all the forward links if existing
        if (bward.count(key)) {
            for (int k:bward[key]) {
                fward[k].erase(key);
            }
            bward[key].clear();
        }
    }
    // update a cell and all the sum related, using BFS
    // weights are used to improve efficiency for overlapping ranges
    void update(int r, int col, int v) {
        int prev = Exl[r][col];
        Exl[r][col] = v;
        // myq is keys for cells in next level, and update is the increment for each cell
        queue<int> myq, update;
        myq.push(r*26+col);
        update.push(v-prev);
        while (!myq.empty()) {
            int key = myq.front(), dif = update.front();
            myq.pop();
            update.pop();
            if (fward.count(key)) {
                for (auto it = fward[key].begin(); it != fward[key].end(); it++) {
                    int k = it->first;
                    myq.push(k);
                    update.push(dif*(it->second));
                    Exl[k/26][k%26] += dif*(it->second);
                }
            }
        }
    }
    
    int get(int r, char c) {
        return Exl[r][c-'A'];
    }
    
    int sum(int r, char c, vector<string> strs) {
        // this is another reset, so break all the forward links
        int col = c-'A', key = r*26+col, ans = 0;
        if (bward.count(key)) {
            for (int k:bward[key]) {
                fward[k].erase(key);
            }
            bward[key].clear();
        }
        // get the sum over multiple ranges
        for (string str:strs) {
            int p = str.find(':'), left, right, top, bot;
            left = str[0]-'A';
            right = str[p+1]-'A';
            if (p == -1) 
                top = stoi(str.substr(1));
            else
                top = stoi(str.substr(1, p-1));
            bot = stoi(str.substr(p+2));
            for (int i = top; i <= bot; ++i) {
                for (int j = left; j <= right; ++j) {
                    ans += Exl[i][j];
                    fward[i*26+j][key]++;
                    bward[key].insert(i*26+j);
                }
            }
        }
        // update this cell and all the sum related
        update(r, col, ans);
        return ans;
    }
private:
    // The key of a cell is defined as 26*row+col, which is int;
    // fward links a cell to all the cells which use it for sum, and it may be used for 
    // multiple times due to overlap ranges, so another map is used for its weight
    // bward links a cell to all the cells that contribute to its sum. When reset its value,
    // or reassign a new sum range to it, we need disconnect the forward link of those cells to it. 
    unordered_map<int, unordered_map<int, int>> fward;
    unordered_map<int, unordered_set<int>> bward;
    vector<vector<int>> Exl;
};
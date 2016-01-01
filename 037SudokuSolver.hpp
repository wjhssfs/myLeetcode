// 37 Sudoku Solver
// Write a program to solve a Sudoku puzzle by filling the empty cells.
// Empty cells are indicated by the character '.'.
// You may assume that there will be only one unique solution.

class Solution {
public:
    typedef vector<vector<char> > BOARDTYPE;
    
    void solveSudoku(BOARDTYPE &board) {
        solveSudokuRe(board, 0, 0);
    }
    
    bool solveSudokuRe(BOARDTYPE &board, int row, int col) {
        getNextEmpty(board, row, col);
        if (row == 9) return true;
        vector<bool> avail(9, true);
        getAvailable(board, avail, row, col);
        for (int i = 0; i < 9; ++i)
        {
            if (!avail[i]) continue;
            board[row][col] = i + '1';
            if (solveSudokuRe(board, row, col)) return true;
        }
        board[row][col] = '.';
        return false;
    }
    
    void getNextEmpty(BOARDTYPE &board, int &row, int &col) {
        do {
            if (board[row][col] == '.') return;
            row = (col == 8) ? row + 1 : row;
            col = (col + 1) % 9;
        } while (row < 9);
    }
    
    void getAvailable(BOARDTYPE &board, vector<bool> &avail, int row, int col) {
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] != '.') avail[board[row][i]-'1'] = false;
            if (board[i][col] != '.') avail[board[i][col]-'1'] = false;
            int box_i = row/3*3 + i/3, box_j = col/3*3 + i%3;
            if (board[box_i][box_j] != '.') avail[board[box_i][box_j]-'1'] = false;
        }
    }
};



class Sudoku{
public:
    void solve(vector<vector<char>> &board){
        vector<vector<set<char>>> m(9, vector<set<char>>(9, set<char>({'1','2','3','4','5','6','7','8','9'})));
        queue<pair<int,int>> q;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    m[i][j] = {board[i][j]};
                    ++total;
                    q.push(make_pair(i,j));
                }
            }
        }
        
        while(q.size()){
            int i = q.front().first, j = q.front().second; q.pop();
            int isquare = i/3*3, jsquare = j /3 * 3;
            char c = board[i][j];
            for(int k = 0; k < 9; k++){
                clear(board, m[i][k], q, i, k, c);
                clear(board, m[k][j], q, k, j, c);
                clear(board, m[isquare + k/3][jsquare + k %3], q, isquare + k/3, jsquare + k %3, c);
            }
            for(char n = '1'; n <= '9'; n++){
                for(int i = 0; i < 9; i ++){
                    int counth = 0, countv = 0, counts = 0;
                    pair<int,int> ph, pv, ps;
                    for(int j = 0; j < 9; j++){
                        if(m[i][j].count(n)) {++counth; ph = make_pair(i,j);}
                        if(m[j][i].count(n)) {++countv; pv = make_pair(j, i);}
                        if(m[i/3*3 + j/3][(i%3)*3+j%3].count(n)) {++counts; ps = make_pair(i/3*3+j/3,(i%3)*3+j%3);}
                    }
                    if(counth == 1 && m[ph.first][ph.second].size() > 1){
                        board[ph.first][ph.second] = n;
                        m[ph.first][ph.second] = {n};
                        q.push(ph);
                        ++total;
                    }
                    if(countv == 1 && m[pv.first][pv.second].size() > 1){
                        board[pv.first][pv.second] = n;
                        m[pv.first][pv.second] = {n};
                        q.push(pv);
                        ++total;
                    }
                    if(counts == 1 && m[ps.first][ps.second].size() > 1){
                        board[ps.first][ps.second] = n;
                        m[ps.first][ps.second] = {n};
                        q.push(ps);
                        ++total;
                    }
                }
            }
        }
        
        for(int i = 0; i < 9; i ++){
            for(int j = 0; j < 9; j++){
                cout << i << " " << j << ": ";
                for(auto ele : m[i][j]){
                    cout << ele << "\t";
                }
                cout << endl;
            }
        }
        
        cout << total << endl;
        cout << "{" << endl;
        for(int i = 0; i < 9; i ++){
            cout << "{";
            for(int j = 0; j < 9; j++){
                cout << board[i][j];
                if(j!=8) cout << '\t';
            }
            string endRow = i==8?"}":"},";
            cout << endRow << endl;
        }
        cout << "}" << endl;
        return;
    }
    
    bool clear(vector<vector<char>> &board, set<char> &s, queue<pair<int,int>> &q, int i, int j, char c)
    {
        if(!s.count(c) || s.size() == 1) return false;
        s.erase(c);
        if(s.size() == 1){
            board[i][j] = *s.begin();
            ++total;
            q.push(make_pair(i,j));
        }
        return true;
    }
    
    int total = 0;
};
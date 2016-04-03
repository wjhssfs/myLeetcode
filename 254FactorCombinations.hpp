// 254 Factor Combinations
// Numbers can be regarded as product of its factors. For example,
// 8 = 2 x 2 x 2;
//   = 2 x 4.
// Write a function that takes an integer n and return all possible combinations of its factors.
// Note: 
// Each combination's factors must be sorted ascending, for example: The factors of 2 and 6 is [2, 6], not [6, 2].
// You may assume that n is always positive.
// Factors should be greater than 1 and less than n.
// Examples: 
// input: 1
// output: 
// []
// input: 37
// output: 
// []
// input: 12
// output:
// [
//   [2, 6],
//   [2, 2, 3],
//   [3, 4]
// ]
// input: 32
// output:
// [
//   [2, 16],
//   [2, 2, 8],
//   [2, 2, 2, 4],
//   [2, 2, 2, 2, 2],
//   [2, 4, 4],
//   [4, 8]
// ]

class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        result.clear(); buf.clear();
        orgN = n;
        if(n==1) return result;
        DFS(n, 2);
        return result;
    }

private:
    void DFS(int n, int start){
        for(int i = start; i <= n && i != orgN; i++){
            if(n%i == 0){
                buf.push_back(i);
                if(n==i) result.push_back(buf);
                else DFS(n/i, i);
                buf.pop_back();
            }
        }
    }
    
    int orgN;
    vector<int> buf;
    vector<vector<int>> result;
};
// 240 Search a 2D Matrix II

// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.
// For example,

// Consider the following matrix:

// [
//   [1,   4,  7, 11, 15],
//   [2,   5,  8, 12, 19],
//   [3,   6,  9, 16, 22],
//   [10, 13, 14, 17, 24],
//   [18, 21, 23, 26, 30]
// ]
// Given target = 5, return true.

// Given target = 20, return false.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int szR = matrix.size(); if (!szR) return false;
        int szC = matrix[0].size(); if(!szC) return false;
        auto bound = lower_bound(matrix.begin(), matrix.end(), target,
            [](vector<int>&v1, int v2){
                return v1[0] < v2;
            }
        );
        if(bound != matrix.end() && (*bound)[0] == target) return true;
        for(auto it = matrix.begin(); it != bound; it++){
            if(binary_search(it->begin(), it->end(), target)) return true;
        }
        return false;
    }
};
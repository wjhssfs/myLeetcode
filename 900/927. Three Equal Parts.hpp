// 927. Three Equal Parts

// Given an array A of 0s and 1s, divide the array into 3 non-empty parts such that all of these parts represent the same binary value.

// If it is possible, return any [i, j] with i+1 < j, such that:

// A[0], A[1], ..., A[i] is the first part;
// A[i+1], A[i+2], ..., A[j-1] is the second part, and
// A[j], A[j+1], ..., A[A.length - 1] is the third part.
// All three parts have equal binary value.
// If it is not possible, return [-1, -1].

// Note that the entire part is used when considering what binary value it represents.  For example, [1,1,0] represents 6 in decimal, not 3.  Also, leading zeros are allowed, so [0,1,1] and [1,1] represent the same value.

 

// Example 1:

// Input: [1,0,1,0,1]
// Output: [0,3]
// Example 2:

// Input: [1,1,0,1,1]
// Output: [-1,-1]
 

// Note:

// 3 <= A.length <= 30000
// A[i] == 0 or A[i] == 1

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        int n1 = count(begin(A), end(A), 1);
        if (n1 == 0) return {0, 2};
        vector<int> res(2, -1);
        if (n1 % 3 != 0) return res;
        for (int i = 0, k = 0; i < A.size(); ++i) {
            if (!A[i]) continue;
            ++k;
            if (k == n1 / 3) res[0] = i;
            else if (k == n1 / 3 * 2) res[1] = i + 1;
        }
        for (int i = A.size() - 1; i >= 0 && !A[i]; --i) {++res[0]; ++res[1];}
        for (int i = 0; i < n1 / 3 ; ++i) {
            if (A[res[0] - i] != A[res[1] - 1 - i] || A[res[0] - i] != A[A.size() - 1 - i]) return {-1, -1};
        }
        return res;
    }
};

// https://leetcode.com/problems/three-equal-parts/discuss/183922/C++-O(n)-time-O(1)-space-12-ms-with-explanation-and-comments
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        // Count no of 1's in the given array
        int countNumberOfOnes = 0;
        for(int c: A)
            if(c == 1)                  
                countNumberOfOnes++;
                                
        // If no 1 is found, that means we can return ans as {0, size-1}
        if(countNumberOfOnes == 0)      
            return {0, A.size()-1};
                        
        // If no of 1's is not a multiple of 3, then we can never find a possible partition since
        // there will be atkeast one partition that will have different no of 1's and hence
        // different binary representation
        // For example,
        // Given :
        // 0000110  110  110 
        //       |  |    |
        //       i       j
        // Total no of ones = 6
        // 0000110         110      110
        //     |           |        |
        //     start       mid      end
        // Match starting from first 1, and putting 2 more pointers by skipping k 1's
        
        if(countNumberOfOnes % 3 != 0)            
            return {-1, -1};
                        
        // find size of each partition
        int k = countNumberOfOnes/3;
        int i;
        
        // find the first 1 in the array
        for(i=0;i<A.size(); i++)
            if(A[i] == 1)
                break;
        int start = i;
        
        // find (k+1)th 1 in the array
        int count1 = 0;
        for(i=0;i<A.size(); i++)
        {
            if(A[i] == 1)
                count1++;
            if(count1 == k + 1)
                break;
        }
        int mid = i;
        
        //find (2*k +1)th 1 in the array
        count1= 0;
        for(i=0;i<A.size(); i++)
        {
            if(A[i] == 1)
                count1++;
            if(count1 == 2*k + 1)
                break;
        }
        int end = i;
        
        // Match all values till the end of the array
        while(end< A.size() && A[start] == A[mid] && A[mid] == A[end])
        {
            start++; mid++; end++;
        }
        
        // Return appropriate values if all the values have matched till the end
        if(end == A.size()) 
            return {start-1, mid};
        
        // otherwise, no such indices found
        return {-1, -1};
    }
};
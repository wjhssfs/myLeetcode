// 949. Largest Time for Given Digits
// Given an array of 4 digits, return the largest 24 hour time that can be made.

// The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from 00:00, a time is larger if more time has elapsed since midnight.

// Return the answer as a string of length 5.  If no valid time can be made, return an empty string.

 

// Example 1:

// Input: [1,2,3,4]
// Output: "23:41"
// Example 2:

// Input: [5,5,5,5]
// Output: ""
 

// Note:

// A.length == 4
// 0 <= A[i] <= 9

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        sort(begin(A), end(A), greater<int>());
        for (int i = 0; i < 4; ++i) { // assume result is: "A[i]A[j] : A[k]A[l]"
            if (A[i] > 2) continue;
            for (int j = 0; j < 4; ++j) {
                if (i == j || A[i] * 10 + A[j] > 23) continue;
                for (int k = 0; k < 4; ++k) {
                    if (i == k || j == k || A[k] > 5) continue;
                    
                    return to_string(A[i]) + to_string(A[j]) + ":" + to_string(A[k]) + 
                    // l equals 6 - i - j - k as i + j + k + l = 0 + 1 + 2 + 3 = 6
                    to_string(A[6 - i - j - k]); 
                }
            }
        }
                    
        return "";
    }
};

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        sort(begin(A), end(A));
        for (int i = 1439; i >= 0; --i) {
            int h = i / 60, m = i % 60;
            vector<int> sol = {h / 10, h % 10, m / 10, m % 10};
            sort(begin(sol), end(sol));
            if (A == sol) return (h < 10 ? "0" : "") + to_string(h) + (m < 10 ? ":0" : ":") + to_string(m);
        }
        return "";
    }
};

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        sort(begin(A), end(A), std::greater<int>());
        do {
        	//  ((A[0] < 2 || (A[0] == 2 && A[1] < 4)) && A[2] < 6)
            if (A[0] * 10 + A[1] < 24 && A[2] < 6) return
                to_string(A[0]) + to_string(A[1]) + ":" + to_string(A[2]) + to_string(A[3]);
        } while (prev_permutation(begin(A), end(A)));
        return "";
    }
};


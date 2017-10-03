// 686. Repeated String Match

// Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.

// For example, with A = "abcd" and B = "cdabcdab".

// Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").

// Note:
// The length of A and B will be between 1 and 10000.

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        for(int i = 0; i < A.size(); ++i) {
            int ii = i;
            int n = 1;
            for (int j = 0; j < B.size(); ++j) {
                if (A[ii] != B[j]) break;
                else {
                    if (j == B.size() - 1) return n;
                    ++ii;
                    if (ii == A.size()) {
                        ++n;
                        ii = 0;
                    }
                }
            }
        }
        return -1;
    }
};

int repeatedStringMatch(string A, string B) {
    for (auto i = 0, j = 0; i < A.size(); ++i) {
        for (j = 0; j < B.size() && A[(i + j) % A.size()] == B[j]; ++j);
        if (j == B.size()) return (i + j) / A.size() + ((i + j) % A.size() != 0 ? 1 : 0);
    }
    return -1;
}

class Solution {
    public int repeatedStringMatch(String A, String B) {
        StringBuilder sb = new StringBuilder();
        int rep = 0;
        while(sb.length() < B.length()){
        	sb.append(A);
        	rep++;
        }
        if(sb.toString().indexOf(B) >= 0){
        	return rep;
        }
        sb.append(A);
        rep++;
        if(sb.toString().indexOf(B) >= 0){
        	return rep;
        }
        return -1;
    }
}
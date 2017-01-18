// 278 First Bad Version

// You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

// Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

// You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, h = n, m = l + (h-l)/2; // not (h+l)/2, which can overflow
        while(l < h){
            if(isBadVersion(m)){
                h = m;
            }
            else {
                l = m + 1;
            }
            m = l + (h-l)/2;
        }
        
        return l;
    }
};
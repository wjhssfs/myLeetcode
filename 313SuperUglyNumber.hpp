// 313 Super Ugly Number

// Write a program to find the nth super ugly number.

// Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

// Note:
// (1) 1 is a super ugly number for any given primes.
// (2) The given numbers in primes are in ascending order.
// (3) 0 < k ≤ 100, 0 < n ≤ 10^6, 0 < primes[i] < 1000.


class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        // cur Ugly Number, generated from m[i] by multiply prime
        typedef pair<int, pair<int, int>> eleType;
        vector<int> m(n+1);
        m[1] = 1;
        priority_queue<eleType, vector<eleType>, greater<eleType>> q;
        for(int i : primes){
            q.push(make_pair(i, make_pair(1, i)));
        }
        for(int i = 2; i <= n; i++){
            auto curNode = q.top();
            m[i] = curNode.first;
            auto nextNode = q.top();
            while(nextNode.first == curNode.first){
                int nextPos = nextNode.second.first+1;
                int curPrime = nextNode.second.second;
                q.push(make_pair(m[nextPos]*curPrime, make_pair(nextPos, curPrime)));
                q.pop();
                nextNode = q.top();
            }
        }
        
        return  m[n];
    }
};

int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> index(primes.size(), 0), ugly(n, INT_MAX);
        ugly[0]=1;
        for(int i=1; i<n; i++){
            for(int j=0; j<primes.size(); j++) 
                ugly[i]=min(ugly[i],ugly[index[j]]*primes[j]);
            for(int j=0; j<primes.size(); j++) 
                index[j]+=(ugly[i]==ugly[index[j]]*primes[j]);
        }
        return ugly[n-1];
}
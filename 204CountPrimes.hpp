// 204 Count Primes
// Count the number of prime numbers less than a non-negative number, n.

class Solution {
public:
    int countPrimes(int n) {
        vector<bool>m(n+1);
        for(int i = 2; i * i < n; i++){
        	if(m[i]) continue;
        	int j = i*i;
        	while(j<n){
        		m[j] = true;
        		j += i;
        	}
        }
        int nPrime = 0;
        for(int i = 2; i < n; i++){
        	if(!m[i]) nPrime++;
        }
        return nPrime;
    }
};
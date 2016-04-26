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

int countPrimes(int n) {
    if (n<=2) return 0;
    vector<bool> passed(n, false);
    int sum = 1;
    int upper = sqrt(n);
    for (int i=3; i<n; i+=2) {
        if (!passed[i]) {
            sum++;
            //avoid overflow
            if (i>upper) continue;
            for (int j=i*i; j<n; j+=i) {
                passed[j] = true;
            }
        }
    }
    return sum;
}

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n, true);
        prime[0] = false, prime[1] = false;
        for (int i = 0; i < sqrt(n); ++i) {
            if (prime[i]) {
                for (int j = i*i; j < n; j += i) {
                    prime[j] = false;
                }    
            }    
        }
        return count(prime.begin(), prime.end(), true);
    }
};
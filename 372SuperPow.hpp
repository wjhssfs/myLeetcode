// 372. Super Pow
// Your task is to calculate a^b mod 1337 where a is a positive integer and b is an extremely
// large positive integer given in the form of an array.
// Example1:
// a = 2
// b = [3]
// Result: 8
// Example2:
// a = 2
// b = [1,0]
// Result: 1024

// https://en.wikipedia.org/wiki/Modular_exponentiation
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int result = 1, modulus = 1337, start = 0;
        int base = a % modulus;
        while (greaterThanZero(b)) {
        	if (nonZeroModByTwo(b)) {
        		result = (result * base) % modulus;
        	}
			divideByTwo(b);
        	base = (base * base) % modulus;
        }
        return result;
    }
 private:
 	bool nonZeroModByTwo(vector<int> &b) {
 		return start != b.size() && (b.back()%2);
 	}
 	bool greaterThanZero(vector<int> &b) {
 		return start != b.size();
 	}
 	void divideByTwo(vector<int> &b) {
 		int c = 0;
 		for (int i = start; i < b.size(); ++i) {
 			int cur = c * 10 + b[i];
 			b[i] = cur / 2;
 			c = cur % 2;
 		}
 		if (start != b.size() && b[start] == 0)
 			++start;
 	}

 	int start;
};

// https://discuss.leetcode.com/topic/50458/1-liners-other-with-explanations
def superPow(self, a, b):
    return pow(a, int(''.join(map(str, b))), 1337)

def superPow(self, a, b):
    result = 1
    for digit in b:
        result = pow(result, 10, 1337) * pow(a, digit, 1337) % 1337
    return result
// Explanation: For example for a^5347, the above computes a^5, then a^53, then a^534,
// and then finally a^5347. And a step from one to the next can be done like a^5347 = (a^534)^10 * a^7.

int superPow(int a, vector<int>& b) {
    const int mod = 1337;
    int ret = 1;
    for (int i : b)  ret = power(ret, 10, mod) * power(a, i, mod) % mod;
    return ret;
}
int power(int x, int n, int mod) {
    x %= mod;
    int ret = 1;
    while (n) {
        if (n & 1) ret = ret * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return ret;
}

   int superPow(int a, vector<int>& b) {
        int n = b.size();
        int result = 1;
        for(int i = n-1; i >=0; i--) {
            result = ((result * modPower(a, b[i])) % 1337);
            a = modPower(a, 10);
        }
        return result;
    }


class Solution {
    const int base = 1337;
    int powmod(int a, int k) //a^k mod 1337 where 0 <= k <= 10
    {
        a %= base;
        int result = 1;
        for (int i = 0; i < k; ++i)
            result = (result * a) % base;
        return result;
    }
public:
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int last_digit = b.back();
        b.pop_back();
        return powmod(superPow(a, b), 10) * powmod(a, last_digit) % base;
    }
};
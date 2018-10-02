// 634. Find the Derangement of An Array
// In combinatorial mathematics, a derangement is a permutation of the elements of a set, such that no element appears in its original position.

// There's originally an array consisting of n integers from 1 to n in ascending order, you need to find the number of derangement it can generate.

// Also, since the answer may be very large, you should return the output mod 109 + 7.

// Example 1:
// Input: 3
// Output: 2
// Explanation: The original array is [1,2,3]. The two derangements are [2,3,1] and [3,1,2].
// Note:
// n is in the range of [1, 106].

// https://en.wikipedia.org/wiki/Derangement#Counting_derangements

// Suppose that there are n people who are numbered 1, 2, ..., n. Let there be n hats also numbered 1, 2, ..., n. We have to find the number of ways in which no one gets the hat having same number as their number. Let us assume that the first person takes hat i. There are n − 1 ways for the first person to make such a choice. There are now two possibilities, depending on whether or not person i takes hat 1 in return:

// Person i does not take the hat 1. This case is equivalent to solving the problem with n − 1 persons and n − 1 hats: each of the remaining n − 1 people has precisely 1 forbidden choice from among the remaining n − 1 hats (i's forbidden choice is hat 1).
// Person i takes the hat 1. Now the problem reduces to n − 2 persons and n − 2 hats.
// !n=(n-1)(!(n-1)+!(n-2))
// !n=n[!(n-1)]+(-1)^{n}
class Solution {
    const static int M = 1000000007;
public:
    int findDerangement(int n) {
        long ans = 1;
        for (int i = 1; i <= n; i++) 
            ans = (i * ans % M + (i % 2 == 0 ? 1 : -1)) % M;
        return (int) ans;
    }
};

// https://en.wikipedia.org/wiki/Inclusion%E2%80%93exclusion_principle#Examples
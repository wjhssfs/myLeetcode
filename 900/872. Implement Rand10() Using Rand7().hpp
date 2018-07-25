// 872. Implement Rand10() Using Rand7()
// Given a function rand7 which generates a uniform random integer in the range 1 to 7, write a function rand10 which generates a uniform random integer in the range 1 to 10.

// Do NOT use system's Math.random().

 

// Example 1:

// Input: 1
// Output: [7]
// Example 2:

// Input: 2
// Output: [8,4]
// Example 3:

// Input: 3
// Output: [8,1,10]
 

// Note:

// rand7 is predefined.
// Each testcase has one argument: n, the number of times that rand10 is called.
 

// Follow up:

// What is the expected value for the number of calls to rand7() function?
// Could you minimize the number of calls to rand7()?

// // The rand7() API is already defined for you.
// // int rand7();
// // @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int result = 40;
        // 7 * (rand7() - 1) + (rand7() - 1) calls rand7() twice, it generates a
        // uniform random integer in range of [0, 48], which is rand49() - 1.
        // 8 * (rand7() - 1) calls rand7() only once, actually it's still rand7(), just multiplied by 8
        while (result >= 40) {result = 7 * (rand7() - 1) + (rand7() - 1);}
        return result % 10 + 1;
    }
};

Time Complexity:
The total number of iterations follows geometric distribution. For each iteration in the while loop, the probabilty of exiting the loop is p = 40/49. So the average time complexity T(n) = O(1/p) = O(49/40) = O(1).

Generalization:
Implement randM() using randN() when M > N:
Step 1: Use randN() to generate randX(), where X >= M. In this problem, I use 7 * (rand7() - 1) + (rand7() - 1) to generate rand49() - 1.
Step 2: Use randX() to generate randM(). In this problem, I use rand49() to generate rand40() then generate rand10.
// https://en.wikipedia.org/wiki/Geometric_distribution#Expected_number_of_failures_before_the_first_success
// https://www.shuxuele.com/algebra/sequences-sums-geometric.html

// 502. IPO

// Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited resources, it can only finish at most k distinct projects before the IPO. Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.

// You are given several projects. For each project i, it has a pure profit Pi and a minimum capital of Ci is needed to start the corresponding project. Initially, you have W capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.

// To sum up, pick a list of at most k distinct projects from given projects to maximize your final capital, and output your final maximized capital.

// Example 1:
// Input: k=2, W=0, Profits=[1,2,3], Capital=[0,1,1].

// Output: 4

// Explanation: Since your initial capital is 0, you can only start the project indexed 0.
//              After finishing it you will obtain profit 1 and your capital becomes 1.
//              With capital 1, you can either start the project indexed 1 or the project indexed 2.
//              Since you can choose at most 2 projects, you need to finish the project indexed 2 to get the maximum capital.
//              Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.
// Note:
// You may assume all numbers in the input are non-negative integers.
// The length of Profits array and Capital array will not exceed 50,000.
// The answer is guaranteed to fit in a 32-bit signed integer.

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        auto netGainCmp = [&](int a, int b) {return Profits[a] < Profits[b];};
        priority_queue<int, vector<int>, decltype(netGainCmp)> gainPq(netGainCmp);
        auto capCmp = [&](int a, int b) {return Capital[a] > Capital[b];};
        priority_queue<int, vector<int>, decltype(capCmp)> capPq(capCmp);
        for (int i = 0; i < Capital.size(); ++i) capPq.push(i);
        while (k) {
            while (capPq.size() && Capital[capPq.top()] <= W) {gainPq.push(capPq.top()); capPq.pop();}
            if (gainPq.empty()) break;
            int maxGainI = gainPq.top();
            W += Profits[maxGainI];
            gainPq.pop();
            --k;
        }
        return W;
    }
};

class Solution {
public:
   int findMaximizedCapital(int k, int W, vector<int>& P, vector<int>& C) {
      priority_queue<int> activated;      // P[i]'s within current W
      multiset<pair<int,int>> waiting; // (C[i],P[i])'s' outside current W
      
      for (int i = 0; i < P.size(); ++i) {
        if (!P[i]) continue;
        if (C[i] <= W) activated.push(P[i]);
        else waiting.emplace(C[i], P[i]);
      }
      while (k-- && activated.size()) { 
        W += activated.top(), activated.pop(); // greedy to work on most profitable first
        for (auto it = waiting.begin(); waiting.size() && it->first <= W; it = waiting.erase(it)) /* erase */
            activated.push(it->second);
      }
      return W;
    }
};
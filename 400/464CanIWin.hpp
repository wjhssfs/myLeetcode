// 464. Can I Win
// In the "100 game," two players take turns adding, to a running total, any integer from 1..10. The player who first causes the running total to reach or exceed 100 wins.
// What if we change the game so that players cannot re-use integers?
// For example, two players might take turns drawing from a common pool of numbers of 1..15 without replacement until they reach a total >= 100.
// Given an integer maxChoosableInteger and another integer desiredTotal, determine if the first player to move can force a win, assuming both players play optimally.
// You can always assume that maxChoosableInteger will not be larger than 20 and desiredTotal will not be larger than 300.
// Example

// Input:
// maxChoosableInteger = 10
// desiredTotal = 11

// Output:
// false

// Explanation:
// No matter which integer the first player choose, the first player will lose.
// The first player can choose an integer from 1 up to 10.
// If the first player choose 1, the second player can only choose integers from 2 up to 10.
// The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
// Same with other integers chosen by the first player, the second player will always win.

class Solution {
public:
	bool canIWin(int maxChoosableInteger, int desiredTotal) {
		if (maxChoosableInteger * (maxChoosableInteger + 1) < desiredTotal * 2) return false;
		unsigned flags = (1 << maxChoosableInteger) - 1;
		return canIWin(maxChoosableInteger, desiredTotal, flags);
	}

	bool canIWin(int maxChoosableInteger, int desiredTotal, unsigned flags) {
		if (m.count(flags)) return m[flags];
		for (unsigned i = maxChoosableInteger, mask = 1; i >= 1;  --i, mask <<= 1) {
			if (!(flags & mask)) continue;
			if (desiredTotal <= i || !canIWin(maxChoosableInteger, desiredTotal - i, flags & ~mask)) {
				m[flags] = true;
				return true;
			}
		}
		m[flags] = false;
		return false;
	}
private:
	unordered_map<unsigned, bool> m;
};

bool CanWin(const vector<int>& all_numbers, vector<bool>* used_positions, 
int sum) {
  if (sum <= 0) {
    // Already lost.
    return false;
  }
  for (int i = 0; i < all_numbers.size(); ++i) {
    if ((*used_positions)[i]) {
      continue;
    }
    (*used_positions)[i] = true
    bool can_other_win = CanWin(all_numbers, used_positions, sum - all_
numbers[i]);
    (*used_positions)[i] = false;
    if (!can_other_win) {
      return true;
    }
  }
  return false;
}

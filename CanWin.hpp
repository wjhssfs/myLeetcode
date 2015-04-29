CanWin

/* In "the 100 game," two players take turns adding, to a running 
total, any integer from 1..10. The player who first causes the running 
total to reach or exceed 100 wins. 
What if we change the game so that players cannot re-use integers? 
For example, if two players might take turns drawing from a common pool of 
numbers 
of 1..15 without replacement until they reach a total >= 100. This problem 
is 
to write a program that determines which player would win with ideal play. 

Write a procedure, "Boolean canIWin(int maxChoosableInteger, int 
desiredTotal)", 
which returns true if the first player to move can force a win with optimal 
play. 

Your priority should be programmer efficiency; don't focus on minimizing 
either space or time complexity. 
*/ 

Boolean canIWin(int maxChoosableInteger, int desiredTotal) { 
// Implementation here. Write yours 

}

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

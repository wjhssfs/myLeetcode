// 488. Zuma Game

// Think about Zuma Game. You have a row of balls on the table, colored red(R), yellow(Y), blue(B), green(G), and white(W). You also have several balls in your hand.

// Each time, you may choose a ball in your hand, and insert it into the row (including the leftmost place and rightmost place). Then, if there is a group of 3 or more balls in the same color touching, remove these balls. Keep doing this until no more balls can be removed.

// Find the minimal balls you have to insert to remove all the balls on the table. If you cannot remove all the balls, output -1.

// Examples:

// Input: "WRRBBW", "RB"
// Output: -1
// Explanation: WRRBBW -> WRR[R]BBW -> WBBW -> WBB[B]W -> WW

// Input: "WWRRBBWW", "WRBRW"
// Output: 2
// Explanation: WWRRBBWW -> WWRR[R]BBWW -> WWBBWW -> WWBB[B]WW -> WWWW -> empty

// Input:"G", "GGGGG"
// Output: 2
// Explanation: G -> G[G] -> GG[G] -> empty 

// Input: "RBYYBBRRB", "YRBGB"
// Output: 3
// Explanation: RBYYBBRRB -> RBYY[Y]BBRRB -> RBBBRRB -> RRRB -> B -> B[B] -> BB[B] -> empty 

// Note:
// You may assume that the initial row of balls on the table won’t have any 3 or more consecutive balls with the same color.
// The number of balls on the table won't exceed 20, and the string represents these balls is called "board" in the input.
// The number of balls in your hand won't exceed 5, and the string represents these balls is called "hand" in the input.
// Both input strings will be non-empty and only contain characters 'R','Y','B','G','W'.

// https://discuss.leetcode.com/topic/75465/concise-3ms-c-solution
#define MAX_STEP 6 
class Solution {
public:
    int findMinStep(string board, string hand) {
        sort(hand.begin(), hand.end()); 
        int res = helper(board, hand); 
        return res > hand.size() ? -1 : res;
    }
    
    int helper(string b, string h) {
        if (b.empty()) return 0;
        if (h.empty()) return MAX_STEP;
        int res = MAX_STEP;
        for (int i = 0; i < h.size(); i++) {
            int j = 0;
            int n = b.size();
            while (j < n) {
                int k = b.find(h[i], j);
                if (k == string::npos) break;
                if (k < n-1 && b[k] == b[k+1]) { // 2 consecutive balls with same color on board
                    string nextb = shrink(b.substr(0, k) + b.substr(k+2)); // shrink the string until no 3 or more consecutive balls in same color
                    if (nextb.empty()) return 1; // this is the best result for current board, no need to continue
                    string nexth = h;
                    nexth.erase(i, 1); // remove the used ball from hand
                    res = min(res, helper(nextb, nexth) + 1);
                    k++;
                }
                else if (i > 0 && h[i] == h[i-1]) { // 2 balls with same color in hand
                    string nextb = shrink(b.substr(0, k) + b.substr(k+1)); // shrink the string until no 3 or more consecutive balls in same color
                    if (nextb.empty()) return 2;  // this is the best result for current board, no need to continue
                    string nexth = h;
                    nexth.erase(i, 1); // remove the used balls from hand
                    nexth.erase(i-1, 1);
                    res = min(res, helper(nextb, nexth) + 2);
                }
                j = k + 1;
            }
        }
        return res;
    }
    
    string shrink(string s) {
        while(s.size() > 0) {
            int start = 0;
            bool done = true;
            for (int i = 0; i <= s.size(); i++) {
                if (i == s.size() || s[i] != s[start]) {
                    if (i - start >= 3) {
                        s = s.substr(0, start) + s.substr(i);
                        done = false;
                        break;
                    }
                    start = i;
                }
            }
            if (done) break;
        }
        return s;
    }
};

public class Solution {
    public int findMinStep(String board, String hand) {
        List<Character> boardList = new ArrayList<Character>();
        for (char c : board.toCharArray()) {
            boardList.add(c);
        }
        Map<Character,Integer> handMap = new HashMap<>();
        handMap.put('R',0);
        handMap.put('Y',0);
        handMap.put('B',0);
        handMap.put('G',0);
        handMap.put('W',0);
        for (char h : hand.toCharArray()) {
            handMap.put(h, handMap.get(h) + 1);
        }
        return find(boardList, handMap);
    }
    
    private int find(List<Character> board, Map<Character, Integer> hand) {
        cleanupBoard(board);
        if (board.size() == 0) return 0;
        if (empty(hand)) return -1;
        int count = 0;
        int min = Integer.MAX_VALUE;
        for (int i = 0; i<board.size(); i++) {
            char c = board.get(i);
            count++;
            if (i == board.size() - 1 || board.get(i+1) != c) {
                int missing = 3 - count;
                if (hand.get(c) >= missing) {
                    hand.put(c, hand.get(c) - missing);
                    List<Character> smallerBoard = new ArrayList<>(board);
                    for (int j = 0; j<count; j++) {
                        smallerBoard.remove(i-j);
                    }
                    int smallerFind = find(smallerBoard, hand);
                    if ( smallerFind != -1 ) {
                        min = Math.min(smallerFind + missing, min);
                    }
                    hand.put(c, hand.get(c) + missing);
                }
                count = 0;
            }
        }
        return (min == Integer.MAX_VALUE) ? -1 : min;
    }
    
    private void cleanupBoard(List<Character> board) {
        int count = 0;
        boolean cleaned = false;
        for (int i = 0; i<board.size(); i++) {
            char c = board.get(i);
            count++;
            if (i == board.size() - 1 || board.get(i+1) != c) {
                if (count >= 3) {
                    for (int j = 0; j<count; j++) {
                        board.remove(i-j);
                    }
                    cleaned = true;
                    break;
                }
                count = 0;
            }
        }
        if (cleaned) {
            cleanupBoard(board);
        }
    }
    
    private boolean empty(Map<Character,Integer> hand) {
        for (int val : hand.values()) {
            if (val > 0) return false;
        }
        return true;
    }
}
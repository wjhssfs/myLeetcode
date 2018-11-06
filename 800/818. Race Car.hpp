// 818. Race Car
// Your car starts at position 0 and speed +1 on an infinite number line.  (Your car can go into negative positions.)

// Your car drives automatically according to a sequence of instructions A (accelerate) and R (reverse).

// When you get an instruction "A", your car does the following: position += speed, speed *= 2.

// When you get an instruction "R", your car does the following: if your speed is positive then speed = -1 , otherwise speed = 1.  (Your position stays the same.)

// For example, after commands "AAR", your car goes to positions 0->1->3->3, and your speed goes to 1->2->4->-1.

// Now for some target position, say the length of the shortest sequence of instructions to get there.

// Example 1:
// Input: 
// target = 3
// Output: 2
// Explanation: 
// The shortest instruction sequence is "AA".
// Your position goes from 0->1->3.
// Example 2:
// Input: 
// target = 6
// Output: 5
// Explanation: 
// The shortest instruction sequence is "AAARA".
// Your position goes from 0->1->3->7->7->6.
 

// Note:

// 1 <= target <= 10000.


// https://leetcode.com/problems/race-car/discuss/124326/Summary-of-the-BFS-and-DP-solutions-with-intuitive-explanation
public int racecar(int target) {
    Deque<int[]> queue = new LinkedList<>();
    queue.offerLast(new int[] {0, 1}); // starts from position 0 with speed 1
    
    Set<String> visited = new HashSet<>();
    visited.add(0 + " " + 1);
    
    for (int level = 0; !queue.isEmpty(); level++) {
        for(int k = queue.size(); k > 0; k--) {
            int[] cur = queue.pollFirst();  // cur[0] is position; cur[1] is speed
            
            if (cur[0] == target) {
                return level;
            }
            
            int[] nxt = new int[] {cur[0] + cur[1], cur[1] << 1};  // accelerate instruction
            String key = (nxt[0] + " " + nxt[1]);
            
            if (!visited.contains(key) && 0 < nxt[0] && nxt[0] < (target << 1)) {
                queue.offerLast(nxt);
                visited.add(key);
            }
            
            nxt = new int[] {cur[0], cur[1] > 0 ? -1 : 1};  // reverse instruction
            key = (nxt[0] + " " + nxt[1]);
            
            if (!visited.contains(key) && 0 < nxt[0] && nxt[0] < (target << 1)) {
                queue.offerLast(nxt);
                visited.add(key);
            }
        }
    }
    
    return -1;
}

// https://leetcode.com/articles/race-car/

class Solution {
    public int racecar(int target) {
        int[] dp = new int[target + 3];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0; dp[1] = 1; dp[2] = 4;

        for (int t = 3; t <= target; ++t) {
            int k = 32 - Integer.numberOfLeadingZeros(t);
            if (t == (1<<k) - 1) {
                dp[t] = k;
                continue;
            }
            for (int j = 0; j < k-1; ++j)
                dp[t] = Math.min(dp[t], dp[t - (1<<(k-1)) + (1<<j)] + k-1 + j + 2);
            if ((1<<k) - 1 - t < t)
                dp[t] = Math.min(dp[t], dp[(1<<k) - 1 - t] + k + 1);
        }

        return dp[target];  
    }
}

// Dijkstra's 
class Solution {
    public int racecar(int target) {
        int K = 33 - Integer.numberOfLeadingZeros(target - 1);
        int barrier = 1 << K;
        int[] dist = new int[2 * barrier + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[target] = 0;

        PriorityQueue<Node> pq = new PriorityQueue<Node>(
            (a, b) -> a.steps - b.steps);
        pq.offer(new Node(0, target));

        while (!pq.isEmpty()) {
            Node node = pq.poll();
            int steps = node.steps, targ1 = node.target;
            if (dist[Math.floorMod(targ1, dist.length)] > steps) continue;

            for (int k = 0; k <= K; ++k) {
                int walk = (1 << k) - 1;
                int targ2 = walk - targ1;
                int steps2 = steps + k + (targ2 != 0 ? 1 : 0);

                if (Math.abs(targ2) <= barrier && steps2 < dist[Math.floorMod(targ2, dist.length)]) {
                    pq.offer(new Node(steps2, targ2));
                    dist[Math.floorMod(targ2, dist.length)] = steps2;
                }
            }
        }

        return dist[0];
    }
}

class Node {
    int steps, target;
    Node(int s, int t) {
        steps = s;
        target = t;
    }
}
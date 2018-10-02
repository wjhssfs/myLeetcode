// 753. Cracking the Safe
// There is a box protected by a password. The password is n digits, where each letter can be one of the first k digits 0, 1, ..., k-1.

// You can keep inputting the password, the password will automatically be matched against the last n digits entered.

// For example, assuming the password is "345", I can open it when I type "012345", but I enter a total of 6 digits.

// Please return any string of minimum length that is guaranteed to open the box after the entire string is inputted.

// Example 1:
// Input: n = 1, k = 2
// Output: "01"
// Note: "10" will be accepted too.
// Example 2:
// Input: n = 2, k = 2
// Output: "00110"
// Note: "01100", "10011", "11001" will be accepted too.
// Note:
// n will be in the range [1, 4].
// k will be in the range [1, 10].
// k^n will be at most 4096.


// https://leetcode.com/problems/cracking-the-safe/solution/
class Solution {
    public String crackSafe(int n, int k) {
        int M = (int) Math.pow(k, n-1);
        int[] P = new int[M * k];
        for (int i = 0; i < k; ++i)
            for (int q = 0; q < M; ++q)
                P[i*M + q] = q*k + i;

        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < M*k; ++i) {
            int j = i;
            while (P[j] >= 0) {
                ans.append(String.valueOf(j / M));
                int v = P[j];
                P[j] = -1;
                j = v;
            }
        }

        for (int i = 0; i < n-1; ++i)
            ans.append("0");
        return new String(ans);
    }
}

// https://en.wikipedia.org/wiki/De_Bruijn_sequence

class Solution {
    bool dfs(string& result, int goal, unordered_set<string>& visited, int n, int k) {
        if (visited.size() == goal) return true;
        string prev = result.substr(result.size() + 1 - n, n - 1);
        for (int i = 0; i < k; ++i)
        {
            string next = prev + to_string(i);
            if (visited.count(next) == 0) {
                visited.insert(next);
                result += to_string(i);
                if (dfs(result, goal, visited, n, k)) return true;
                result.pop_back();
                visited.erase(next);
            }
        }
        return false;
    }
public:
    string crackSafe(int n, int k) {
        int total = pow(k, n);
        string result(n, '0');
        unordered_set<string> visited{result};
        dfs(result, total, visited, n, k);
        return result;
    }
};


// https://discuss.leetcode.com/topic/114818/de-bruijn-sequence-c
// Find an Eulerian cycle of an (n − 1)-dimensional de Bruijn graph
// Here we construct the sequence for password with length n using all the password with length n-1.
// In the code, v equals k^(n-1) that is the number of password with length n-1 and also the number
// nodes of the graph. Every node has k indegree and k outdegree. For example, n - 1 = 3, k = 3, the
// node with password 002 can go to 020 021 022 and can be reached by 100, 000, 200. The number of
// edges is k^(n-1) * k, that is k^n. That is why the dimension of visited is k^(n-1) by k. After we
// traverse all the edges in the graph, the sequence is constructed.
class Solution {
    int n, k, v;
    vector<vector<bool> > visited;
    string sequence;
public:
    string crackSafe(int n, int k) {
        if (k == 1) return string(n, '0');
        this->n = n;
        this->k = k;
        v = 1;
        for (int i = 0; i < n -1; ++i) v *= k;
        visited.resize(v, vector<bool>(k, false));
        dfs(0);
        return sequence + sequence.substr(0, n - 1);
    }
    
    void dfs(int u) {
        for (int i = 0; i < k; ++i) {
            if (!visited[u][i]) {
                visited[u][i] = true;
                dfs((u * k + i) % v);
                sequence.push_back('0' + i);
            }
        }
    }
};

def de_bruijn(k, n):
    """
    de Bruijn sequence for alphabet k
    and subsequences of length n.
    """
    try:
        # let's see if k can be cast to an integer;
        # if so, make our alphabet a list
        _ = int(k)
        alphabet = list(map(str, range(k)))

    except (ValueError, TypeError):
        alphabet = k
        k = len(k)

    a = [0] * k * n
    sequence = []

    def db(t, p):
        if t > n:
            if n % p == 0:
                sequence.extend(a[1:p + 1])
        else:
            a[t] = a[t - p]
            db(t + 1, p)
            for j in range(a[t - p] + 1, k):
                a[t] = j
                db(t + 1, t)
    db(1, 1)
    return "".join(alphabet[i] for i in sequence)

print(de_bruijn(2, 3))

// https://discuss.leetcode.com/topic/114860/a-brainstorming-python-solution/3
// The tricky part is the proof of this method. Also interesting we can only loop the reversed range
// for y in range(k - 1, -1, -1): otherwise it won't work.

    class Solution(object):
    def crackSafe(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        ans = "0" * (n - 1)
        visits = set()
        for x in range(k ** n):
            current = ans[-n+1:] if n > 1 else ''
            for y in range(k - 1, -1, -1):
                if current + str(y) not in visits:
                    visits.add(current + str(y))
                    ans += str(y)
                    break
        return ans
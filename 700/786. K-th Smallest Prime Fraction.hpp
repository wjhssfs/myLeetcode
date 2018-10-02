// 786. K-th Smallest Prime Fraction

// A sorted list A contains 1, plus some number of primes.  Then, for every p < q in the list, we consider the fraction p/q.

// What is the K-th smallest fraction considered?  Return your answer as an array of ints, where answer[0] = p and answer[1] = q.

// Examples:
// Input: A = [1, 2, 3, 5], K = 3
// Output: [2, 5]
// Explanation:
// The fractions to be considered in sorted order are:
// 1/5, 1/3, 2/5, 1/2, 3/5, 2/3.
// The third fraction is 2/5.

// Input: A = [1, 7], K = 1
// Output: [1, 7]
// Note:

// A will have length between 2 and 2000.
// Each A[i] will be between 1 and 30000.
// K will be between 1 and A.length * (A.length + 1) / 2.

class Solution {
    const double ep = 0.000000000000001;
    int getCount(vector<int>& A, double v) {
        int r = 0;
        for (int i = 1; i < A.size(); ++i) {
            auto it = upper_bound(A.begin(), A.begin() + i, A[i] * v);
            r += it - A.begin();
        }
        return r;
    }
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        double left = A.front() / A.back(), right = 1;
        while ((abs(left - right) > ep)) {
            double mid = (left + right) / 2.0;
            int c = getCount(A, mid);
            if (c >= K) right = mid;
            else left = mid + ep;
        }
        for (int i = 1; i < A.size(); ++i) {
            auto it = lower_bound(A.begin(), A.begin() + i, A[i] * left);
            if (abs((double)(*it) / A[i] - left) < ep) {
                return {*it, A[i]};
            } if (it != A.begin()) {
                --it;
                if (abs((double)(*it) / A[i] - left) < ep) return {*it, A[i]};
            }
        }
        return {};
    }
};


   public int[] kthSmallestPrimeFraction(int[] a, int k) {
        int n = a.length;
        // 0: numerator idx, 1: denominator idx
        PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                int s1 = a[o1[0]] * a[o2[1]];
                int s2 = a[o2[0]] * a[o1[1]];
                return s1 - s2;
            }
        });
        for (int i = 0; i < n-1; i++) {
            pq.add(new int[]{i, n-1});
        }
        for (int i = 0; i < k-1; i++) {
            int[] pop = pq.remove();
            int ni = pop[0];
            int di = pop[1];
            if (pop[1] - 1 > pop[0]) {
                pop[1]--;
                pq.add(pop);
            }
        }

        int[] peek = pq.peek();
        return new int[]{a[peek[0]], a[peek[1]]};
    }
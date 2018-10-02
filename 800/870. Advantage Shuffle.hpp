// 870. Advantage Shuffle
// Given two arrays A and B of equal size, the advantage of A with respect to B is the number of indices i for which A[i] > B[i].

// Return any permutation of A that maximizes its advantage with respect to B.

 

// Example 1:

// Input: A = [2,7,11,15], B = [1,10,4,11]
// Output: [2,11,7,15]
// Example 2:

// Input: A = [12,24,8,32], B = [13,25,32,11]
// Output: [24,32,8,12]
 

// Note:

// 1 <= A.length = B.length <= 10000
// 0 <= A[i] <= 10^9
// 0 <= B[i] <= 10^9

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> index(B.size());
        iota(index.begin(), index.end(), 0);
        sort(index.begin(), index.end(), [&](int a, int b) { return B[a] > B[b];});
        auto C = A;
        sort(C.begin(), C.end(), greater<int>());
        vector<int> left;
        int j = 0;
        for (int i = 0; i < B.size(); ++i) {
            if (C[j] > B[index[i]]) {
                A[index[i]] = C[j];
                ++j;
            }
            else {
                left.push_back(i);
            }
        }
        for (auto p : left) {
            A[index[p]] = C[j++];
        }
        
        return A;
    }
};

class Solution {
    public int[] advantageCount(int[] A, int[] B) {
        Arrays.sort(A);
        int n=A.length;
        int[] res= new int[n];
        PriorityQueue<int[]> pq= new PriorityQueue<>((a,b)->b[0]-a[0]);
        for (int i=0; i<n; i++) pq.add(new int[]{B[i], i});
        int lo=0, hi=n-1;
        while(!pq.isEmpty()){
            int[] cur= pq.poll();
            int idx=cur[1], val=cur[0];
            if (A[hi]>val) res[idx]=A[hi--];
            else res[idx]=A[lo++];
        }
        return res;
    }  
}
// 315 Count of Smaller Numbers After Self
// You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

// Example:

// Given nums = [5, 2, 6, 1]

// To the right of 5 there are 2 smaller elements (2 and 1).
// To the right of 2 there is only 1 smaller element (1).
// To the right of 6 there is 1 smaller element (1).
// To the right of 1 there is 0 smaller element.
// Return the array [2, 1, 1, 0].

// binary index tree https://www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/
class Solution {
    vector<int> tree;
    int MaxVal;
    int read(int idx){
        int sum = 0;
        while (idx > 0){
            sum += tree[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }
    
    void update(int idx ,int val){
        while (idx <= MaxVal){
            tree[idx] += val;
            idx += (idx & -idx);
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result;
        int n = (int)nums.size();
        if(!n) return result;
        result.resize(n);
        int minElem = INT_MAX, maxElem = INT_MIN;
        for(int i : nums) {minElem = min(minElem, i); maxElem = max(maxElem, i);}
        MaxVal = maxElem - minElem + 1;
        tree.resize(MaxVal+1);
        for(int i = n-1; i >= 0; i--){
            int normalizedI = nums[i]-minElem+1;
            result[i] = read(normalizedI-1);
            update(normalizedI, 1);
        }
        return result;
    }
};


def countSmaller(self, nums):
    def sort(enum):
        half = len(enum) / 2
        if half:
            left, right = sort(enum[:half]), sort(enum[half:])
            for i in range(len(enum))[::-1]:
                if not right or left and left[-1][1] > right[-1][1]:
                    smaller[left[-1][0]] += len(right)
                    enum[i] = left.pop()
                else:
                    enum[i] = right.pop()
        return enum
    smaller = [0] * len(nums)
    sort(list(enumerate(nums)))
    return smaller


// https://discuss.leetcode.com/topic/31405/9ms-short-java-bst-solution-get-answer-when-building-bst
class Solution {
    struct Node {
        Node *left, *right;
        int val, sum, dup;
        Node (int v) : val(v), sum(0),dup(1), left(nullptr), right(nullptr){}
    };
    
    Node * insert(int num, Node *node, vector<int> &res, int i, int preSum) {
        if (!node) {
            node = new Node(num);
            res[i] = preSum;
        } else if (num == node->val) {
            ++node->dup;
            res[i] = preSum + node->sum;
        } else if (num > node ->val) {
            node->right = insert(num, node->right, res, i, preSum + node->sum + node->dup);
        } else {
            ++node->sum;
            node->left = insert(num, node->left, res, i, preSum);
        }
        
        return node;
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size());
        Node *root = nullptr;
        for (int i = (int)nums.size() - 1; i >= 0; --i) {
            root = insert(nums[i], root, res, i, 0);
        }
        return res;
    }
};

class Solution {
public:
    class TreeNode {
        public: 
        int val, smallerCnt;
        TreeNode* left, *right;
        TreeNode(int v, int s) : left(NULL), right(NULL), val(v), smallerCnt(s){}
    };
    
    vector<int> countSmaller(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)    return vector<int>();
        vector<int> ret(len, 0); 
        TreeNode* root = NULL;
        
        for(int i = len-1; i >= 0; --i) 
            root = insert(ret, nums[i], i, 0, root);

        return ret;
    }

private:
    TreeNode* insert(vector<int>& ret, int val, int idx, int preSum, TreeNode* node) {
        if(node == NULL) {
            node = new TreeNode(val, 0);
            ret[idx] = preSum;
        }
        else if(node->val > val) {
            node->smallerCnt++;
            node->left = insert(ret, val, idx, preSum, node->left);
        }
        else
            node->right = insert(ret, val, idx, preSum + node->smallerCnt + ((node->val < val)? 1: 0), node->right);
            
        return node;
    }
};

class Solution {
    void sort(vector<pair<int, int>> &m, vector<int> &res) {
        if (m.size() <= 1) return;
        int h = m.size() / 2;
        vector<pair<int, int>> mLeft(m.begin(), m.begin() + h), mRight(m.begin() + h, m.end());
        sort(mLeft, res);
        sort(mRight, res);
        int mi = 0, mli = 0, mri = 0;
        while (mli < mLeft.size() && mri < mRight.size()) {
            if (mLeft[mli].first > mRight[mri].first) {
                res[mLeft[mli].second] += (mRight.size() - mri);
                m[mi++] = mLeft[mli++];
            } else if (mLeft[mli].first <= mRight[mri].first) {
                m[mi++] = mRight[mri++];
            }
        }
        while (mli < mLeft.size()) m[mi++] = mLeft[mli++];
        while (mri < mRight.size()) m[mi++] = mRight[mri++];
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size());
        vector<pair<int, int>> m;
        for (int i = 0; i < nums.size(); ++i) m.push_back(make_pair(nums[i], i));
        sort(m, res);
        return res;
    }
};
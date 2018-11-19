// 493. Reverse Pairs
// Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].

// You need to return the number of important reverse pairs in the given array.

// Example1:

// Input: [1,3,2,3,1]
// Output: 2
// Example2:

// Input: [2,4,3,5,1]
// Output: 3
// Note:
// The length of the given array will not exceed 50,000.
// All the numbers in the input array are in the range of 32-bit integer.

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size());
    }
    
    int mergeSort(vector<int>& nums, size_t start, size_t end) {
        if (start + 1 >= end) return 0;
        size_t mid = start + (end - start) / 2;
        int total = mergeSort(nums, start, mid) + mergeSort(nums, mid, end);
        for (int i = start, j = mid; i < mid; ++i) {
            while (j < end && nums[i] / 2.0 > nums[j]) ++j;
            total += j - mid;
        }
        inplace_merge(nums.begin() + start, nums.begin() + mid, nums.begin() + end);
        return total;
    }
};

class Solution {
public:
    int sort_and_count(vector<int>::iterator begin, vector<int>::iterator end) {
        if (end - begin <= 1)
            return 0;
        auto mid = begin + (end - begin) / 2;
        int count = sort_and_count(begin, mid) + sort_and_count(mid, end);
        for (auto i = begin, j = mid; i != mid; ++i) {
            while (j != end and *i > 2L * *j)
                ++j;
            count += j - mid;
        }
        inplace_merge(begin, mid, end);
        return count;
    }

    int reversePairs(vector<int>& nums) {
        return sort_and_count(nums.begin(), nums.end());
    }
};

// https://discuss.leetcode.com/topic/79227/general-principles-behind-problems-similar-to-reverse-pairs

// 1 BST. can become O(n^2)
class Node {
    int val, cnt;
    Node left, right;
        
    Node(int val) {
        this.val = val;
        this.cnt = 1;
    }
}

private int search(Node root, long val) {
    if (root == null) {
        return 0;
    } else if (val == root.val) {
        return root.cnt;
    } else if (val < root.val) {
        return root.cnt + search(root.left, val);
    } else {
        return search(root.right, val);
    }
}

private Node insert(Node root, int val) {
    if (root == null) {
        root = new Node(val);
    } else if (val == root.val) {
        root.cnt++;
    } else if (val < root.val) {
        root.left = insert(root.left, val);
    } else {
        root.cnt++;
        root.right = insert(root.right, val);
    }
    
    return root;
}

public int reversePairs(int[] nums) {
    int res = 0;
    Node root = null;
        
    for (int ele : nums) {
        res += search(root, 2L * ele + 1);
        root = insert(root, ele);
    }
    
    return res;
}

// 2. BIT 
private int search(int[] bit, int i) {
    int sum = 0;
    
    while (i < bit.length) {
        sum += bit[i];
        i += i & -i;
    }

    return sum;
}

private void insert(int[] bit, int i) {
    while (i > 0) {
        bit[i] += 1;
        i -= i & -i;
    }
}
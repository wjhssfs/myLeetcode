// 360. Sort Transformed Array

// Given a sorted array of integers nums and integer values a, b and c. Apply a function of the form f(x) = ax2 + bx + c to each element x in the array.

// The returned array must be in sorted order.

// Expected time complexity: O(n)

// Example:
// nums = [-4, -2, 2, 4], a = 1, b = 3, c = 5,

// Result: [3, 9, 15, 33]

// nums = [-4, -2, 2, 4], a = -1, b = 3, c = 5

// Result: [-23, -5, 1, 7]

public class Solution {
    public int[] sortTransformedArray(int[] nums, int a, int b, int c) {
        int n = nums.length;
        int[] sorted = new int[n];
        int i = 0, j = n - 1;
        int index = a >= 0 ? n - 1 : 0;
        while (i <= j) {
            if (a >= 0) {
                sorted[index--] = quad(nums[i], a, b, c) >= quad(nums[j], a, b, c) ? quad(nums[i++], a, b, c) : quad(nums[j--], a, b, c);
            } else {
                sorted[index++] = quad(nums[i], a, b, c) >= quad(nums[j], a, b, c) ? quad(nums[j--], a, b, c) : quad(nums[i++], a, b, c);
            }
        }
        return sorted;
    }
    
    private int quad(int x, int a, int b, int c) {
        return a * x * x + b * x + c;
    }
}

class Solution {
public:
	vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
		vector<int> result;
		if (nums.empty()) return result;
		bool reverse = false;
		if (a == 0) {
			if (b < 0) reverse = true;
			for (auto num : nums) result.push_back(f(a, b, c, num));
		}
		else {
			if (a < 0) reverse = true;
			double r = -0.5 * b / a;
			double minDiff = abs(nums[0] - r);
			int m = 0;
			for (int i = 1; i < nums.size(); ++i) {
				if (minDiff > abs(r - nums[i])) {
					minDiff = abs(r - nums[i]);
					m = i;
				}
			}
			result.push_back(f(a, b, c, nums[m]));
			int left = m - 1, right = m + 1;
			for (int i = 1; i < nums.size(); ++i) {
				if (right >= nums.size() || (left >= 0 && abs(nums[left] - r) < abs(nums[right] - r))){
					result.push_back(f(a, b, c, nums[left]));
					--left;
				}
				else {
					result.push_back(f(a, b, c, nums[right]));
					++right;
				}
			}
		}

		if (reverse) {
			for (int i = 0; i < result.size() / 2; ++i) {
				swap(result[i], result[result.size() - 1 - i]);
			}
		}
		return result;
	}
private:
	int f(int a, int b, int c, int x) {
		return a * x * x + b * x + c;
	}
};

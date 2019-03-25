/*
 * [665] Non-decreasing Array
 *
 * https://leetcode.com/problems/non-decreasing-array/description/
 *
 * algorithms
 * Easy (19.69%)
 * Total Accepted:    37.8K
 * Total Submissions: 192K
 * Testcase Example:  '[4,2,3]'
 *
 * 
 * Given an array with n integers, your task is to check if it could become
 * non-decreasing by modifying at most 1 element.
 * 
 *
 *
 * We define an array is non-decreasing if array[i]  holds for every i (1
 *
 * Example 1:
 *
 * Input: [4,2,3]
 * Output: True
 * Explanation: You could modify the first 4 to 1 to get a non-decreasing
 * array.
 *
 *
 *
 * Example 2:
 *
 * Input: [4,2,1]
 * Output: False
 * Explanation: You can't get a non-decreasing array by modify at most one
 * element.
 *
 *
 *
 * Note:
 * The n belongs to [1, 10,000].
 *
 */
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
		int loc = 0, count = 0;

		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] < nums[i - 1]) {
				count++;
				if (count > 1)
					return false;
				else
					loc = i;
			}
		}

		if (count == 0) return true;

		if (loc - 1 == 0 || loc == nums.size() - 1)
			return true;
		else if (nums[loc - 2] < nums[loc])
			return true;
		else if (nums[loc - 1] < nums[loc + 1])
			return true;
		else
			return false;
	}
};

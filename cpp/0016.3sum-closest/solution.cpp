// Created by jasonph at 2025/11/07 18:45
// leetgo: 1.4.15
// https://leetcode.com/problems/3sum-closest/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        // declare variable to track sums

        // two pointer approach 
        // sort the array
        int closestSum = nums[0] + nums[1] + nums[2];
        sort (nums.begin(), nums.end());
        // iterate over the entire array
        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;
            int right = nums.size() - 1;
            // calculate the sum
            // if it equals, just return the sum
            while (left < right) {

                int sum = (nums[i] + nums[left] + nums[right]);
                if (abs(closestSum - target) > abs(sum - target)){
                    closestSum = sum;
                }
                if (sum == target) {
                    return sum;
                }
                else if (sum > target) {
                    right--;
                }
                else {
                    left++;
                }
            }
        }
        // return the sum of 3 integers
        return closestSum;
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);
	int target;
	LeetCodeIO::scan(cin, target);

	Solution *obj = new Solution();
	auto res = obj->threeSumClosest(nums, target);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

// Created by jasonph at 2025/11/15 20:27
// leetgo: 1.4.15
// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int search(vector<int>& nums, int target) {
       
        int left = 0;
        int right = nums.size() -1;

        while (left <= right) {

            int mid = left + (right - left) / 2;
            if (target == nums[mid]) {
                return mid;
            }
            if (nums[right] > nums[mid]) {
                // right side is sorted, let's check if it's here
                if (target > nums[mid] && target <= nums[right]) {
                    // it's in here somewhere
                    left = mid + 1;
                }
                else {
                    right = mid - 1; // not in right side, and not the middle
                }
            }
            else {
                // left side is sorted, let's check if it's in here
                if (target >= nums[left] && target <= nums[mid]) {
                    right = mid - 1;
                }
                else { 
                    left = mid + 1;
                }
            }
        }
        return -1;
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
	auto res = obj->search(nums, target);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

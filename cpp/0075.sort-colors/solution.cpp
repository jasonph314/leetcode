// Created by jasonph at 2025/11/11 21:34
// leetgo: 1.4.15
// https://leetcode.com/problems/sort-colors/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // set up high and low flags, as well as iterator
        int low = 0;
        int high = nums.size() - 1;
        int i = 0;

        while (i <= high) {

            if (nums[i] == 2) {
                swap(nums[i], nums[high]);
                high--;
            }
            else if (nums[i] == 0) {
                swap(nums[i], nums[low]);
                low++;
                i++;
            }
            else {
                i++;

            }
        }
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);

	Solution *obj = new Solution();
	auto res = obj->sortColors(nums);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

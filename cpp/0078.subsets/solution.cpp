// Created by jasonph at 2026/01/05 02:38
// leetgo: 1.4.16
// https://leetcode.com/problems/subsets/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;
using vvi = vector<vector<int>>;

// @lc code=begin

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vvi results;

        function<void(vector<int>, size_t)> backtrack = [&](vector<int> current, size_t index) {
            // base case: index is equal to nums.size()-1
            if (index == nums.size()) {
                // append to current set to results
                results.push_back(current);
                return;
            }
            else {
            // recursive case:
            // 1: include nums[index]
            current.push_back(nums[index]);
            backtrack(current, index + 1);
            // 2: don't include nums[index]
            current.pop_back();
            backtrack(current, index + 1);

            }
        };

        backtrack({}, 0);
        return results;
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);

	Solution *obj = new Solution();
	auto res = obj->subsets(nums);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

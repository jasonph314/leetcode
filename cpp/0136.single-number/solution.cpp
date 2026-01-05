// Created by jasonph at 2025/11/26 13:42
// leetgo: 1.4.15
// https://leetcode.com/problems/single-number/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        // using XOR on all the integers, the duplicates will cancel
        for (auto& n : nums) {

            result ^= n;
        }

        // loop through array, and apply XOR to all
        return result;

        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);

	Solution *obj = new Solution();
	auto res = obj->singleNumber(nums);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

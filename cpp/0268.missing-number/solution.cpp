// Created by jasonph at 2025/11/26 14:50
// leetgo: 1.4.15
// https://leetcode.com/problems/missing-number/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // core concept : because they're indices 0 to N, if we XOR all the indices and numbers, the one without the pair will come out on top
        // each number, pairs with an index, no matter the ordering at the end

        int result = nums.size(); // this guarantees the last + 1 index is XORed

        for (int i = 0; i < nums.size(); i++) {
            result ^= i ^ nums[i];

        }
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
	auto res = obj->missingNumber(nums);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

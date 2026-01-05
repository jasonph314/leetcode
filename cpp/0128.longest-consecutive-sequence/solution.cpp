// Created by jasonph at 2025/11/14 17:06
// leetgo: 1.4.15
// https://leetcode.com/problems/longest-consecutive-sequence/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) { return 0; }
        // declare hashset 
        unordered_set <int> seen;
        // store all values in the hashset
        for (auto& num : nums){
            seen.insert(num);
        } 
        // iterate over nums
        int maximumLength = 0;

        for (auto& num : seen) { 
            // determine start of sequence (if num - 1 doesn't exist)
            if (seen.find(num - 1) == seen.end()) {
                int currentLength = 1;

                // if it does, begin checking if the subsequent numbers exist
                while (seen.find(num + currentLength) != seen.end()) {
                    currentLength++;
                // increment maximumLength
                }
                // adjust maximumLength after each sequence count
                maximumLength = max(maximumLength, currentLength);
            }
        }
        // return maximumLength
        return maximumLength;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);

	Solution *obj = new Solution();
	auto res = obj->longestConsecutive(nums);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

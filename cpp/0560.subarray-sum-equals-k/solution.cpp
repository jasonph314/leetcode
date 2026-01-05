// Created by jasonph at 2025/11/14 13:11
// leetgo: 1.4.15
// https://leetcode.com/problems/subarray-sum-equals-k/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        // declare a hashmap of the prefixCounts
        unordered_map<int, int> prefixCounts;
        // initialize a key value pair of 0 : 1 to represent a different to 0, (sort of like TwoSum)
        prefixCounts[0] = 1;

        // declare a counter variable
        int counter = 0;
        // declare a currentSum variable
        int currentSum = 0;
        // iterate and check if the currentSum - k equals a sum in our hashmap (aka a previousSum)
        for (auto& num : nums) { 
            // if it is, we increment count with the number of times the currentSum was seen

            // accumulate the sum
            currentSum += num;
            if (prefixCounts.count(currentSum - k)) {
                counter += prefixCounts[currentSum - k];
            }
            // store the current sum in our map
            prefixCounts[currentSum]++;
        }
        return counter;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);
	int k;
	LeetCodeIO::scan(cin, k);

	Solution *obj = new Solution();
	auto res = obj->subarraySum(nums, k);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

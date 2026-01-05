// Created by jasonph at 2025/11/14 13:02
// leetgo: 1.4.15
// https://leetcode.com/problems/product-of-array-except-self/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> answer (nums.size(), 1);

        int leftProduct = 1;
        for (int i = 0; i < nums.size(); i++) {
            
            answer[i] = leftProduct;
            leftProduct *= nums[i];

        } 
        
        int rightProduct = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            
            answer[i] *= rightProduct;
            rightProduct *= nums[i];

        } 

        return answer;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);

	Solution *obj = new Solution();
	auto res = obj->productExceptSelf(nums);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

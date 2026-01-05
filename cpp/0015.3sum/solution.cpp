// Created by jasonph at 2025/11/11 21:16
// leetgo: 1.4.15
// https://leetcode.com/problems/3sum/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {


        vector<vector<int>> results;
        //sort
        sort(nums.begin(), nums.end());

        //outer loop -- current sum
        for (int i = 0; i < nums.size(); i++) {

            // handle duplicates for outer loop **avoiding out of bounds check
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            // initialize left and right pointer accordingly
            int left = i + 1;
            int right = nums.size()-1;
             
            // two pointer condition
            while(left < right) {
            // calculate the sum
                int sum = nums[i] + nums[left] + nums[right];
                // balancing conditions on the 0 scale

                if (sum < 0) {
                    left++;
                }
                else if (sum > 0) {
                    right--;
                }
                else {
                    results.push_back({nums[i], nums[left], nums[right]});
                    // handling duplicates for the pointers
                    
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }

                    // advance pointers to guarantee new potential sum
                    right--;
                    left++;
                }
            }
        }
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
	auto res = obj->threeSum(nums);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

// Created by jasonph at 2025/11/06 17:03
// leetgo: 1.4.15
// https://leetcode.com/problems/container-with-most-water/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    // target complexity: O(n) using the Two Pointer algorithm
    int maxArea(vector<int>& height) {
       // declare left and right pointers
        int left = 0;
        int right = height.size()-1;
        // keep track of the maximum AREA
        int maxArea = 0;
        // while the two pointer is valid

        while (left < right){

            // keep track of the current Area
            int currentArea = (right - left)* min(height[left], height[right]); // only account for the smaller height
            maxArea = max(maxArea, currentArea);
            // move the shorter of the two lines to possibly find the next taller height
            // if height_left < height_right
            if (height[left] < height[right]){
                // increment left
                left++;
            }

            // otherwise demcrement left, even if they're equal
            else {
                right--;
            }
        }
        return maxArea;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> height;
	LeetCodeIO::scan(cin, height);

	Solution *obj = new Solution();
	auto res = obj->maxArea(height);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

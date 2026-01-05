// Created by jasonph at 2025/11/19 12:48
// leetgo: 1.4.15
// https://leetcode.com/problems/trapping-rain-water/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

        // two pointer approach, determining which is the limiting wall
        // this determines the area
class Solution {
public:
    int trap(vector<int>& height) {

        // declare pointers that will track which wall is limiting (left or right)

        int left = 0;
        int right = height.size () - 1;
        int tallestLeft = 0;
        int tallestRight = 0;
        int trappedWater = 0;
        
        while (left < right) {
        // control flow -- which wall is shorter, calculate and move that
            if (height[left] < height[right]) {
                tallestLeft = max(height[left], tallestLeft);
                trappedWater += (tallestLeft - height[left]);
                left++;
        
            // at each wall calculate the water at that column
            }
            else {
                // calculate the height from the right
                tallestRight = max(height[right], tallestRight);
                trappedWater += (tallestRight - height[right]);
                right--;

            }
        }
        return trappedWater;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> height;
	LeetCodeIO::scan(cin, height);

	Solution *obj = new Solution();
	auto res = obj->trap(height);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

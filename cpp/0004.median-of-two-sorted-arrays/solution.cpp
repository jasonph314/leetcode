// Created by jasonph at 2025/11/16 01:05
// leetgo: 1.4.15
// https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure the nums1 is the smaller array

        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);

        }

        int m = nums1.size();
        int n = nums2.size();
        int left = 0;
        int right = m;

        while (left <= right) {

            int partitionA = (left + right) / 2;
            int partitionB = (m + n + 1) / 2 - partitionA;

            // Get the boundary elements
            int maxLeftA = (partitionA == 0) ? INT_MIN : nums1[partitionA - 1];
            int minRightA = (partitionA == m) ? INT_MAX : nums1[partitionA];
            int maxLeftB = (partitionB == 0) ? INT_MIN : nums2[partitionB - 1];
            int minRightB = (partitionB == n) ? INT_MAX : nums2[partitionB];

            // Check for valid partition
            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {

                if((m + n ) % 2 == 0) {
                    return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
                } else {
                    return max(maxLeftA, maxLeftB);
                }
            }
            else if (maxLeftA > minRightB) {
                // A's left is too large
                right = partitionA - 1;
            }
            else {
                // A's left is too small
                left = partitionA + 1;

            }
        }
        return 0.0; // should never reach here
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums1;
	LeetCodeIO::scan(cin, nums1);
	vector<int> nums2;
	LeetCodeIO::scan(cin, nums2);

	Solution *obj = new Solution();
	auto res = obj->findMedianSortedArrays(nums1, nums2);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

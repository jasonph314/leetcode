// Created by jasonph at 2025/11/15 18:56
// leetgo: 1.4.15
// https://leetcode.com/problems/koko-eating-bananas/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       // 1. set up binary search bounds
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        int result = right; // worst case: eat at the max speed

        while (left <= right) {
            int mid = left + (right - left) / 2; // candidate speed

            // Step 3: check if the speed works
            if (canFinish(piles, mid, h)) {
                // can finish, but can we go slower?
                result = mid;
                right = mid - 1;
            } else {
                // this speed is too slow
                left = mid + 1;
            }
        }

        return result;
    }

private: 
    // Helper function, can we finish all piles in h hours at speed k?

    bool canFinish (vector<int>& piles, int k, int h) {
        long long hours = 0;
        // calculate total hours
        for (auto& num : piles) {
            hours += (num + k - 1) / k; 
        }
        // if total hours <= h, return true
        return hours <= h;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> piles;
	LeetCodeIO::scan(cin, piles);
	int h;
	LeetCodeIO::scan(cin, h);

	Solution *obj = new Solution();
	auto res = obj->minEatingSpeed(piles, h);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

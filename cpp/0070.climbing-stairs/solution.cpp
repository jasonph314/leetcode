// Created by jasonph at 2025/11/16 03:16
// leetgo: 1.4.15
// https://leetcode.com/problems/climbing-stairs/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int climbStairs(int n) {
       if (n <= 1) return 1;

        vector<int> dp(n+1);

        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2]; //recurrence relation

        }

        return dp[n];
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	int n;
	LeetCodeIO::scan(cin, n);

	Solution *obj = new Solution();
	auto res = obj->climbStairs(n);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

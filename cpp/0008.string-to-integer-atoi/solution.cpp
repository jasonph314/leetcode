// Created by jasonph at 2025/11/27 00:45
// leetgo: 1.4.15
// https://leetcode.com/problems/string-to-integer-atoi/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int myAtoi(string s) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	string s;
	LeetCodeIO::scan(cin, s);

	Solution *obj = new Solution();
	auto res = obj->myAtoi(s);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

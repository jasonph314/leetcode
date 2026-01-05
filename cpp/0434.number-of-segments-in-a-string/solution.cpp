// Created by jasonph at 2025/11/20 22:03
// leetgo: 1.4.15
// https://leetcode.com/problems/number-of-segments-in-a-string/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        bool inSegment = false;

        for (auto c : s) {

            if (c != ' ') {
                if (!inSegment) {
                count++;
                inSegment = true;
                }
            }
            else {
                inSegment = false;

            }
        }
        return count;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	string s;
	LeetCodeIO::scan(cin, s);

	Solution *obj = new Solution();
	auto res = obj->countSegments(s);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

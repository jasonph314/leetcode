// Created by jasonph at 2025/11/18 02:25
// leetgo: 1.4.15
// https://leetcode.com/problems/longest-common-prefix/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if (strs.empty()) return "";

        string result = "";

        for (int i = 0; i < strs[0].length(); i++) {

            char currentChar = strs[0][i];
            for (int j = 0; j < strs.size(); j++) {

                if (i >= strs[j].length() || strs[j][i] != currentChar) {
                    return result;

                }
            }

            // all strings matched at position i;
            result += currentChar;
        }
        return result;
    }

};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<string> strs;
	LeetCodeIO::scan(cin, strs);

	Solution *obj = new Solution();
	auto res = obj->longestCommonPrefix(strs);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

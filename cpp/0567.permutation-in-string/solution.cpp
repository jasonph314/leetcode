// Created by jasonph at 2025/11/10 16:35
// leetgo: 1.4.15
// https://leetcode.com/problems/permutation-in-string/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // declare hashmap to track frequency
        if (s1.size() > s2.size()) return false;
        unordered_map<char, int> window1;
        unordered_map<char, int> window2;
        for (auto& c : s1) {
            window1[c]++;
        }
        for (auto i = 0; i < s1.size(); i++) {
            window2[s2[i]]++;
        }
        // iterate over s2, window condition = same freq of letters
        if(window1 == window2) return true;
        for (int right = s1.size(); right < s2.size(); right++) {

            window2[s2[right]]++;
            int left = right - s1.size();
            window2[s2[left]]--;

            if (window2[s2[left]] == 0) {
                window2.erase(s2[left]);
            }

            if (window1 == window2) return true;
        }
        return false;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	string s1;
	LeetCodeIO::scan(cin, s1);
	string s2;
	LeetCodeIO::scan(cin, s2);

	Solution *obj = new Solution();
	auto res = obj->checkInclusion(s1, s2);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

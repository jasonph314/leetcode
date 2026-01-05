// Created by jasonph at 2025/11/07 23:45
// leetgo: 1.4.15
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        // declare a hashset that checks what's currently in our window
        unordered_set<char> seen;
        // declare the window start at 1 character
        int left = 0;
        int maxLength = 0;
        // iterate over the string
        for (int right = 0; right < s.size(); right++) {
            // check if seen before

            // while yes, shrink the window until the duplicate is gone
            while (seen.contains(s[right])) {
                // remove that character from the set
                seen.erase(s[left]);
                left++;
            }
            // add the character to the set
            seen.insert(s[right]);
            int currentWindow = (right - left + 1); 
            // update the maxLength, which is the max(maxLength, currWindow)
            maxLength = max(currentWindow, maxLength);
        }
        return maxLength;
    }
    

};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	string s;
	LeetCodeIO::scan(cin, s);

	Solution *obj = new Solution();
	auto res = obj->lengthOfLongestSubstring(s);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

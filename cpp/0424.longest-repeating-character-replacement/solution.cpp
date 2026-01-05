// Created by jasonph at 2025/11/15 00:26
// leetgo: 1.4.15
// https://leetcode.com/problems/longest-repeating-character-replacement/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin
class Solution {
public:
    int characterReplacement(string s, int k) {
        // base case: empty string
        if (s.empty()) {
            return 0;
        }
        unordered_map<char, int> freq;
        // initialize maxLength to 1
        int maxLength = 1;
        // initialize maxFreq to 0
        int maxFreq = 0;

        int left = 0;
        // iterate over the string, expanding right bound as long as valid window
        for (int right = 0; right < s.size(); right++) {
            // update frequency of char on right
            freq[s[right]]++; 
            // update maxFreq;
            maxFreq = max(maxFreq, freq[s[right]]);
            // while not valid window
            while (!((right - left + 1) - maxFreq  <= k)) {
                // decrement frequency on the left bound
                freq[s[left]]--;
                // increment left -- shrink window
                left++;
            }
            //update maxLength
            maxLength = max (maxLength, (right-left + 1));
        }
        // loop is done, checked all possibilities
        return maxLength;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	string s;
	LeetCodeIO::scan(cin, s);
	int k;
	LeetCodeIO::scan(cin, k);

	Solution *obj = new Solution();
	auto res = obj->characterReplacement(s, k);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

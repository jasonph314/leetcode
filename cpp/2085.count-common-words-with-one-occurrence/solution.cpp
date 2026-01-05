// Created by jasonph at 2025/11/24 19:44
// leetgo: 1.4.15
// https://leetcode.com/problems/count-common-words-with-one-occurrence/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> w1;
        unordered_map<string, int> w2;
        int counter = 0;

        for (auto& str : words1) {
            w1[str]++;

        }
        for (auto& str: words2) {
            w2[str]++;

        }
        for (auto pair : w2) {

            if (pair.second == 1) {

                if (!w1.contains(pair.first)) {
                    continue;
                }
                else if (w1[pair.first] == 1){
                    counter++;

                }

            }
            else {
                continue;
            }

        }
        return counter;
        
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<string> words1;
	LeetCodeIO::scan(cin, words1);
	vector<string> words2;
	LeetCodeIO::scan(cin, words2);

	Solution *obj = new Solution();
	auto res = obj->countWords(words1, words2);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

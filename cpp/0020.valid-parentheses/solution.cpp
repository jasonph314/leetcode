// Created by jasonph at 2025/11/18 18:41
// leetgo: 1.4.15
// https://leetcode.com/problems/valid-parentheses/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (char c : s) {
            // If opening bracket, push
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            // If closing bracket
            else {
                // Stack empty? No matching opening
                if (st.empty()) {
                    return false;
                }
                
                char top = st.top();
                
                // Check if matches
                if ((c == ')' && top == '(') ||
                    (c == '}' && top == '{') ||
                    (c == ']' && top == '[')) {
                    st.pop();  // Match! Remove opening
                } else {
                    return false;  // Mismatch!
                }
            }
        }
        
        // Stack should be empty (all brackets matched)
        return st.empty();
    }
};
// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	string s;
	LeetCodeIO::scan(cin, s);

	Solution *obj = new Solution();
	auto res = obj->isValid(s);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

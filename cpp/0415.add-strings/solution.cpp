// Created by jasonph at 2025/11/20 11:44
// leetgo: 1.4.15
// https://leetcode.com/problems/add-strings/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    string addStrings(string num1, string num2) {

        string result = "";
        
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        // we can iterate through each num string
        int carry = 0;
        
        while (i >= 0 || j>= 0 || carry) {

        // convert everything to a char and extract the true value using ASCII
            int digit1 =  (i >= 0) ? charToInt(num1[i]) : 0;
            int digit2 =  (j >= 0) ? charToInt(num2[j]) : 0;

            int sum = digit1 + digit2 + carry;

            carry = sum / 10;
            int digit = sum % 10;
            char S = digit + '0';

            result += S;
            i--;
            j--;
        }
        reverse(result.begin(), result.end());

        return result;


    }
    int charToInt (char c) {

        int digit = c - '0';
        return digit;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	string num1;
	LeetCodeIO::scan(cin, num1);
	string num2;
	LeetCodeIO::scan(cin, num2);

	Solution *obj = new Solution();
	auto res = obj->addStrings(num1, num2);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

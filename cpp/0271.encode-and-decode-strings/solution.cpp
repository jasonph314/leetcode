// Created by jasonph at 2025/11/14 18:03
// leetgo: 1.4.15
// https://leetcode.com/problems/encode-and-decode-strings/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {


        string encoded = "";
        // iterate over the vector and concatenate to the empty string
        for (auto& str : strs){
            int len = str.length();
            string lenStr = to_string(len);
            encoded += lenStr + "#" + str;

        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        if (s.empty()){

            return {};
        }
        vector<string> decoded;
        int i = 0;

        while (i < s.size()){

        // find the # delimiter
        int delimPos = s.find('#', i);
       
        if (delimPos == string::npos) break;
        // extract the lenStr encoding
        int lenStr = stoi(s.substr(i, delimPos - i));

        int startPos = delimPos + 1;

        // extract the substr needed
        string str = s.substr(startPos, lenStr);

        decoded.push_back(str);
        i = startPos + lenStr;
        }

        return decoded;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

// @lc code=end

// Warning: this is a manual question, the generated test code may be incorrect.
int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<string> dummy_input;
	LeetCodeIO::scan(cin, dummy_input);

	Solution *obj = new Solution();
	auto res = obj->encode(dummy_input);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

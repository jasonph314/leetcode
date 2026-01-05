// Created by jasonph at 2025/11/05 18:18
// leetgo: 1.4.15
// https://leetcode.com/problems/happy-number/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool isHappy(int n) {
       
	// declare a hash set to track if the number exists in the loop
	unordered_set<int> seen;
	// use modulo to parse the individual digits and integer division
	while (1)
	{
		int sum = sumOfSquares(n);
		// if it equals to 1, return true
		if (sum == 1) return true;
		// if the number exists in our hashset , return false
		if (seen.contains(sum))
      		{
			return false;
		} 
		seen.insert(sum);
		// update n
		n = sum;

	}

    }
	// generating a helper function to calculate the sum of squares
	int sumOfSquares(int n)
	{
		int sum = 0;
		while (n > 0)
		{
			int digit = n % 10; // extract last digit
			n = n / 10;  // remove last digit
			sum += digit * digit;
		}
		return sum;
	}
	
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	int n;
	LeetCodeIO::scan(cin, n);

	Solution *obj = new Solution();
	auto res = obj->isHappy(n);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

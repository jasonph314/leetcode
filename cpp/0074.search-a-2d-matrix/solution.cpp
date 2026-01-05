// Created by jasonph at 2025/11/15 16:29
// leetgo: 1.4.15
// https://leetcode.com/problems/search-a-2d-matrix/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Step 1: binary search to find row candidate
        int top = 0;
        int bottom = m - 1;
        while (top <= bottom) {
            int mid = top + (bottom - top) / 2;

            // check if target is in bounds of row
            if (target < matrix[mid][0]) {

                bottom = mid - 1; // too small, search upper rows
            }
            else if (target > matrix[mid][n-1]) {

                top = mid + 1; // number is bigger, search lower
            } 
            else {
                return binarySearchRow(matrix[mid], target);
            }
        }
        return false;
    }
private: 
    bool binarySearchRow(vector<int>& row, int target) {

        int left = 0;
        int right = row.size() - 1;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (target < row[mid]){
                right = mid - 1;

            }
            else if (target > row[mid]) {
                left = mid + 1;
            }
            else {
                return true;
            }

        }
        return false;

    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<vector<int>> matrix;
	LeetCodeIO::scan(cin, matrix);
	int target;
	LeetCodeIO::scan(cin, target);

	Solution *obj = new Solution();
	auto res = obj->searchMatrix(matrix, target);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

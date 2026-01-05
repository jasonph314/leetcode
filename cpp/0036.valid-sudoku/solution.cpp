// Created by jasonph at 2025/11/14 23:23
// leetgo: 1.4.15
// https://leetcode.com/problems/valid-sudoku/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // declare vector of sets to store "seens"
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> columns(9);
        vector<unordered_set<char>> box(9);
        

        // iterate over the rows 
        for (int i = 0; i < 9; i++) {

            // iterate through the columns
            for (int j = 0; j < 9; j++) {
                // if it's a blank ".", we skip over it
                char c = board[i][j];
                int boxIndex = ((i/3) * 3) + (j/3);
                if (c == '.') {
                    continue;
                }
                // if it's exists in either of the sets, we return false
                if (rows[i].contains(c) || columns[j].contains(c) || box[boxIndex].contains(c)) {
                    return false;

                }

                rows[i].insert(c);
                columns[j].insert(c);
                box[boxIndex].insert(c);

            }
        }
        // finishing the vector means return true
        return true;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<vector<char>> board;
	LeetCodeIO::scan(cin, board);

	Solution *obj = new Solution();
	auto res = obj->isValidSudoku(board);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

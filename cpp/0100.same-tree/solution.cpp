// Created by jasonph at 2025/11/19 12:40
// leetgo: 1.4.15
// https://leetcode.com/problems/same-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // ultimate case -- no nodes
        if (!q && !p) {
            return true;

        }
        // ultimate false -- if uneven nodes
        if (!q || !p) {
            return false;

        }
        // early out condition -- node values not equal, return false
        if (q->val != p->val){
            return false;

        }

        // recursive case, do the same checks on each sub tree, if it reaches the past the bottom, true value will bubble up
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	TreeNode* p;
	LeetCodeIO::scan(cin, p);
	TreeNode* q;
	LeetCodeIO::scan(cin, q);

	Solution *obj = new Solution();
	auto res = obj->isSameTree(p, q);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

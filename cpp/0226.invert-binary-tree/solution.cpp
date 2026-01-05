// Created by jasonph at 2025/11/26 16:11
// leetgo: 1.4.15
// https://leetcode.com/problems/invert-binary-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // simple tree case -> only left and right, swap them
        if (!root) {
            return root;
        }

        swap(root->left, root->right);
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);

        return root;
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	TreeNode* root;
	LeetCodeIO::scan(cin, root);

	Solution *obj = new Solution();
	auto res = obj->invertTree(root);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

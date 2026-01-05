// Created by jasonph at 2025/11/28 15:30
// leetgo: 1.4.15
// https://leetcode.com/problems/diameter-of-binary-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int diameter = 0; // Global tracker

    int height (TreeNode* root) {
        // calculate the heights of each subtree
        // we'll add them together at the end

        if (!root) return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        diameter = max(diameter, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);

        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	TreeNode* root;
	LeetCodeIO::scan(cin, root);

	Solution *obj = new Solution();
	auto res = obj->diameterOfBinaryTree(root);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

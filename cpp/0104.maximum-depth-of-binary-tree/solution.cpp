// Created by jasonph at 2025/11/26 15:04
// leetgo: 1.4.15
// https://leetcode.com/problems/maximum-depth-of-binary-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // base case, we have an empty root
        // or what if have just one node
        if (!root) {
            return 0;
        }

        int leftSide = maxDepth(root->left);
        int rightSide = maxDepth(root->right);

        return 1 + max(leftSide, rightSide);
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	TreeNode* root;
	LeetCodeIO::scan(cin, root);

	Solution *obj = new Solution();
	auto res = obj->maxDepth(root);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

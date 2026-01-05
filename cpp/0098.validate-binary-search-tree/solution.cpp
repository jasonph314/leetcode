// Created by jasonph at 2025/11/19 20:57
// leetgo: 1.4.15
// https://leetcode.com/problems/validate-binary-search-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST (root, LONG_MIN, LONG_MAX);

    }

    bool isValidBST (TreeNode* root, long min, long max) {
        
        if (!root) {
            return true;

        }

        // check if current node violates constraints
        
        if (root->val <= min || root->val >= max){
            return false;

        }

        bool leftValid = isValidBST(root->left, min, root->val);
        bool rightValid = isValidBST(root->right, root->val, max);


        return leftValid && rightValid;

    }
};


// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	TreeNode* root;
	LeetCodeIO::scan(cin, root);

	Solution *obj = new Solution();
	auto res = obj->isValidBST(root);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

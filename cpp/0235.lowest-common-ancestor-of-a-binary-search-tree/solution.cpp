// Created by jasonph at 2025/11/19 22:40
// leetgo: 1.4.15
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {


        // if both p and q are less, LCA is in left
        if (p->val < root->val && q->val < root->val){
            return lowestCommonAncestor (root->left, p, q);

        }

        // if p and q are greater, LCA is in the right subtree
        if (p->val > root->val && q->val > root->val){
            return lowestCommonAncestor (root->right, p, q);

        }
        // otherwise: split OR root is p/q -> root is LCA
        return root;
    }
};

// @lc code=end

// Warning: this is a manual question, the generated test code may be incorrect.
int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	TreeNode* root;
	LeetCodeIO::scan(cin, root);
	int p;
	LeetCodeIO::scan(cin, p);
	int q;
	LeetCodeIO::scan(cin, q);

	Solution *obj = new Solution();
	auto res = obj->lowestCommonAncestor(root, p, q);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

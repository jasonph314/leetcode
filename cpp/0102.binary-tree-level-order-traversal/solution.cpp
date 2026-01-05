// Created by jasonph at 2025/11/11 00:05
// leetgo: 1.4.15
// https://leetcode.com/problems/binary-tree-level-order-traversal/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // edgecases for null ptr and empty tree
        if (root == NULL) {
            return {};
        }
        // declare return variable called results 
        vector<vector<int>> results;
        // declare two queues, currQ, nextQ
        queue<TreeNode*> currQ;
        currQ.push(root);
       
        // initialize level
        int level = 0;

        // check for children, if yes, push to nextQ
        // while loop -- condition is nextQ cannot be empty aka "still things to visit"
        while (!currQ.empty()) {
            int levelSize = currQ.size(); // handles current levels
            vector<int> currentLevel;
            // iterate through currQ
            for (int i = 0; i < levelSize; i++) {
                //append the value to results[level]
                TreeNode* node = currQ.front(); // returns the address of the node
                currQ.pop();
                currentLevel.push_back(node->val);
                // add the children for the next level
                if (node->left != nullptr) {
                    currQ.push(node->left);
                }
                if (node->right != nullptr) {
                    currQ.push(node->right);
                }

            }
            // increment level
            results.push_back(currentLevel);
        }
        // return results
        return results;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	TreeNode* root;
	LeetCodeIO::scan(cin, root);

	Solution *obj = new Solution();
	auto res = obj->levelOrder(root);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

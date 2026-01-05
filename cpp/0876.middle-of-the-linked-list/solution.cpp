// Created by jasonph at 2025/11/17 11:41
// leetgo: 1.4.15
// https://leetcode.com/problems/middle-of-the-linked-list/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next){

            slow = slow->next;
            fast = fast->next->next;

        }

        return slow;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	ListNode* head;
	LeetCodeIO::scan(cin, head);

	Solution *obj = new Solution();
	auto res = obj->middleNode(head);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

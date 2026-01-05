// Created by jasonph at 2025/11/16 17:59
// leetgo: 1.4.15
// https://leetcode.com/problems/reverse-linked-list/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // base case, we have no head, or our head points to nothing (aka we're done)
        if (!head || !head->next) {
            return head;
        }

        ListNode* newHead = reverseList(head->next);

        // recursive case 
        head->next->next = head;
        head->next = nullptr;

        // set a temp node to hold the information of next, then we reverse the next one to point at the current, and then we point at null
        return newHead;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	ListNode* head;
	LeetCodeIO::scan(cin, head);

	Solution *obj = new Solution();
	auto res = obj->reverseList(head);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

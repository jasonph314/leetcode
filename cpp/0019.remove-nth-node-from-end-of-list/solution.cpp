// Created by jasonph at 2025/11/16 23:02
// leetgo: 1.4.15
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       // initialize a dummy node to handle edge cases (remove the head) -- we need the one before it
        ListNode* dummy  = new ListNode(0);
        dummy->next = head;

        // move pointer1 n+1 away from pointer2
        ListNode* pointer1 = dummy;
        ListNode* pointer2 = dummy;

        for (int i = 0; i < n + 1; i++) {
            pointer1 = pointer1->next;

        }
        // while pointer1 is not null
        while (pointer1) {

            // move the pointers in tandem
            pointer1 = pointer1->next;
            pointer2 = pointer2->next;

        }
        // once null, we're one before the desired node
        // set its pointer to point to the node after it
        pointer2->next = pointer2->next->next;
        return dummy->next;

    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	ListNode* head;
	LeetCodeIO::scan(cin, head);
	int n;
	LeetCodeIO::scan(cin, n);

	Solution *obj = new Solution();
	auto res = obj->removeNthFromEnd(head, n);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

// Created by jasonph at 2025/11/16 19:56
// leetgo: 1.4.15
// https://leetcode.com/problems/linked-list-cycle/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool hasCycle(ListNode *head) {

        // edge case
        if (!head || !head->next) {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            if (slow == fast) {
                return true;
            }

            slow = slow->next;
            fast = fast->next->next;

        }
        return false;
        
    }
};

// @lc code=end

// Warning: this is a manual question, the generated test code may be incorrect.
int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	ListNode* head;
	LeetCodeIO::scan(cin, head);
	int pos;
	LeetCodeIO::scan(cin, pos);

	Solution *obj = new Solution();
	auto res = obj->hasCycle(head, pos);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

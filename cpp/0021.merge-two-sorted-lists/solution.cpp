// Created by jasonph at 2025/11/16 19:25
// leetgo: 1.4.15
// https://leetcode.com/problems/merge-two-sorted-lists/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        // declare a dummy node to be returned
        ListNode* dummy = new ListNode(0);
        // current starts at dummy
        ListNode* current = dummy;

        // while both lists have nodes to cover
        while (list1 && list2) {
            // compare the values
            if (list1->val <= list2->val) {
                    current->next = list1;
                    list1 = list1->next   ;
            }
            else {
                    current->next = list2;
                    list2 = list2->next;
            }

                    current = current->next;
        }

        current->next = list1 ? list1 : list2;
        return dummy->next; // our head is pointing here
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	ListNode* list1;
	LeetCodeIO::scan(cin, list1);
	ListNode* list2;
	LeetCodeIO::scan(cin, list2);

	Solution *obj = new Solution();
	auto res = obj->mergeTwoLists(list1, list2);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

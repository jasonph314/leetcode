// Created by jasonph at 2025/11/17 18:30
// leetgo: 1.4.15
// https://leetcode.com/problems/palindrome-linked-list/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool isPalindrome(ListNode* head) {

        // use slow and fast pointer to find the center
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

        }
        // for odd length list
        if (fast != nullptr) {
            slow = slow->next;
        }

        ListNode* reversed = reverseLinkedList(slow);

        // do a comparision - loop invariant = "list1 and list2 have nodes/are nodes"
        return listComparision (head, reversed);
        
    }

private:
    ListNode* reverseLinkedList(ListNode* head) {

        ListNode* prev = nullptr;
        ListNode* current = head;

        while (current != nullptr) {
            ListNode* temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;

        }

        return prev;

    }
    bool listComparision(ListNode* list1, ListNode* list2) {

        while (list1 && list2) {
            if (list1->val != list2->val) {
                return false;
            } 

            list1 = list1->next;
            list2 = list2->next;
        }
        return true;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	ListNode* head;
	LeetCodeIO::scan(cin, head);

	Solution *obj = new Solution();
	auto res = obj->isPalindrome(head);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

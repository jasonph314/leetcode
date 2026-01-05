// Created by jasonph at 2025/11/18 16:17
// leetgo: 1.4.15
// https://leetcode.com/problems/kth-largest-element-in-a-stream/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {

            minHeap.push(num);

            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        
        if (minHeap.size() > k) {
            minHeap.pop();
        }

        return minHeap.top();
        
    }

private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<string> method_names;
	LeetCodeIO::scan(cin, method_names);

	KthLargest *obj;
	const unordered_map<string, function<void()>> methods = {
		{ "KthLargest", [&]() {
			int k; LeetCodeIO::scan(cin, k); cin.ignore();
			vector<int> nums; LeetCodeIO::scan(cin, nums); cin.ignore();
			int numsSize; LeetCodeIO::scan(cin, numsSize); cin.ignore();
			obj = new KthLargest(k, nums, numsSize);
			out_stream << "null,";
		} },
		{ "add", [&]() {
			int val; LeetCodeIO::scan(cin, val); cin.ignore();
			LeetCodeIO::print(out_stream, obj->add(val)); out_stream << ',';
		} },
	};
	cin >> ws;
	out_stream << '[';
	for (auto &&method_name : method_names) {
		cin.ignore(2);
		methods.at(method_name)();
	}
	cin.ignore();
	out_stream.seekp(-1, ios_base::end); out_stream << ']';
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

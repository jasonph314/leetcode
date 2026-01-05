// Created by jasonph at 2025/11/18 19:06
// leetgo: 1.4.15
// https://leetcode.com/problems/min-stack/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class MinStack {
private:
    vector<pair<int, int>> stack;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (stack.empty()) {
            stack.push_back({val,val});
        }
        else {
        int prevMin = stack.back().second; 
        int newMin = min (val, prevMin);
        stack.push_back({val, newMin});
        }
    }
    
    void pop() {
        stack.pop_back();
        
    }
    
    int top() {
        return stack.back().first; 
        
    }
    
    int getMin() {
        return stack.back().second; 
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<string> method_names;
	LeetCodeIO::scan(cin, method_names);

	MinStack *obj;
	const unordered_map<string, function<void()>> methods = {
		{ "MinStack", [&]() {
			cin.ignore();
			obj = new MinStack();
			out_stream << "null,";
		} },
		{ "push", [&]() {
			int val; LeetCodeIO::scan(cin, val); cin.ignore();
			obj->push(val);
			out_stream << "null,";
		} },
		{ "pop", [&]() {
			cin.ignore();
			obj->pop();
			out_stream << "null,";
		} },
		{ "top", [&]() {
			cin.ignore();
			LeetCodeIO::print(out_stream, obj->top()); out_stream << ',';
		} },
		{ "getMin", [&]() {
			cin.ignore();
			LeetCodeIO::print(out_stream, obj->getMin()); out_stream << ',';
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

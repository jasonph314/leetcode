// Created by jasonph at 2025/11/16 00:00
// leetgo: 1.4.15
// https://leetcode.com/problems/time-based-key-value-store/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class TimeMap {
private: 
       unordered_map<string , vector<pair<int, string>>> store; 

public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {

        store[key].push_back({timestamp, value});

    }
    
    string get(string key, int timestamp) {
        
        // edge case: key doesn't exist
        if (store.find(key) == store.end()) {
            return "";
        }

        // get the vector for this key
        vector<pair<int, string>>& values = store[key]; // reference to the vector stored at store[key]

        // binary search
        int left = 0;
        int right = values.size() - 1;
        string result = "";

        while (left <= right) {

            int mid = left + (right - left) / 2;
            if (values[mid].first <= timestamp) {
                // this timestamp works! save it and search for a larger one

                result = values[mid].second;
                left = mid + 1;
            } else {

                // this timestamp is too large
                right = mid - 1; // search left
            }
        }
        return result;

    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<string> method_names;
	LeetCodeIO::scan(cin, method_names);

	TimeMap *obj;
	const unordered_map<string, function<void()>> methods = {
		{ "TimeMap", [&]() {
			cin.ignore();
			obj = new TimeMap();
			out_stream << "null,";
		} },
		{ "set", [&]() {
			string key; LeetCodeIO::scan(cin, key); cin.ignore();
			string value; LeetCodeIO::scan(cin, value); cin.ignore();
			int timestamp; LeetCodeIO::scan(cin, timestamp); cin.ignore();
			obj->set(key, value, timestamp);
			out_stream << "null,";
		} },
		{ "get", [&]() {
			string key; LeetCodeIO::scan(cin, key); cin.ignore();
			int timestamp; LeetCodeIO::scan(cin, timestamp); cin.ignore();
			LeetCodeIO::print(out_stream, obj->get(key, timestamp)); out_stream << ',';
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

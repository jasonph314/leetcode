// Created by jasonph at 2025/11/18 21:10
// leetgo: 1.4.15
// https://leetcode.com/problems/daily-temperatures/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        if (temperatures.size() == 0) {
            return {};

        }
        if (temperatures.size() == 1) {
            return {0};

        }
        // declare an answer array to be returned

        vector<int> answer(temperatures.size());
        // this stores (temperature, day "index")
        stack<pair<int, int>> visited;

        for (int i = 0; i < temperatures.size(); i++) {

            int currTemp = temperatures[i];
            while (!visited.empty() && currTemp > visited.top().first) {
                int prevDay = visited.top().second;
                // if current day temp is greater than previous day temp (on stack) note that in answer
                answer[prevDay] = (i - prevDay);
                visited.pop();

            }

                visited.push({currTemp, i});
        }
        return answer;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> temperatures;
	LeetCodeIO::scan(cin, temperatures);

	Solution *obj = new Solution();
	auto res = obj->dailyTemperatures(temperatures);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

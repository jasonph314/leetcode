// Created by jasonph at 2025/11/24 19:30
// leetgo: 1.4.15
// https://leetcode.com/problems/teemo-attacking/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

/* Brainstorm

- if the difference between time timeSeries[i] and timeSeries[i-1] >= duration given
then we just increment the totalDuration by the duration given
- otherwise, we should increment by the difference in the two


[1, 2, 5, 9, 12], duration = 4

i = 1, totalDuration = 1
i = 2, totalDuration = 1 + 3
i = 3, totalDuration = 1 + 3 + 4.. so on so forth
we can end the loop once we're on the last element -- invariant being that there is nothing to check against anymore
*/


// @lc code=begin

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {

        int totalDuration = 0;
        // iterate through the loop
        for (int i = 1; i < timeSeries.size(); i++) {
            // compare the current with previous
            if ((timeSeries[i] - timeSeries[i-1]) >= duration) {
            // if greater or equal to duration given, add duration
                totalDuration += duration;
            }
            else {
            // otherwise add the difference between times
                totalDuration += (timeSeries[i] - timeSeries[i-1]);

            }
        }
        return totalDuration + duration;
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> timeSeries;
	LeetCodeIO::scan(cin, timeSeries);
	int duration;
	LeetCodeIO::scan(cin, duration);

	Solution *obj = new Solution();
	auto res = obj->findPoisonedDuration(timeSeries, duration);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

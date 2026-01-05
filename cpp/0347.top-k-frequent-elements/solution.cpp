// Created by jasonph at 2025/11/10 18:43
// leetgo: 1.4.15
// https://leetcode.com/problems/top-k-frequent-elements/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // declare a hashmap called freq to count -- called freq
        unordered_map<int, int> freq;
        // declare a results vector to be returned -- called results
        vector<int> results;
        // declare an vector of vector of ints, to iterate backwards from -- called buckets 
        vector<vector<int>> buckets (nums.size() + 1); // guaranteed size of nums, 0 index never used


        // iterate over the array of nums
        for (auto& i : nums){
            // add to the hashmap and increment value to track frequency
            freq[i]++;
        }
        // iterate over the hashmap
        for(auto& pairs : freq) {
            // store ints, based on frequency. frequency translates to index. push into buckets vector
            buckets[pairs.second].push_back(pairs.first);
        }
        // iterate backwards over the array to capture highest frequency elements
        for(int i = buckets.size() - 1; i > 0; i--) {
            // nested loop to capture subgroups of same frequency
            for (int j = 0; j < buckets[i].size(); j++) {

                results.push_back(buckets[i][j]);
                // check if number of elements in results equals k, then we're done
                }
                if (results.size() == k) {
                    return results;
            }
        } 
        // return results
        return results;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);
	int k;
	LeetCodeIO::scan(cin, k);

	Solution *obj = new Solution();
	auto res = obj->topKFrequent(nums, k);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

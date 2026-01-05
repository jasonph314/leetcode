// Created by jasonph at 2025/11/20 18:09
// leetgo: 1.4.15
// https://leetcode.com/problems/evaluate-division/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
private:
    // finding the path using DFS
    double dfs(string current, string target, unordered_map<string, vector<pair<string, double>>>& graph, unordered_set<string>& visited, double product){
        // base case -- target is found
        if (current == target) {
            return product;
        }
        visited.insert(current);

        for (auto& [neighbor, weight] : graph[current]) {

            if (visited.count(neighbor) == 0) {
                double result = dfs(neighbor, target, graph, visited, product*weight);
                if (result != -1.0){
                    return result;

                }
            }
        }

        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        vector<double> answer;
        // build an adjacency list
        unordered_map<string, vector<pair<string, double>>> graph;

        for (int i = 0; i < equations.size(); i++) {
            string A = equations[i][0];
            string B = equations[i][1];

            graph[A].push_back({B, values[i]});
            graph[B].push_back({A, 1.0/values[i]});

        }

        for (auto& query : queries){
            string start = query[0];
            string end = query[1];
            
            // edge case: doesn't exist
            if (graph.count(start) == 0 || graph.count(end) == 0) {
                answer.push_back(-1.0);
                continue;

            }

            if (start == end) {
                answer.push_back(1.0);
                continue;
            }

            unordered_set<string> visited;
            double result = dfs(start, end, graph, visited, 1.0);
            answer.push_back(result);

        }
        return answer;

    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<vector<string>> equations;
	LeetCodeIO::scan(cin, equations);
	vector<double> values;
	LeetCodeIO::scan(cin, values);
	vector<vector<string>> queries;
	LeetCodeIO::scan(cin, queries);

	Solution *obj = new Solution();
	auto res = obj->calcEquation(equations, values, queries);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

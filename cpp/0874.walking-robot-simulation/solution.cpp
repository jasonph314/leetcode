// Created by jasonph at 2025/11/20 00:26
// leetgo: 1.4.15
// https://leetcode.com/problems/walking-robot-simulation/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {


private:
    // all obstacles
    set<pair<int, int>> obstacle_set;
    // direction vectors
    vector<pair<int, int>> dir_vector = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        // store all the obstacles that we know immediately
        for (const auto& obs : obstacles) {
            obstacle_set.insert({obs[0], obs[1]});

        }

        int x = 0, y = 0;
        int max_dist = 0;

        // main loop
        
        int direction = 0;
        for (int i = 0; i < commands.size(); i++){

            if (commands[i] == -1) {
                direction = (direction + 1) % 4;

            }
            else if (commands[i] == -2) {
                direction = (direction + 3) % 4;
            }

            else {
                for (int j = 0; j < commands[i]; j++){
                    int next_x = x + dir_vector[direction].first;
                    int next_y = y + dir_vector[direction].second;
                    
                    if (obstacle_set.contains({next_x, next_y})){
                        break;

                    }
                    
                    x = next_x;
                    y = next_y;

                    int currentDistance = (x*x + y*y);
                    max_dist = max(currentDistance, max_dist);
                }

            }
        }

        return max_dist;

    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> commands;
	LeetCodeIO::scan(cin, commands);
	vector<vector<int>> obstacles;
	LeetCodeIO::scan(cin, obstacles);

	Solution *obj = new Solution();
	auto res = obj->robotSim(commands, obstacles);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

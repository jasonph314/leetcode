// Created by jasonph at 2025/11/20 14:01
// leetgo: 1.4.15
// https://leetcode.com/problems/number-of-orders-in-the-backlog/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        // declare backlogs for buys and sells, which gets iteratively filled
        // each node should have a price and amount. everything is sorted by the price
        const int MOD = 1e9 + 7;
        priority_queue<pair<int, int>> buyBacklog;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> sellBacklog; 

        // main logic -- matching prices 
        for (auto e : orders) {

            int orderType = e[2];
            int price = e[0];
            int amount = e[1];
            
            // if orderType is buy, check the sell backlog
            if (orderType == 0) {
                // search lowest price (left to right)

                while (amount > 0 && !sellBacklog.empty() && sellBacklog.top().first <= price){

                    auto [sellPrice, sellAmount] = sellBacklog.top();
                    sellBacklog.pop();

                    int matched = min (amount, sellAmount);
                    amount -= matched;
                    sellAmount -= matched;

                    if (sellAmount > 0) {
                        sellBacklog.push({sellPrice, sellAmount});

                    }
                    
                }

                if (amount > 0) {
                    buyBacklog.push({price, amount});

                }

            }
            // else if selling, check the buy backlog
            else if (orderType == 1) {
                // search the highest buy price (right to left)
                while (amount > 0 && !buyBacklog.empty() && buyBacklog.top().first >= price) {

                auto [buyPrice, buyAmount] = buyBacklog.top();
                buyBacklog.pop();

                int matched = min(amount, buyAmount);
                amount -= matched;
                buyAmount -= matched;

                if (buyAmount > 0){
                        buyBacklog.push({buyPrice, buyAmount});

                }

                }

                if (amount > 0) {
                    sellBacklog.push({price, amount});

                }
            }
        }

        // after all the orders have been processed
        long long total = 0;
        while (!sellBacklog.empty()){
            total += sellBacklog.top().second;
            sellBacklog.pop();

        }
        while (!buyBacklog.empty()){
            total += buyBacklog.top().second;
            buyBacklog.pop();
        }
        // at the end, we should check the sizes of our backlogs % (10^9 + 1)
        return total % MOD;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<vector<int>> orders;
	LeetCodeIO::scan(cin, orders);

	Solution *obj = new Solution();
	auto res = obj->getNumberOfBacklogOrders(orders);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

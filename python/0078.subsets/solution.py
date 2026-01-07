# Created by jasonph at 2026/01/06 13:12
# leetgo: 1.4.16
# https://leetcode.com/problems/subsets/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        results = []

        def backtrack(current, index):
            if index == len(nums):
                results.append(current[:])
                return
            
            current.append(nums[index))
            backtrack(current, index + 1)
            current.pop()
            backtrack(current, index + 1)

        backtrack([], 0)
        return results
        

# @lc code=end

if __name__ == "__main__":
    nums: List[int] = deserialize("List[int]", read_line())
    ans = Solution().subsets(nums)
    print("\noutput:", serialize(ans, "integer[][]"))

# Created by jasonph at 2025/11/15 15:49
# leetgo: 1.4.15
# https://leetcode.com/problems/3sum/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        

# @lc code=end

if __name__ == "__main__":
    nums: List[int] = deserialize("List[int]", read_line())
    ans = Solution().threeSum(nums)
    print("\noutput:", serialize(ans, "integer[][]"))

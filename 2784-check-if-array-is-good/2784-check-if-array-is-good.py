class Solution:
    def isGood(self, nums):
        n = max(nums)
        if len(nums) != n + 1:
            return False

        nums.sort()
        for i in range(1, n):
            if nums[i - 1] != i:
                return False
        return nums[-1] == n and nums[-2] == n
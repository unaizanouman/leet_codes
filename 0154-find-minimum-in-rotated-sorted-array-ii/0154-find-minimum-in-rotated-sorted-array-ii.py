class Solution:
    def findMin(self, nums):
        l = 0
        r = len(nums) - 1

        result_idx = 0

        while l <= r:

            while l < r and nums[l] == nums[l + 1]:
                l += 1
            while l < r and nums[r] == nums[r - 1]:
                r -= 1

            mid = l + (r - l) // 2
            if nums[mid] < nums[result_idx]:
                result_idx = mid
            if nums[mid] > nums[r]:
                l = mid + 1
            else:
                r = mid - 1

        return nums[result_idx]
class Solution:
    def findMin(self, nums):
        l = 0
        r = len(nums) - 1

        result_idx = 0

        while l <= r:

            # remove duplicates from left
            while l < r and nums[l] == nums[l + 1]:
                l += 1

            # remove duplicates from right
            while l < r and nums[r] == nums[r - 1]:
                r -= 1

            mid = l + (r - l) // 2

            # update answer
            if nums[mid] < nums[result_idx]:
                result_idx = mid

            # minimum lies on right side
            if nums[mid] > nums[r]:
                l = mid + 1
            # minimum can be on left side
            else:
                r = mid - 1

        return nums[result_idx]
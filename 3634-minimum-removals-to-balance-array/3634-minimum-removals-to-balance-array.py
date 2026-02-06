class Solution:
    def minRemoval(self,nums,k):

        nums.sort()
        n=len(nums)

        left=0
        max_keep=1
        for right in range(n):
            while nums[right]>nums[left]*k:
                left=left+1
            current_size=right-left+1
            if current_size>max_keep:
                max_keep=current_size
        return n-max_keep
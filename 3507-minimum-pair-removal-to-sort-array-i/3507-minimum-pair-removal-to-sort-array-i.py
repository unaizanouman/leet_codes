class Solution:
    def minimumPairRemoval(self, nums):
        def issorted(arr):
            for i in range(1,len(arr)):
                if arr[i]<arr[i-1]:
                    return False
            return True
        count=0
        while not issorted(nums):
            mins=10**18
            idx=0

            for i in range(len(nums)-1):
                s=nums[i]+nums[i+1]
                if s<mins:
                    mins=s
                    idx=i
            nums[idx]=nums[idx]+nums[idx+1]
            nums.pop(idx+1)
            count=count+1

        return count
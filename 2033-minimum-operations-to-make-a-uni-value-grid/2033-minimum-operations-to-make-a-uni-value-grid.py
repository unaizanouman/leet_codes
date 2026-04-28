class Solution:
    def minOperations(self,grid,x):
        arr=[]
        for row in grid:
            for v in row:
                arr.append(v)
        base=arr[0]%x
        for v in arr:
            if v%x!=base:
                return -1
        arr.sort()
        mid=arr[len(arr)//2]
        ans=0
        for v in arr:
            ans+=abs(v-mid)//x
        return ans
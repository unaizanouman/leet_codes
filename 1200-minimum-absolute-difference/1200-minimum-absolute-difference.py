class Solution:
    def minimumAbsDifference(self,arr):

        arr.sort()

        mindiff=10**9

        for i in range(len(arr)-1):
            diff=arr[i+1]-arr[i]
            if diff<mindiff:
                mindiff=diff
        ans=[]
        for i in range(len(arr)-1):
            if arr[i+1]-arr[i]==mindiff:
                ans.append([arr[i],arr[i+1]])

        return ans
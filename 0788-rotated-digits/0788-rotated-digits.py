class Solution:
    def rotatedDigits(self, n):
        good={2,5,6,9}
        valid={0,1,2,5,6,8,9}
        ans=0
        for i in range(1,n+1):
            x=i
            ok=False
            while x:
                d=x%10
                if d not in valid:
                    ok=False
                    break
                if d in good:
                    ok=True
                x//=10
            else:
                if ok:ans+=1
        return ans
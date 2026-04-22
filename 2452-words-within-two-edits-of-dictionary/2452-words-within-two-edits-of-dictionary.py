class Solution:
    def twoEditWords(self,queries,dictionary):
        res=[]
        for q in queries:
            for d in dictionary:
                diff=0
                for i in range(len(q)):
                    if q[i]!=d[i]:
                        diff+=1
                        if diff>2:
                            break
                if diff<=2:
                    res.append(q)
                    break
        return res
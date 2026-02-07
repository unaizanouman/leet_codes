class Solution:
    def minimumDeletions(self,s):
        b_count=0
        deletions=0
        for ch in s:
            if ch=='b':
                b_count=b_count+1
            else:
                deletions=min(deletions+1,b_count)
        return deletions
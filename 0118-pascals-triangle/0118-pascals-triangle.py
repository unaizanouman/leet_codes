class Solution:
    def generate(self,numRows):

        triangle=[]
        for i in range(numRows):
            row=[1]
            if i>0:
                prev=triangle[i-1]
                for j in range(1,i):
                    row.append(prev[j-1]+prev[j])
                row.append(1)
            triangle.append(row)
        return triangle
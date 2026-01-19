class Solution:
    def maxSideLength(self, mat, threshold):

        rows=len(mat)
        cols=len(mat[0])
        prefix=[[0]*(cols+1) for i in range(rows+1)]

        for i in range(rows):
            for j in range(cols):
                prefix[i+1][j+1]=mat[i][j]+prefix[i][j+1]+prefix[i+1][j]-prefix[i][j]

        maxLen=0

        for size in range(1,min(rows,cols)+1):
            found=False

            for i in range(size,rows+1):
                for j in range(size,cols+1):
                    total=prefix[i][j]-prefix[i-size][j]-prefix[i][j-size]+prefix[i-size][j-size]

                    if total<=threshold:
                        found=True
                        break
                if found:
                    break
            if found:
                maxLen=size
            else:
                break

        return maxLen
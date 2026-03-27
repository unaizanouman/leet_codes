class Solution:
    def areSimilar(self, mat, k):
        m, n = len(mat), len(mat[0])
        k = k % n
        
        for i in range(m):
            row = mat[i]
            if i % 2 == 0:
                shifted = row[k:] + row[:k]
            else:
                shifted = row[-k:] + row[:-k]
            if shifted != row:
                return False
        return True
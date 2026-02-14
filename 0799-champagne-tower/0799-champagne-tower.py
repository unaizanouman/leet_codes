class Solution(object):
    def champagneTower(self, poured, query_row, query_glass):
        row = [float(poured)]
        
        for r in range(query_row):
            next_row = [0.0] * (len(row) + 1)
            
            for i in range(len(row)):
                if row[i] > 1:
                    overflow = (row[i] - 1) / 2.0
                    next_row[i] += overflow
                    next_row[i + 1] += overflow
            
            row = next_row
        
        return min(1, row[query_glass])
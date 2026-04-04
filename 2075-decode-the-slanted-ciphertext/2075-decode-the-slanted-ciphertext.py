class Solution:
    def decodeCiphertext(self, encodedText, rows):
        if rows == 1:
            return encodedText
        
        n = len(encodedText)
        cols = n // rows
        
        # Step 1: build matrix
        matrix = []
        idx = 0
        for i in range(rows):
            matrix.append(list(encodedText[idx:idx+cols]))
            idx += cols
        
        # Step 2: read diagonals
        result = []
        
        for start_col in range(cols):
            i, j = 0, start_col
            
            while i < rows and j < cols:
                result.append(matrix[i][j])
                i += 1
                j += 1
        
        # Step 3: remove trailing spaces
        return "".join(result).rstrip()
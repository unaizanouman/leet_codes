class Solution:
    def bestClosingTime(self, customers):
        penalty = customers.count('Y')
        
        min_penalty = penalty
        best_hour = 0
        
        for i in range(len(customers)):
            if customers[i] == 'Y':
                penalty -= 1
            else:
                penalty += 1
            
            if penalty < min_penalty:
                min_penalty = penalty
                best_hour = i + 1
        
        return best_hour

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0; 
        int total = 0;

        for (auto &row : bank) {
            int curr = count(row.begin(), row.end(), '1');
            if (curr > 0) {
                total += prev * curr;  
                prev = curr; 
            }
        }

        return total;
    }
};

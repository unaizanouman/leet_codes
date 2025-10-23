class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        int left = 0, right = n - 1;
        int top = 0, bottom = n - 1;
        int num = 1;

        while (left <= right && top <= bottom) {
            for (int j = left; j <= right; j++) 
                matrix[top][j] = num++;
            top++;
            for (int i = top; i <= bottom; i++) 
                matrix[i][right] = num++;
            right--;
            if (top <= bottom) {
                for (int j = right; j >= left; j--) 
                    matrix[bottom][j] = num++;
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; i--) 
                    matrix[i][left] = num++;
                left++;
            }
        }

        return matrix;
    }
};

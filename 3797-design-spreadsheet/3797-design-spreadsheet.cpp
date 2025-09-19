class Spreadsheet {
private:
    vector<vector<int>> grid;

    pair<int,int> parseCell(const string& cell) {
        int col = cell[0] - 'A'; 
        int row = stoi(cell.substr(1)) - 1; 
        return {row, col};
    }

    int getVal(const string& token) {
        if (isalpha(token[0])) { 
            auto [r, c] = parseCell(token);
            return grid[r][c];
        }
        return stoi(token);
    }

public:
    Spreadsheet(int rows) {
        grid = vector<vector<int>>(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        auto [r, c] = parseCell(cell);
        grid[r][c] = value;
    }
    
    void resetCell(string cell) {
        auto [r, c] = parseCell(cell);
        grid[r][c] = 0;
    }
    
    int getValue(string formula) {
        // formula like "=X+Y"
        string expr = formula.substr(1); // remove '='
        int plusPos = expr.find('+');
        string left = expr.substr(0, plusPos);
        string right = expr.substr(plusPos + 1);

        return getVal(left) + getVal(right);
    }
};

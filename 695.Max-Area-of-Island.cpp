class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int max_area = 0;
        vector<vector<bool>> seen(rows, vector<bool>(cols, 0));
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                max_area = max(max_area, findArea(i, rows, j, cols, seen, grid));
            }
        }
        
        return max_area;
    }
    
    int findArea(int i, int rows, int j, int cols, vector<vector<bool>>& seen, vector<vector<int>>& grid){
        if(i < 0 || j < 0 || i >= rows || j >= cols || seen[i][j] || grid[i][j] == 0)
            return 0;
        
        seen[i][j] = true;
        
        return 1 + findArea(i + 1, rows, j, cols, seen, grid)
            + findArea(i - 1, rows, j, cols, seen, grid)
            + findArea(i, rows, j + 1, cols, seen, grid)
            + findArea(i, rows, j - 1, cols, seen, grid);
    }
};
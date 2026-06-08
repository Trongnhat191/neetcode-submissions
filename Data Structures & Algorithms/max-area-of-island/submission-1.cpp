class Solution {
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area =  0, tmp_area = 0;
        int ROWS = grid.size(), COLS= grid[0].size();

        for (int r = 0; r< ROWS; r++){
            for (int c = 0; c<COLS; c++){
                if (grid[r][c] == 1){
                    tmp_area = 0;
                    dfs(grid, r, c, tmp_area);
                    max_area = max(max_area, tmp_area);
                }
            }
        }
        return max_area;
    }
    void dfs(vector<vector<int>> & grid, int r, int c, int& tmp_area){
        if (r < 0|| c<0 || c>= grid[0].size()|| r>= grid.size()|| grid[r][c] == 0){
            return;
        }
        tmp_area ++;
        grid[r][c] = 0;

        for (int i = 0; i< 4; i++){
            dfs(grid, r + directions[i][0], c+ directions[i][1], tmp_area);
        }
    }
};

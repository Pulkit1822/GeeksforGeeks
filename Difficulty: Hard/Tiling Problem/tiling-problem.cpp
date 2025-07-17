class Solution {
public:
    void fillTile(int n, vector<vector<int>> &grid) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == -1) {
                    divide(grid, 0, n - 1, 0, n - 1, i, j);
                    return;
                }
            }
        }
    }

private:
    int to_fill = 1;

    void fill2by2Tile(vector<vector<int>> &grid, int top, int down, int left, int right, int i, int j) {
        for (int p = top; p <= down; p++) {
            for (int q = left; q <= right; q++) {
                if (!(p == i && q == j)) {
                    grid[p][q] = to_fill;
                }
            }
        }
        to_fill++;
    }

    void divide(vector<vector<int>> &grid, int top, int down, int left, int right, int i, int j) {
        if (down == top || left == right) return;

        if (down - top == 1 || right - left == 1) {
            fill2by2Tile(grid, top, down, left, right, i, j);
            return;
        }

        int mid_x = (top + down) / 2;
        int mid_y = (left + right) / 2;
        int curr_fill = to_fill++;
        
        if (i <= mid_x && j <= mid_y)
            divide(grid, top, mid_x, left, mid_y, i, j);
        else {
            grid[mid_x][mid_y] = curr_fill;
            divide(grid, top, mid_x, left, mid_y, mid_x, mid_y);
        }

        if (i <= mid_x && j > mid_y)
            divide(grid, top, mid_x, mid_y + 1, right, i, j);
        else {
            grid[mid_x][mid_y + 1] = curr_fill;
            divide(grid, top, mid_x, mid_y + 1, right, mid_x, mid_y + 1);
        }

        if (i > mid_x && j > mid_y)
            divide(grid, mid_x + 1, down, mid_y + 1, right, i, j);
        else {
            grid[mid_x + 1][mid_y + 1] = curr_fill;
            divide(grid, mid_x + 1, down, mid_y + 1, right, mid_x + 1, mid_y + 1);
        }

        if (i > mid_x && j <= mid_y)
            divide(grid, mid_x + 1, down, left, mid_y, i, j);
        else {
            grid[mid_x + 1][mid_y] = curr_fill;
            divide(grid, mid_x + 1, down, left, mid_y, mid_x + 1, mid_y);
        }
    }
};

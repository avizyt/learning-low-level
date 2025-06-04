#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<char>> &grid, int r, int c)
{
    int nr = grid.size();
    int nc = grid[0].size();

    if (r < 0 || r >= nr || c < 0 || c >= nc || grid[r][c] == '0')
    {
        return;
    }
    grid[r][c] = '0';
    dfs(grid, r + 1, c);
    dfs(grid, r - 1, c);
    dfs(grid, r, c + 1);
    dfs(grid, r, c - 1);
}

int numIslands(vector<vector<char>> &grid)
{
    if (grid.empty())
    {
        return 0;
    }
    int nr = grid.size();
    int nc = grid[0].size();
    int num_islands = 0;

    for (int i = 0; i < nr; ++i)
    {
        for (int j = 0; j < nc; ++j)
        {
            if (grid[i][j] == '1')
            {
                ++num_islands;
                dfs(grid, i, j);
            }
        }
    }

    return num_islands;
}

int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};
    cout << "Number of islands: " << numIslands(grid) << endl; // Output: 1

    vector<vector<char>> grid2 = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};
    cout << "Number of islands: " << numIslands(grid2) << endl; // Output: 3

    return 0;
}
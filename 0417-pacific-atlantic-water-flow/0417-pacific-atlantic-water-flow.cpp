class Solution {
public:
    int m, n;
    vector<vector<int>> pacific, atlantic;

    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<int>>& visited) {
        visited[i][j] = 1;

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];

            if (x >= 0 && x < m && y >= 0 && y < n &&
                !visited[x][y] && heights[x][y] >= heights[i][j]) {
                dfs(heights, x, y, visited);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<int>> p(m, vector<int>(n, 0));
        vector<vector<int>> a(m, vector<int>(n, 0));

        // Pacific
        for (int i = 0; i < m; i++) {
            dfs(heights, i, 0, p);
            dfs(heights, i, n - 1, a);
        }

        for (int j = 0; j < n; j++) {
            dfs(heights, 0, j, p);
            dfs(heights, m - 1, j, a);
        }

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (p[i][j] && a[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
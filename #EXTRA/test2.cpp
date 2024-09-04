


class Solution
{
public:
    void findPathUtil(vector<vector<int>> &m, int n, int r, int c, vector<pair<int, int>> &def, vector<vector<int>> &vis, string path, vector<string> &ans)
    {
        if (r == n - 1 && c == n - 1)
        {
            if (m[r][c] == 1)
            {
                ans.push_back(path);
            }
            return;
        }

        string sync = "DLRU";  // Changed to match the direction pairs

        for (int i = 0; i < 4; i++)
        {
            int nr = r + def[i].first;
            int nc = c + def[i].second;

            if ((nr >= 0 && nr < n) && (nc >= 0 && nc < n) && m[nr][nc] == 1 && vis[nr][nc] != 1)
            {
                vis[nr][nc] = 1;
                findPathUtil(m, n, nr, nc, def, vis, path + sync[i], ans);
                vis[nr][nc] = 0;
            }
        }
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        vector<pair<int, int>> def = {{+1, 0}, {0, -1}, {0, +1}, {-1, 0}};  // Adjusted to match D, L, R, U

        if (m[0][0] == 1)
        {
            vis[0][0] = 1;  // Mark the initial cell as visited
            findPathUtil(m, n, 0, 0, def, vis, "", ans);
        }

        return ans;
    }
};
class Solution {
    vector<int> fa;
    int m;
    int n;

    int node(int i, int j) { return i * n + j; }
    int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
    void union_(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx != fy)
            fa[fy] = fx;
    }

public:
    int numIslands(vector<vector<char>> &board) {

        if (board.empty() || board[0].empty())
            return 0;

        m = board.size();
        n = board[0].size();

        fa.resize(m * n);

        for (int i = 0; i < fa.size(); ++i) {
            fa[i] = i;
        }

        set<int> islands;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '1') {

                    if (i > 0 && board[i - 1][j] == '1')
                        union_(node(i, j), node(i - 1, j));

                    if (i < m - 1 && board[i + 1][j] == '1')
                        union_(node(i, j), node(i + 1, j));

                    if (j > 0 && board[i][j - 1] == '1')
                        union_(node(i, j), node(i, j - 1));

                    if (j < n - 1 && board[i][j + 1] == '1')
                        union_(node(i, j), node(i, j + 1));
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '1')
                    islands.insert(find(node(i, j)));
            }
        }
        return islands.size();
    }
};

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define forn(i,n) for(int i = 0; i <(int)n; ++i)
#define vi vector<int>
#define debug(x)    cout << #x << " : " << x << endl;

const int MOD = 1000000007;
//const int MOD = 998244353;
const int MAXN = 4e5 + 5;
int **grid;
bool **vis;
int n, m;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
int fill(int x, int y, int height) {
    if (vis[x][y]) {
        return 0;
    }

    int ret = 1;

    forn(i, 4) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && grid[nx][ny] <= height) {
            ret += fill(nx, ny, height);
        }
    }

    return ret;
}



void solve() {
    cin >> n >> m;

    grid = new int*[n];
    forn(i, n) {
        grid[i] = new int[m];
    }

    vis = new bool*[n];
    forn(i, n) {
        vis[i] = new bool[m];
        forn(j, m) {
            vis[i][j] = false;
        }
    }

    forn(i, n) forn(j, m) {
        cin >> grid[i][j];
    }

    int ans[n][m];
    forn(i, n) forn(j, m) {
        forn (ii, n) forn (jj, m) vis[ii][jj] = false;
        ans[i][j] = fill(i, j, grid[i][j]);
    }

    forn(i, n) {
        forn(j, m) cout << ans[i][j] << ' '; cout << '\n';
    }



    // CLEANUP
    forn(i, n) {
        delete[] grid[i];
        delete[] vis[i];
    }
    delete[] grid;
    delete[] vis;
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int tc = 1;
    // cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}
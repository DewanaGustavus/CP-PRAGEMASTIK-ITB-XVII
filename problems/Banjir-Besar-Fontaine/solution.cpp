#include <bits/stdc++.h>

using namespace std;

#define int long long
#define forn(i,n) for(int i = 0; i <(int)n; ++i)
#define vi vector<int>
#define debug(x)    cout << #x << " : " << x << endl;

const int MOD = 1000000007;
//const int MOD = 998244353;
const int MAXN = 4e5 + 5;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int to1d(int i, int j, int m) {
    return i * m + j;
}
pair<int,int> to2d(int ii, int m) {
    return {ii / m, ii % m};
}

int par[MAXN];
int sz[MAXN];

void init() {
    forn(i, MAXN) {
        par[i] = i; sz[i] = 1;
    }
}

int getpar(int x) {
    if (x == par[x]) return x;
    return par[x] = getpar(par[x]);
}

void mer(int x, int y) {
    x = getpar(x);
    y = getpar(y);

    if (x == y) return;

    if (sz[x] > sz[y]) swap(x, y);

    par[x] = y;
    sz[y] += sz[x];
}

void solve() {
    init();
    int n, m;
    cin >> n >> m;

    int grid[n][m];
    forn(i, n) forn(j, m) {
        cin >> grid[i][j];
    }

    vector<pair<int, int>> height; // first: height, second: 1d index
    forn(i, n) forn(j, m) {
        height.emplace_back(grid[i][j], to1d(i, j, m));
    }

    sort(height.begin(), height.end());

    int ans[n][m];
    memset(ans, -1, sizeof(ans));
    forn(itr, height.size()) {
        // merge all with same height
        for(int pppp = itr; pppp < height.size() && height[pppp].first == height[itr].first; ++pppp) {
            pair<int, int> _ij = to2d(height[pppp].second, m);
            int i = _ij.first;
            int j = _ij.second;

            forn(k, 4) {
                int ni = i + dx[k];
                int nj = j + dy[k];

                if (ni >= 0 && nj >= 0 && ni < n && nj < m && grid[i][j] >= grid[ni][nj]) {
                    mer(to1d(i, j, m), to1d(ni, nj, m));
                }
            }
        }

        // get all answer
        for(int pppp = itr; pppp < height.size() && height[pppp].first == height[itr].first; ++pppp) {
            pair<int, int> _ij = to2d(height[pppp].second, m);
            int i = _ij.first;
            int j = _ij.second;

            ans[i][j] = sz[getpar(height[pppp].second)];
            itr = pppp;
        }
        
    }

    forn(i, n) {
        forn(j, m) cout << ans[i][j] << ' '; cout << '\n';
    }
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
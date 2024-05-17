#include <bits/stdc++.h>

using namespace std;

#define int long long
#define forn(i,n) for(int i = 0; i <(int)n; ++i)
#define vi vector<int>
#define debug(x)    cout << #x << " : " << x << endl;

// const int MOD = 1000000007;
const int MOD = 998244353;

struct Matrix {
    private:
    vector<vi> val;
    int dim[2];

    public:
    Matrix(int n): Matrix(n, n) {}
    Matrix(int n, int m): Matrix(n, m, 0) {}
    Matrix(int n, int m, int defaultValue) {
        val = vector<vi>(n, vi(m, defaultValue));
        dim[0] = n;
        dim[1] = m;
    }
    void set(int i, int j, int newval) {
        val[i][j] = newval;
    }
    int get(int i, int j) {
        return val[i][j];
    }

    const Matrix operator*(Matrix o) {
        if (dim[1] != o.dim[0]) {
            assert(0);
        }

        Matrix res = Matrix(dim[0], o.dim[1]);
        forn(i, dim[0]) forn(j, o.dim[1]) forn(k, dim[1]) {
            res.val[i][j] += val[i][k] * o.val[k][j];
            res.val[i][j] %= MOD;
        }

        return res;
    }

    void print() {
        forn(i, dim[0]) {
            forn(j, dim[1]) {
                cout << val[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    Matrix pow(int e) {
        if (!e) return identity(dim[0]);
        Matrix tmp = pow(e / 2);
        tmp = tmp * tmp;
        if (e % 2) tmp = tmp * *this;
        return tmp;
    }

    static Matrix identity(int n) {
        Matrix res(n);
        forn(i, n) res.set(i, i, 1);
        return res;
    }
};

/**
 * SALAH BIKIN
 * 
 * @param n ukuran matrix
 * @param moveCount pemindahan
 * 
*/
Matrix createMoveMatrix(int n, int moveCount) {
    Matrix res = Matrix::identity(n);
    
    forn(i, n) {
        int j = (i-moveCount%n+n)%n;
        res.set(i, j, res.get(i, j) + 1);
    }

    return res;
}


void solve() {
    int n, k;
    cin >> n >> k;
    int cnt[9];
    memset(cnt, 0, sizeof(cnt));

    forn(i, n) {
        string s; cin >> s;
        int p = 0;
        for(char c: s) {
            p += c - '0';
        }
        cnt[p%9]++;
    }



    Matrix cur(9);
    forn(i, 9) {
        forn(moveCount, 9) {
            int j = (i-moveCount%9+9)%9;
            cur.set(i, j, cnt[moveCount]);

        }
    }

    cur = cur.pow(k);

    // cur.print();

    Matrix ans(9, 1);
    ans.set(0, 0, 1);
    ans = cur * ans;

    cout << ans.get(0, 0) << '\n';
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
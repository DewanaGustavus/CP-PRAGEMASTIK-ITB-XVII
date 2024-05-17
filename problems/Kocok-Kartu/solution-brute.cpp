#include <bits/stdc++.h>

using namespace std;

#define int long long
#define forn(i,n) for(int i = 0; i <(int)n; ++i)
#define vi vector<int>
#define debug(x)    cout << #x << " : " << x << endl;

const int MOD = 1000000007;
//const int MOD = 998244353;

long long fastexp (long long x, long long e, long long mod = MOD) {
    if (!e) return 1;
    long long ret = fastexp(x, e / 2, mod);
    ret = ret * ret % mod;
    if (e % 2) ret = ret * x % mod;
    return ret;
}

void solve() {
    int n; cin >> n;
    for(int i = 2; i <= n+2; ++i) {
        if (fastexp(2, i, n+1) == 1) {
            cout << i << endl;
            return;
        }
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
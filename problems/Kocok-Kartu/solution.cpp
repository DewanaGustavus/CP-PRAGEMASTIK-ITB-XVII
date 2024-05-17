#include <bits/stdc++.h>

using namespace std;

#define int long long
#define forn(i,n) for(int i = 0; i <(int)n; ++i)
#define vi vector<int>
#define debug(x)    cout << #x << " : " << x << endl;

const int MOD = 1000000007;
//const int MOD = 998244353;

int etf(int x) {
    int res = x;
    vi primes;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i) continue;
        primes.push_back(i);
        while(!(x%i)) {
            x /= i;
        }
    }
    if (x != 1) {
        primes.push_back(x);
    }

    for(int p: primes) {
        res = res / p * (p-1); 
    }
    return res;
}

vi getAllFactor(int x) {
    vi res;
    for (int i = 1; i * i <= x; ++i) {
        if (x % i) continue;
        res.push_back(i);
        if (x / i != i) {
            res.push_back(x / i);
        }
    }

    return res;
}

long long fastexp (long long x, long long e, long long mod = MOD) {
    if (!e) return 1;
    long long ret = fastexp(x, e / 2, mod);
    ret = ret * ret % mod;
    if (e % 2) ret = ret * x % mod;
    return ret;
}

void solve() {
    int n; cin >> n;
    int eee = etf(n+1);
    vi fac = getAllFactor(eee);
    sort(fac.begin(), fac.end());
    for (int x: fac) {
        if (fastexp(2, x, n+1) == 1) {
            cout << x << endl;
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
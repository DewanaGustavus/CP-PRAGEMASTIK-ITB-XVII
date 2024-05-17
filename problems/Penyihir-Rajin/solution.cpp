#include <bits/stdc++.h>

#define ll long long
#define MOD 998244353

using namespace std;

vector<vector<ll>> multiply(vector<vector<ll>> &a, vector<vector<ll>> &b) {
    assert(a[0].size() == b.size());

    vector<vector<ll>> res(a.size(), vector<ll>(b[0].size(), 0));
    
    for (ll i = 0; i < (int)a.size(); i++) {
        for (ll j = 0; j < (int)b[0].size(); j++) {
            for (ll k = 0; k < (int)a[0].size(); k++) {
                ll add = (a[i][k] * b[k][j] % MOD + MOD) % MOD;
                res[i][j] = (res[i][j] + add) % MOD;
            }
        }
    }
    
    return res;
}

vector<vector<ll>> matrixPow(vector<vector<ll>> &a, ll e) {
    if (e == 0) {
        vector<vector<ll>> res(a.size(), vector<ll>(a.size(), 0));
        for (ll i = 0; i < (int)a.size(); i++) res[i][i] = 1;
        return res;
    } else if (e == 1) {
        return a;
    }

    vector<vector<ll>> tmp = matrixPow(a, e / 2);
    tmp = multiply(tmp, tmp);

    if (e % 2 == 1) tmp = multiply(tmp, a);

    return tmp;
}

void solve() {
    ll n, k, t; cin >> n >> k >> t;

    vector<vector<ll>> matrix = {
        {k + 1, 0, 0, -1, 1},
        {1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, k, 0, 1},
        {0, 0, 0, 0, 1},
    };

    vector<ll> bases = {n};
    for (ll i = 1; i <= 2; i++) bases.push_back(((k + (bases[i - 1] * k) + bases[i - 1]) % MOD) % MOD);

    if (t <= 2) {
        cout << bases[t] << endl;
        return;
    }

    vector<vector<ll>> base = {
        {bases[2]},
        {bases[1]},
        {bases[0]},
        {bases[0]},
        {k}
    };

    vector<vector<ll>> ans = matrixPow(matrix, t - 2);
    ans = multiply(ans, base);

    cout << (ans[0][0] % MOD + MOD) % MOD << endl;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}
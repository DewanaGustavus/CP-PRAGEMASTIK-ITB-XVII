#include <bits/stdc++.h>

#define ll long long
#define MOD 998244353

using namespace std;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> freq(9, 0);

    for (int i = 0; i < n; i++) {
        string s; cin >> s;

        int temp = 0;
        for (auto x: s) {
            temp = (temp + (x - '0')) % 9;
        }

        freq[temp] += 1;
    }

    vector<ll> ans(freq);

    for (ll i = 2; i <= k; i++) { // Iterate over k
        vector<ll> temp(9, 0);

        for (ll x = 0; x < 9; x++) {
            for (ll y = 0; y < 9; y++) {
                temp[(x + y) % 9] = (temp[(x + y) % 9] + (ans[x] * freq[y])) % MOD;
            }
        }

        ans = temp;
    }

    cout << ans[0] << endl;
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
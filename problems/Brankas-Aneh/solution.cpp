#include <bits/stdc++.h>

#define ll long long
#define MOD 998244353

using namespace std;

void solve() {
    ll n; cin >> n;
    
    ll magic = 0;
    for (ll i = 0; i < n; i++) {
        ll x; cin >> x;

        if (n % 2 != 0 && i % 2 == 0) {
            if ((i / 2) % 2 == 0) {
                magic += x;
            } else {
                magic -= x;
            }
        }
    }

    for (ll i = 0; i < n; i++) {
        ll x; cin >> x;

        if (n % 2 != 0 && i % 2 == 0) {
            if ((i / 2) % 2 == 0) {
                magic -= x;
            } else {
                magic += x;
            }
        }
    }

    if (magic == 0) cout << "Ya" << endl;
    else cout << "Tidak" << endl;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}
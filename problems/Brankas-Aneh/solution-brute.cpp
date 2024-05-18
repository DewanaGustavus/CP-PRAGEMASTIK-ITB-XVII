#include <bits/stdc++.h>

#define ll long long
#define MOD 998244353

using namespace std;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n), b(n);

    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    if (n % 2 == 0) {
        ll p;

        // For odd buttons
        p = 1;
        while (p < n) {
            while (a[p - 1] > 0) {
                a[p - 1]--;
                if (p + 1 < n) a[p + 1]--;
            }

            while (a[p - 1] < 0) {
                a[p - 1]++;
                if (p + 1 < n) a[p + 1]++;
            }

            while (b[p - 1] > 0) {
                b[p - 1]--;
                if (p + 1 < n) b[p + 1]--;
            }

            while (b[p - 1] < 0) {
                b[p - 1]++;
                if (p + 1 < n) b[p + 1]++;
            }

            p += 2;
        }

        // For even buttons
        p = n - 2;
        while (p >= 0) {
            while (a[p + 1] > 0) {
                a[p + 1]--;
                if (p - 1 >= 0) a[p - 1]--;
            }

            while (a[p + 1] < 0) {
                a[p + 1]++;
                if (p - 1 >= 0) a[p - 1]++;
            }

            while (b[p + 1] > 0) {
                b[p + 1]--;
                if (p - 1 >= 0) b[p - 1]--;
            }

            while (b[p + 1] < 0) {
                b[p + 1]++;
                if (p - 1 >= 0) b[p - 1]++;
            }

            p -= 2;
        }
    } else {
        ll p;

        // For odd buttons
        p = 1;
        while (p < n) {
            while (a[p - 1] > 0) {
                a[p - 1]--;
                if (p + 1 < n) a[p + 1]--;
            }

            while (a[p - 1] < 0) {
                a[p - 1]++;
                if (p + 1 < n) a[p + 1]++;
            }

            while (b[p - 1] > 0) {
                b[p - 1]--;
                if (p + 1 < n) b[p + 1]--;
            }

            while (b[p - 1] < 0) {
                b[p - 1]++;
                if (p + 1 < n) b[p + 1]++;
            }

            p += 2;
        }

        // For even buttons
        p = n - 1;
        while (p >= 0) {
            while (p + 1 < n && a[p + 1] > 0) {
                a[p + 1]--;
                if (p - 1 >= 0) a[p - 1]--;
            }

            while (p + 1 < n && a[p + 1] < 0) {
                a[p + 1]++;
                if (p - 1 >= 0) a[p - 1]++;
            }

            while (p + 1 < n && b[p + 1] > 0) {
                b[p + 1]--;
                if (p - 1 >= 0) b[p - 1]--;
            }

            while (p + 1 < n && b[p + 1] < 0) {
                b[p + 1]++;
                if (p - 1 >= 0) b[p - 1]++;
            }

            p -= 2;
        }
    }

    // for (auto x: a) {
    //     cout << x << " ";
    // }
    // cout << endl;

    // for (auto x: b) {
    //     cout << x << " ";
    // }
    // cout << endl;

    bool ans = true;
    for (ll i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            ans = false;
            break;
        }
    }

    if (ans) cout << "Ya" << endl;
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
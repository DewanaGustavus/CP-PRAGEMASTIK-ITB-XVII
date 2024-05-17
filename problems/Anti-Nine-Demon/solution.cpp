#include <bits/stdc++.h>

#define ll long long
#define MOD 998244353

using namespace std;

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd>& a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }

    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}

void mul(vector<cd>& a, vector<cd>& b) {
    int n = 1;
    while (n < a.size() + b.size() - 1) n <<= 1;

    a.resize(n);
    b.resize(n);

    fft(a, false);
    fft(b, false);

    for (int i = 0; i < a.size(); i++) a[i] *= b[i];
    fft(a, true);

    for (int i = 0; i < a.size(); i++) a[i] = round(a[i].real());
}

void dnc(vector<cd>& a, int n) {
    if (n <= 1) return;

    vector<cd> half(a);
    dnc(half, n / 2);

    vector<cd> cpy(half);
    mul(half, cpy);

    if (n % 2 != 0) mul(half, a);

    vector<ll> tempvec(9, 0);
    for (int i = 0; i < half.size(); i++) {
        ll tempval = (ll) round(half[i].real());
        tempvec[i % 9] = (tempvec[i % 9] + tempval) % MOD;
    }
    
    a.assign(9, 0);
    for (int i = 0; i < 9; i++) {
        a[i] = tempvec[i] % MOD;
    }
}

void solve() {
    ll n, k; cin >> n >> k;
    vector<cd> freq(9, 0);

    for (int i = 0; i < n; i++) {
        string s; cin >> s;

        int temp = 0;
        for (auto x: s) {
            temp = (temp + (x - '0')) % 9;
        }

        freq[temp] += 1;
    }

    dnc(freq, k);
    cout << (ll) round(freq[0].real()) << endl;
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
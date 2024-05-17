#include <bits/stdc++.h>

#define ll long long
#define MOD 998244353

using namespace std;

void solve() {
    ll n, k, t; cin >> n >> k >> t;

    ll ans = n;
    queue<ll> forgottenSpells; forgottenSpells.push(n); 
    
    for (ll i = 1; i <= t; i++) {
        ll spellLearned = (k + (ans * k) % MOD) % MOD;
        ans = (ans + spellLearned) % MOD;

        if (i >= 3) {
            ll forgottenSpell = forgottenSpells.front(); forgottenSpells.pop();
            ans = (ans - forgottenSpell + MOD) % MOD;
        }

        forgottenSpells.push(spellLearned);
    }

    cout << ans % MOD << endl;
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
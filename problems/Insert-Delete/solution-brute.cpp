// Time Complexity : O((n + q)^2 * log(n + q))

#include <bits/stdc++.h>
using namespace std;

#define int                 long long
#define all(vec)            (vec).begin(),(vec).end()
#define range(i,s,e)		for(int i=s;i<e;i++)

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    range(i,0,n) cin >> a[i];
    sort(all(a));

    int q; cin >> q;
    range(i,0,q) {
        int t; cin >> t;
        int x, idx;
        if(t == 1) {
            cin >> x;
            a.push_back(x);
            sort(all(a));
        }else if(t == 2) {
            cin >> idx;
            a.erase(a.begin() + idx - 1);
            sort(all(a));
        }else if(t == 3) {
            cin >> idx;
            cout << a[idx - 1] << endl;
        }else if(t == 4) {
            int l, r;
            cin >> l >> r;
            int sum = 0;
            range(i,l-1,r) {
                sum += a[i];
            }
            cout << sum << endl;
        }else if(t == 5) {
            cin >> x;
            range(i,0,a.size()) {
                a[i] += x;
            }
        }else if(t == 6) {
            cin >> x;
            range(i,0,a.size()) {
                a[i] = max(0ll, a[i] - x);
            }
        }

        // printarr(a)
    }


    return 0;
}







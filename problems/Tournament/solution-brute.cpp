// Time Complexity : O(n * q)

#include <bits/stdc++.h>
using namespace std;

#define range(i,s,e)		for(int i=s;i<e;i++)
#define int                 long long

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n; cin >> n;
    int a[n];
    range(i,0,n) cin >> a[i];

    int q; cin >> q;
    range(i,0,q) {
        int x,l,r;
        cin >> x >> l >> r;

        int val = a[x - 1];
        int cnt = 0;
        range(i,l-1,r) {
            if (val > a[i]) {
                cnt++;
            }
        }

        cout << cnt << endl;
    }
    

    return 0;
}









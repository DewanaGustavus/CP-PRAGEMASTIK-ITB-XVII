// Time Complexity : O((n + q) * log(n))

#include <bits/stdc++.h>
using namespace std;

#define range(i,s,e)		for(int i=s;i<e;i++)
#define int                 long long


struct segtree{
    // segment tree bottom up traversal
    // 0-indexing, left child is 2*i, right child is 2*i+1, parent is floor(i/2)
    // template for sum range
    int n;
    vector<int> segment;
    int init = 0; // initialize array value
    int operation(int a, int b){return a+b;} // segment tree operation
    segtree(vector<int> array){
        n = log2(array.size()-1) + 1;
        n = (1<<n);
        segment = vector<int>(2*n, init);
        for(int i=0;i<array.size();i++){
            add(i, array[i]);
        }
    }
    void add(int idx, int val){
        idx += n;
        segment[idx] += val;
        for(idx/=2;idx>=1;idx/=2){
            segment[idx] = operation(segment[2*idx], segment[2*idx + 1]); 
        }
    }
    int sum(int l, int r) {
        l += n;
        r += n;
        int ans = init;
        while (l <= r) {
            if (l%2 == 1) ans = operation(ans, segment[l++]);
            if (r%2 == 0) ans = operation(ans, segment[r--]);
            l /= 2; r /= 2;
        }
        return ans;
    }
};


struct queries {
    int x,idx;
    queries() {}
    queries(int _x, int _idx) {
        x = _x;
        idx = _idx;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n; cin>>n;
    const int amax = 1e6;

    int a[n + 1] = {};
    range(i,0,n) cin >> a[i];
    a[n] = amax + 1;

    vector<int> dummy(amax + 2);
    segtree st(dummy);

    int q; cin >> q;
    vector<queries> queRySl[n + 1];
    vector<queries> queRySr[n + 1];
    range(i,0,q) {
        int x, l, r;
        cin >> x >> l >> r;
        
        queries IRySl(a[x - 1], i);
        queries IRySr(a[x - 1], i);
        queRySl[l - 1].push_back(IRySl);
        queRySr[r].push_back(IRySr);
    }

    int cntl[q] = {};
    int cntr[q] = {};
    range(i,1,n + 1) {
        st.add(a[i - 1], 1);
        
        for(queries IRyS : queRySl[i]) {
            cntl[IRyS.idx] = st.sum(0, IRyS.x - 1);
        }
        for(queries IRyS : queRySr[i]) {
            cntr[IRyS.idx] = st.sum(0, IRyS.x - 1);
        }

        // range(i,0,7) {
        //     cout << st.sum(i,i) << " ";
        // }
        // cout << endl;
    }

    // range(i,0,q) cout << (cntl[i]) << " ";
    // cout << endl;
    // range(i,0,q) cout << (cntr[i]) << " ";
    // cout << endl;

    range(i,0,q) {
        int ans = cntr[i] - cntl[i];
        cout << ans << endl;
    }

    return 0;
}







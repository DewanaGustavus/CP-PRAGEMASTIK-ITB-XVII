// Time Complexity : O((n + q) * log(n + q))

#include <bits/stdc++.h>
using namespace std;

#define int                 long long
#define range(i,s,e)		for(int i=s;i<e;i++)

struct val_type {
    int cnt, val;
    val_type(int cnt = 0, int val = 0) : cnt(cnt), val(val) {}
};

struct segtreelazy{
    // generic segtree lazy template
    int n;
    int z;
    int amax;
    vector<val_type> segment;
    vector<bool> lazyset; // set 0 or not
    vector<int> lazyadd;
    val_type init = val_type(); // initialize array value
    val_type operation(val_type a, val_type b) {
        // segment tree operation
        val_type ret;
        ret.cnt = a.cnt + b.cnt;
        ret.val = a.val + b.val;
        return ret;
    }

    segtreelazy(vector<int> array, int _amax){
        z = 0;
        n = log2(array.size() - 1) + 2;
        n = (1<<n);
        amax = _amax;
        segment = vector<val_type>(2*n, init);
        lazyset = vector<bool>(2*n, 0);
        lazyadd = vector<int>(2*n, 0);
        build(array);
    }

    void build(vector<int> array){
        for(int i=0;i<(int)array.size();i++){
            segment[i+n + amax] = val_type(array[i], i * array[i]);
        }
        for(int i=n-1;i>=1;i--){
            segment[i] = operation(segment[2*i], segment[2*i+1]);
        }
    }

    void propagate(int idx){
        if(lazyset[idx] == 0 && lazyadd[idx] == 0)return ;
        if (lazyset[idx]) {
            segment[idx] = init;
            if(idx < n){ // not leaf
                lazyset[2*idx] = lazyset[idx];
                lazyset[2*idx+1] = lazyset[idx];
            }
        }
        
        if (lazyadd[idx] != 0) {
            segment[idx].val += lazyadd[idx] * segment[idx].cnt;
            if(idx < n){ // not leaf
                lazyadd[2*idx] += lazyadd[idx];
                lazyadd[2*idx+1] += lazyadd[idx];
            }
        }
        
        lazyset[idx] = 0;
        lazyadd[idx] = 0;
    }

    val_type get(int idx){
        propagate(idx);
        return segment[idx];
    }

    void add(int idx, int val){add(idx,idx + amax,val,1,0,n-1);}
    void add(int idx, int tidx, int val, int si, int sl, int sr){
        if(tidx > sr || tidx < sl)return; // out of range
        else if(tidx <= sl && sr <= tidx) {
            propagate(si);
            segment[si].cnt += val;
            segment[si].val += val * (idx + z);
        }else{
            propagate(si);
            int mid = (sl+sr)/2;
            add(idx,tidx,val,2*si,sl,mid);
            add(idx,tidx,val,2*si+1,mid+1,sr);
            segment[si] = operation(get(2*si), get(2*si+1));
        }
    }

    void set(int l, int r){set(l,r,1,0,n-1);}
    void set(int l, int r, int idx, int sl, int sr){
        if(l > sr || r < sl)return; // out of range
        else if(l <= sl && sr <= r)lazyset[idx] = 1;
        else{
            propagate(idx);
            int mid = (sl+sr)/2;
            set(l,r,2*idx,sl,mid);
            set(l,r,2*idx+1,mid+1,sr);
            segment[idx] = operation(get(2*idx), get(2*idx+1));
        }
    }

    val_type range_query(int l, int r){return range_query(l,r,1,0,n-1);}
    val_type range_query(int l, int r, int idx, int sl, int sr){
        if(l > sr || r < sl)return init; // out of range
        if(l <= sl && sr <= r)return get(idx);
        propagate(idx);
        int mid = (sl+sr)/2;
        return operation(range_query(l,r,2*idx,sl,mid), range_query(l,r,2*idx+1,mid+1,sr));
    }

    int get_idx(int real_idx) {
        // top down finding first index same as minimum global in minimum query
        int idx = 1;
        int search_idx = real_idx;
        while(idx < n) {
            idx *= 2;
            int left = get(idx).cnt;
            if(left < search_idx) {
                // go to right
                search_idx -= left;
                idx++;
            }
        }
        return idx - n;
    }
    
    int sumrange(int l, int r) {
        int sl = get_idx(l);
        int sr = get_idx(r);
        int sum = 0;

        int startl = l - range_query(0, sl - 1).cnt;
        int endr = r - range_query(0, sr - 1).cnt;
        // print("Debug sumrange")
        // prints(sl)
        // prints(sr)
        // prints(startl)
        // prints(endr)

        if(sl == sr) {
            int length = endr - startl + 1;
            sum = length * (sl + z - amax);
        }else {
            int mid = range_query(sl + 1, sr - 1).val;
            int left_length = range_query(sl, sl).cnt - startl + 1;
            int right_length = endr;
            int left = left_length * (sl + z - amax);
            int right = right_length * (sr + z - amax);

            // endline
            // print2(left_length, right_length)
            // prints(left)
            // prints(mid)
            // prints(right)

            sum = left + mid + right;
        }

        // endline

        return sum;
    }

    void shift(int x) {
        lazyadd[1] += x;
        z += x;

        if (z < 0) {
            int cnt = range_query(0, -z + amax).cnt;
            set(0, -z + amax);
            add(-z, cnt);
        }
    }
};

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n; cin >> n;
    int a[n];
    range(i,0,n) cin >> a[i];

    const int amax = 2e6;
    vector<int> dummy(amax + 1);
    range(i,0,n) {
        dummy[a[i]]++;
    }

    segtreelazy st(dummy, amax);

    int q; cin >> q;
    range(i,0,q) {
        int t; cin >> t;
        int x, idx;

        if(t == 1) {
            // INSERT
            cin >> x;
            st.add(x - st.z, 1);
        }else if(t == 2) {
            // delete
            cin >> idx;
            idx = st.get_idx(idx) - amax;
            st.add(idx, -1);
        }else if(t == 3) {
            // query pos
            cin >> idx;
            idx = st.get_idx(idx) + st.z - amax;
            cout << idx << endl;
        }else if(t == 4) {
            // sum query
            int l, r;
            cin >> l >> r;
            int sum = st.sumrange(l, r);
            cout << sum << endl;
        }else if(t == 5) {
            // shift left
            cin >> x;
            st.shift(x);
        }else if(t == 6) {
            // shift right
            cin >> x;
            st.shift(-x);
        }

        // range(i,0,2 * amax) {
        //     int cnt = st.range_query(i, i).cnt;
        //     range(j,0,cnt) {
        //         prints(i + st.z - amax)
        //     }
        // }
        // endline
    }


    return 0;
}




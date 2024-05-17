// Time Complexity : O(n * log^2(n))

#include <bits/stdc++.h>
using namespace std;

#define vi          vector<int>
#define pb          push_back
#define vvi         vector<vector<int>>
#define all(vec)    (vec).begin(), (vec).end()
#define int         long long

struct segtree{
    int n;
    vvi segment;
    segtree(){}
    segtree(vi &array){
        n = log2(array.size()-1) + 1;
        n = (1<<n);
        segment = vvi(2*n);
        build(array);
    }

    void build(vi &array){
        for(int i=0;i<(int)array.size();i++){
            segment[i+n].push_back(array[i]);
        }
        for(int i=n-1;i>=1;i--){ // merge sort tree
            int l = 0;
            int r = 0;
            while(l < (int)segment[2*i].size() && r < (int)segment[2*i + 1].size()) {
                if(segment[2*i][l] <= segment[2*i + 1][r]) {
                    segment[i].push_back(segment[2*i][l++]);
                }else{
                    segment[i].push_back(segment[2*i+1][r++]);
                }
            }

            while(l < (int)segment[2*i].size())segment[i].push_back(segment[2*i][l++]);
            while(r < (int)segment[2*i+1].size())segment[i].push_back(segment[2*i+1][r++]);
        }
    }

    int rangequery(int l, int r, int k){return rangequery(l,r,k,1,0,n-1);}
    int rangequery(int l, int r, int k, int idx, int sl, int sr){
        if(l > sr || r < sl)return 0; // out of range
        if(l <= sl && sr <= r){
            auto it = upper_bound(all(segment[idx]), k);
            int amount = distance(segment[idx].begin(), it);
            return amount;
        }
        int mid = (sl+sr)/2;
        return rangequery(l,r,k,2*idx,sl,mid) +
                rangequery(l,r,k,2*idx+1,mid+1,sr);
    }
};

const int maxn = 2e5 + 5;
vi adj[maxn];
int depth[maxn] = {};
int subtreesize[maxn];
int eulertouridx[maxn];
int eulerarray[maxn];
int idx = 0;

void dfs(int node, int par = 1){
    depth[node] = depth[par] + 1;
    eulerarray[idx] = node;
    eulertouridx[node] = idx++;
    subtreesize[node] = 1;
    for(auto nxt:adj[node]) {
        if (nxt == par) continue;
        dfs(nxt, node);
        subtreesize[node] += subtreesize[nxt];
    }
}

segtree st;
int ans = 0;
void ansdfs(int x, int prev = 1) {
    ans += subtreesize[x]; // kasus (x,x), dan (x,b)
    int l = eulertouridx[x];
    int r = l + subtreesize[x] - 1;
    ans += st.rangequery(l+1, r, 2*depth[x]); // kasus (a, x)
    for(int c : adj[x]) { // kasus (a,b)
        if(c == prev)continue;
        l = eulertouridx[c];
        r = l + subtreesize[c] - 1;
        int ansa = st.rangequery(l, r, 2*depth[x]);
        int ansb = subtreesize[x] - subtreesize[c] - 1;
        ans += ansa * ansb;
        ansdfs(c, x);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int n;cin>>n;
    int a, b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    depth[1] = -1; // buat bikin depth[1] = 0
    dfs(1);

    vi eulerdeptharr(n);
    for(int i=1;i<=n;i++){
        eulerdeptharr[eulertouridx[i]] = depth[i];
    }
    st = segtree(eulerdeptharr);
    ansdfs(1);
    cout << ans << endl;
    
    return 0;
}


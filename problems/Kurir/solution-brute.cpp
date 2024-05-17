// Time Complexity : O(n^2 * log(n))

#include <bits/stdc++.h>
using namespace std;
 
#define range(i,s,e)		for(int i=s;i<e;i++)

// time DFS process LCA
const int maxn = 2e5 + 5;
const int LOG = 20;
vector<int> adj[maxn];
int lift[maxn][LOG];
int depth[maxn] = {};
int starttime[maxn];
int endtime[maxn];
int timer[2*maxn];
int TIME;

void dfs(int node, int par = 1) {
    depth[node] = depth[par] + 1;
    lift[node][0] = par;
    timer[node] = TIME;
    starttime[node] = TIME++;
    for(int i=1;i<LOG;i++)
        lift[node][i] = lift[lift[node][i - 1]][i - 1];
    for(auto nxt:adj[node]) {
        if (nxt == par) continue;
        dfs(nxt, node);
    }
    timer[node] = TIME;
    endtime[node] = TIME++;
}

bool isancestor(int node, int v) {
    return starttime[node] <= starttime[v] && endtime[node] >= endtime[v];
}

int lca(int node, int v) {
    if(isancestor(node, v))return node;
    if(isancestor(v, node))return v;
    for (int i=LOG-1;i>=0;i--) {
        if(!isancestor(lift[node][i], v)) node = lift[node][i];
    }
    return lift[node][0];
}

int dist(int a, int b) {
    int c = lca(a,b);
    return depth[a] + depth[b] - 2*depth[c];
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n,a,b;
    cin >> n;
    range(i,1,n) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);
    // range(i,1,n+1)prints(depth[i])
    // endline

    int ans = 0;
    range(a,1,n+1)range(b,1,n+1) {
        // print2(a,b)
        // print(lca(a,b))
        // print2(dist(a,b), dist(1,b))
        // endline
        if(dist(a,b) <= dist(1,b)) {
            // print2(a,b)
            ans++;
        }
    }
    cout << ans << endl;
    
    return 0;
}


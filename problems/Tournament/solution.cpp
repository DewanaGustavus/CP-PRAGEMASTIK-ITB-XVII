// Time Complexity : O((n + q + AMAX) * log(n))

#include <bits/stdc++.h>
using namespace std;

#define range(i,s,e)		for(int i=s;i<e;i++)
#define int                 long long

struct node{
    int l, r;
    int val = 0;
    node *tl = nullptr, *tr = nullptr;
    node(int a, int b){
        l = a;
        r = b;
    }
    int sum(int ql, int qr){
        if(ql > r || qr < l)return 0;
        if(ql <= l && r <= qr)return val;
        int ans = 0;
        if(tl)ans += tl->sum(ql, qr);
        if(tr)ans += tr->sum(ql, qr);
        return ans;
    }
};

void build(node* root){
    int l = root->l;
    int r = root->r;
    if(l == r){
        root->val = 0;
        return;
    }
    int mid = (l + r)/2;
    root->tl = new node(l, mid);
    root->tr = new node(mid+1, r);
    build(root->tl);
    build(root->tr);
    root->val = root->tl->val + root->tr->val;
}

node* add_persistent(int idx, int val, node* root){
    int l = root->l;
    int r = root->r;
    node* new_node = new node(l, r);
    int mid = (l+r)/2;
    if(l == idx && r == idx){
        new_node->val = val + root->val;
        return new_node;
    }else if(l <= idx && idx <= mid){
        new_node->tr = root->tr;
        new_node->tl = add_persistent(idx, val, root->tl);
    }else{
        new_node->tl = root->tl;
        new_node->tr = add_persistent(idx, val, root->tr);
    }
    new_node->val = new_node->tl->val + new_node->tr->val;
    return new_node;
}

node* get_persistent(node* root){
    node* new_node = new node(root->l,root->r);
    new_node->tl = root->tl;
    new_node->tr = root->tr;
    new_node->val = root->val;
    return new_node;
}

vector<node*> roots;
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    const int amax = 1e6;

    int n; cin>>n;
    int a[n];
    range(i,0,n) cin >> a[i];

    node* initial = new node(0, amax);
    build(initial);
    roots.push_back(initial);

    range(i,0,n) {
        node* new_node = add_persistent(a[i], 1, roots.back());
        roots.push_back(new_node);
    }

    // range(i,0,n + 1) {
    //     range(j,0,amax + 1) {
    //         prints(roots[i]->sum(j,j))
    //     }
    //     endline
    // }

    int q; cin >> q;
    range(i,0,q) {
        int x,l,r;
        cin >> x >> l >> r;

        int val = a[x - 1];
        int cnt = roots[r]->sum(0, val - 1) - roots[l - 1]->sum(0, val - 1);
        cout << cnt << endl;
    }

    return 0;
}







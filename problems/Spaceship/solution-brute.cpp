// Time Complexity : O(n*m^3)

#include <bits/stdc++.h>
using namespace std;

#define int                 long long
#define range(i,s,e)		for(int i=s;i<e;i++)
#define vvi   vector<vector<int>>
#define vi    vector<int>

int n, m;
vvi mat;

bool inbound(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}


int calc(int a, int b) {
    vvi destroyed(n, vi(m));

    // line
    range(i,0,n) {
        destroyed[i][a] = 1;
        destroyed[i][b] = 1;
    }

    // left diag a
    range(i,0,n) {
        if(!inbound(i, a - i)) break;
        destroyed[i][a - i] = 1;
    }

    // left diag b
    range(i,0,n) {
        if(!inbound(i, b - i)) break;
        destroyed[i][b - i] = 1;
    }

    // right diag a
    range(i,0,n) {
        if(!inbound(i, a + i)) break;
        destroyed[i][a + i] = 1;
    }

    // right diag b
    range(i,0,n) {
        if(!inbound(i, b + i)) break;
        destroyed[i][b + i] = 1;
    }

    // ans
    int val = 0;
    range(i,0,n) {
        range(j,0,m) {
            val += destroyed[i][j] * mat[i][j];
        }
    }

    return val;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    mat = vvi(n, vi(m));
    
    range(i,0,n) {
        range(j,0,m) {
            cin >> mat[i][j];
        }
    }

    int maxi = 0;
    range(i,0,m) {
        range(j, i + 1, m) {
            maxi = max(maxi, calc(i, j));
        }
    }

    cout << maxi << endl;


    return 0;
}


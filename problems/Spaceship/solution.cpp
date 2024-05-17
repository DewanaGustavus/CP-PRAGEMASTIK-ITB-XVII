// Time Complexity : O(n*m + m^2)

#include <bits/stdc++.h>
using namespace std;

#define int                 long long
#define range(i,s,e)		for(int i=s;i<e;i++)
#define vvi   vector<vector<int>>
#define vi    vector<int>

int n, m;
vvi mat;
vi memo_line, memo_left, memo_right;

bool inbound(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}


void precompute() {
    memo_line = vi(m);
    range(i,0,n) {
        range(j,0,m) {
            memo_line[j] += mat[i][j];
        }
    }

    memo_left = vi(m);
    memo_right = vi(m);
    range(k,0,m) {
        range(i,0,n) {
            if(!inbound(i, k-i)) break;
            memo_left[k] += mat[i][k-i];
        }
        range(i,0,n) {
            if(!inbound(i, k+i)) break;
            memo_right[k] += mat[i][k+i];
        }
    }
}


int calc(int a, int b) {
    int vala = memo_line[a] + memo_left[a] + memo_right[a] - 2 * mat[0][a];
    int valb = memo_line[b] + memo_left[b] + memo_right[b] - 2 * mat[0][b];

    int intersection_left = 0, intersection_mid = 0, intersection_right = 0;
    int dif = b - a;
    if (inbound(dif, b - dif)) {
        intersection_left = mat[dif][b - dif];
    }
    if (inbound(dif, a + dif)) {
        intersection_right = mat[dif][a + dif];
    }
    if ((dif%2 == 0) && inbound(dif / 2, a + dif / 2)) {
        intersection_mid = mat[dif/2][a + dif / 2];
    }

    int val = vala + valb - intersection_left - intersection_mid - intersection_right;

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

    precompute();

    int maxi = 0;
    range(i,0,m) {
        range(j, i + 1, m) {
            maxi = max(maxi, calc(i, j));
        }
    }

    cout << maxi << endl;


    return 0;
}

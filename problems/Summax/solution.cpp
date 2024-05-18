#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;

int squared(int n)
{
    return n * n;
}

const int MAXN = 1e5;
const int MAXK = 10;
int dp[MAXN + 1][MAXK + 1];

// Time Complexity O ( N * K * K )
int32_t main()
{

    int N, K;
    cin >> N >> K;
    int arr[N + 1]; // 1-based indexing

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    int prefix_sum[N + 1] = {0};
    for (int i = 1; i <= N; i++)
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];


    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= K; j++)
            dp[i][j] = -INF;

    dp[0][0] = 0;
    dp[1][0] = arr[1];
    dp[1][1] = squared(arr[1]);

    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j <= K; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                if(k == 0){
                    dp[i][j] = max(dp[i][j],arr[i] + dp[i-1][j]);
                }
                else if(k == i){
                    dp[i][j] = max(dp[i][j],squared(prefix_sum[i]) + dp[i-k][j-k]);
                }else{
                    dp[i][j] = max(dp[i][j],squared(prefix_sum[i]-prefix_sum[i-k]) + dp[i-k-1][j-k] + arr[i-k]);
                }
            }
        }
    }

    cout << dp[N][K] << endl
;
    return 0;
}

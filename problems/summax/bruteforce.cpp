#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;

int binary_exponentiation(int base, int pow)
{
    int ans = 1;

    for (int i = 0; i < 64; i++)
    {
        if (pow & (1LL << i))
            ans *= base;
        base *= base;
    }

    return ans;
}

int squared(int n)
{
    return n * n;
}

// Time Complexity O ( N * (2 ^ N) )
int32_t main()
{

    int N, K;
    cin >> N >> K;
    int arr[N + 1];

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    int ans = -INF;

    for (int i = 0; i < binary_exponentiation(2, N); i++)
    {
        int flag[N+1] = {0};

        for(int j = 0;j < N;j++){
            if(i & (1<<j)){
                flag[j+1] = 1;
            }
        }

        int cnt = 0;
        for(int j = 1;j <= N;j++) cnt += flag[j];

        if(cnt <= K){
            
            int sum_merge = 0;
            int sum_arr = 0;
            int in = 0;

            vector<int> v;

            for(int k = 1;k <= N;k++){
                if(flag[k]){
                    in = 1;
                    sum_merge += arr[k];
                }else{
                    if(in){
                        v.push_back(squared(sum_merge));
                        sum_merge = 0;
                        in = 0;
                    }
                    v.push_back(arr[k]);
                }
            }

            if(in){
                v.push_back(squared(sum_merge));
            }

            for(int x : v) sum_arr += x;
            ans =  max(ans,sum_arr);
        }
    }

    cout << ans;

    return 0;
}
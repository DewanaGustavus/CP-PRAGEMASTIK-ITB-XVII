#include <bits/stdc++.h>
using namespace std;

int first[26];

int main()
{
    string s, t;
    cin >> s >> t;

    int ans = 1;
    int curIdx = -1;
    for (int i = 0; i < 26; i++)
    {
        first[i] = -1;
    }

    for (int i = 0; i < s.length(); i++)
    {
        int alp = s[i] - 'a';
        if (first[alp] == -1)
            first[alp] = i;
    }

    for (int i = 0; i < t.length(); i++)
    {
        int alp = t[i] - 'a';
        if (first[alp] == -1){
            ans = -1;
            break;
        }
        else{
            bool found = false;
            for(int j = curIdx + 1; j < s.length(); j++){
                int sAlp = s[j] - 'a';
                if(sAlp == alp){
                    curIdx = j;
                    found = true;
                    break;
                }
            }
            if(!found){
                ans += 1;
                curIdx = first[alp];
            }
        }
    }

    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
 
set<int> occ[26];

int main() {
    string s, t;
    cin >> s >> t;

    for(int i=0; i<(int)s.length(); i++){
        int alp = s[i] - 'a';
        occ[alp].insert(i);
    }

    int ans = 1;
    int curIdx = -1;

    for(int i=0; i<(int)t.length(); i++){
        int alp = t[i] - 'a';
        auto it = occ[alp].upper_bound(curIdx);

        // ada
        if (it != occ[alp].end()){
            curIdx = *it;
        }

        // gk ada
        else if(occ[alp].size() > 0){
            curIdx = *occ[alp].begin();
            ans += 1;
        }
        else{
            ans = -1;
            break;
        }
    }

    cout<<ans<<endl;
    
}
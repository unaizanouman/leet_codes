#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int nextBeautifulNumber(int n){
        vector<int> vals;
        for(int mask=1;mask<(1<<9);++mask){
            string s;
            int len=0;
            for(int d=1;d<=9;++d) if(mask&(1<<(d-1))){
                len+=d;
                s.append(d,char('0'+d));
            }
            if(len==0||len>7) continue;
            sort(s.begin(),s.end());
            do{
                long long v=0;
                for(char c:s) v=v*10+(c-'0');
                if(v<=20000000) vals.push_back((int)v);
            }while(next_permutation(s.begin(),s.end()));
        }
        sort(vals.begin(),vals.end());
        vals.erase(unique(vals.begin(),vals.end()),vals.end());
        for(int x:vals) if(x>n) return x;
        return -1;
    }
};

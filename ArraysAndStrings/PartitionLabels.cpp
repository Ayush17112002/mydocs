#include<bits/stdc++.h>
using namespace std;
int main(){
    string s; cin>>s;
    unordered_map<char,int> mp;
    for(int i = 0; i < s.length(); i++){
        mp[s[i]] = i;
    }
    vector<int> ans;
    int len = 0, i = 0, mx = mp[s[0]];
    while(i < s.length()){
        if(i == mx){ 
            len++;
            ans.push_back(len);
            len = 0;
            if(i < s.length()-1){
                mx = mp[s[i+1]];
            }
            i++;
            continue;
        }
        if(mp[s[i]] > mx){
            mx = mp[s[i]];
        }
        len++;
        i++;
    } 
    for(auto it : ans) cout<<it<<" ";
    return 0;
}
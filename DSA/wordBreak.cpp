#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1e9+7
bool wordBreak(string s, vector<string>& wordDict) {
            unordered_set<string> st;
            int n = s.length();
            for(int i = 0; i < wordDict.size(); i++){
                st.insert(wordDict[i]);
            }
            vector<int> dp(n,INT_MAX);
            for(int i = n-1; i >= 0; i--){
                //keep string till ith
                //check for (0,i) each cut and rest's ans from dp
                string tmp = "";
                int ans = INT_MAX;
                for(int j = i; j <= n-2; j++){
                    tmp += s[j];
                    if(st.find(tmp) == st.end()){
                        continue;
                    }else{
                        if(dp[j+1] == INT_MAX){
                            //it is not possible to break (0,jth) string
                            continue;
                        }else{
                            ans = min(ans, 1+dp[j+1]);
                        }
                    }
                }
                tmp += s[n-1];
                if(st.find(tmp) != st.end()){
                    ans = 0;
                }
                dp[i] = ans;
            }
            for(int&i:dp) cout<<i<<endl;
            return true;
    }
int main(){
    vector<string> v = {"i", "like", "sam", "sung", "samsung", "mobile", "ice", "cream" ,"icecream" ,"man" ,"go" ,"mango"};
    wordBreak("ilikesamsung",v);
    return 0;
}
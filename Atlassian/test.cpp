#include<bits/stdc++.h>
using namespace std;
int dfs(unordered_map<string,vector<string>>&mp, set<string>&vis,string src, set<string>&ans){
    vis.insert(src);
    ans.insert(src);
    int tmp=1;
    for(int i=0; i < mp[src].size(); i++){
        if(vis.find(mp[src][i])==vis.end()){
            tmp += dfs(mp,vis,mp[src][i],ans);
        }
    }
    return tmp;
}
void solution(unordered_map<string,vector<string>>&edges,set<string>&st,int n,string&target,int num){
    //viisted array that stores all problems that have been visited till now
    set<string>vis;
    //answer that stores every problem and all the problems that are similar to it.
    unordered_map<string,set<string>>ans;


    for(auto it=st.begin();it!=st.end();it++){
        if(vis.find(*it)!=vis.end()){
            continue;
        }else{
            //if the problem has yet not been included in any of our component
            set<string>component; //that stores all the problems that are similar to *it string
            int cnt = dfs(edges,vis,*it,component);
            for(auto it = component.begin(); it!=component.end(); it++){
                ans[*it]=component;
            }
        }
    }
    for(auto it=ans[target].begin(); it!=ans[target].end();it++){
        if(*it == target)continue;
        if(num>0){
            cout<<*it<<endl;
            num--;
        }
    }
    
}
int main(){
    int n; cin>>n;
    int m; cin>>m;
    set<string>str;
    unordered_map<string,vector<string>>edges;
    for(int i=0;i<m;i++){
        string a,b; cin>>a>>b;
        str.insert(a);
        str.insert(b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    string target; int num; cin>>target>>num;
    solution(edges,str,m,target,num);
    return 0;
}
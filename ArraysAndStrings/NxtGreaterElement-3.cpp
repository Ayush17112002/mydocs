#include<bits/stdc++.h>
using namespace std;
int main(){
    string s; cin>>s;
    int n = s.length();
    stack<int> st;
    st.push(0);
    int i = 1;
    pair<int,int> ans = {-1,-1}; //first -> prev lesser, second -> index
    vector<pair<int,int>> vec;
    while(i < n){
        int ele = (s[i] - '0');
        while(st.size() > 0){
            if((s[st.top()] - '0') < ele){
                vec.push_back({st.top(), i});
                break;
            }else{
                st.pop();
            }
        }
        st.push(i);
        i++;
    }
    if(vec.size() > 0){
        sort(vec.begin(), vec.end());
        int i = vec[vec.size()-1].first , j = vec[vec.size()-1].second; 
        swap(s[i], s[j]);
        vector<char> ch;
        for(int id = i+1; id < s.length(); id++){
            ch.push_back(s[id]);
        }
        sort(ch.begin(), ch.end());
        cout<<s.substr(0,i+1);
        for(auto it : ch) cout<<it;
    }else cout<<"-1";
    return 0;
}
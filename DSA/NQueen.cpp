#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> check, ans, tmp;

void fillrow(int n, int r, int val){
    for(int i = 0; i < n; i++){
         if(check[r][i] == 0) check[r][i]=val;
    }
}
void fillcol(int n, int r, int c, int val){
    for(int i = r; i < n; i++){
        if(check[i][c] == 0) check[i][c]=val;
    }
}
void filldiagonal(int n, int r, int c, int val){
    for(int i = r, j = c; i < n && j < n; i++,j++){
        if(check[i][j] == 0)check[i][j]=val;
    }
    for(int i = r, j = c; i < n && j>=0; i++,j--){
        if(check[i][j] == 0)check[i][j]=val;
    }
}
void unfillrow(int n, int r, int val){
    for(int i = 0; i < n; i++){
        if(check[r][i] == val) check[r][i]=0;
    }
}
void unfillcol(int n, int r, int c, int val){
    for(int i = r; i < n; i++){
        if(check[i][c] == val) check[i][c]=0;;
    }
}
void unfilldiagonal(int n, int r, int c, int val){
    for(int i = r, j = c; i < n && j < n; i++,j++){
        if(check[i][j] == val) check[i][j]=0;
    }
    for(int i = r, j = c; i < n && j>=0; i++,j--){
        if(check[i][j] == val) check[i][j]=0;
    }
}
bool solveNQ(int n, int r){
    if(r == n){
         vector<int> getit;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(ans[i][j] == 1) getit.push_back(j+1);
            }
        }
        tmp.push_back(getit);
        return true;
    }
    //place n queens
    //after placing 1 queen on valid cell solve the question for r-1 queens
    for(int i = 0; i < n; i++){
        if(check[r][i] == 0){
            //u can place the queen here.
            fillrow(n,r,r+1);
            fillcol(n,r,i,r+1);
            filldiagonal(n,r,i,r+1);
            ans[r][i] = 1;
            bool checkit = solveNQ(n,r+1);
            unfillrow(n,r,r+1);
            unfillcol(n,r,i,r+1);
            unfilldiagonal(n,r,i,r+1);
            ans[r][i] = 0;
        }
    }
    return false;
}

int main(){
    int n; cin>>n;
    check.resize(n,vector<int>(n,0));
    ans.resize(n,vector<int>(n,0));
    solveNQ(n,0);
    int sz = tmp.size();
    for(int i = 0; i < sz; i++){
        for(int j = 0; j < n; j++) cout<<tmp[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}
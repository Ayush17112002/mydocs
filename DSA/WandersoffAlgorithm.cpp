#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
/*bool moveTheKnight(int n, int i, int j, int moveNo){
    //knight is at (i,j)
    //there are total 8 moves
    v[i][j]=moveNo;
    if(moveNo == ((n*n) - 1)){
        return true;
    }
    pair<int,int> moves[8] = {{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2}};
    for(int k = 0; k < 8; k++){
        int idash = moves[k].first+i;
        int jdash = moves[k].second+j;
        bool check = false;
        if(idash>=0 && idash<n && jdash>=0 && jdash<n && v[idash][jdash]==-1) check = moveTheKnight(n,idash,jdash,moveNo+1);
        if(check){
            return true;
        }else{
            continue;
        }
    }
    v[i][j]=-1;
    return false;
}
*/
bool isSafe(int i, int j, int n){
    if(i>=0 && j>=0 && i<n && j<n && v[i][j]==-1){
        return true;
    }
    return false;
}
//this is using WARDENSOFF'S ALGO 
//from all possible options choose one such cell which has minimum accessibility i.e. that cell from where we can move to minimum no. of cells
bool moveTheKnight(int n, int i, int j, int moveNo){
    //knight is at (i,j)
    //there are total 8 moves
    v[i][j]=moveNo;
    if(moveNo == ((n*n) - 1)){
        return true;
    }
    pair<int,int> moves[8] = {{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2}};
    int mnacc=10;
    pair<int,int> p = {-1,-1};
    for(int k = 0; k < 8; k++){
        int idash = moves[k].first+i;
        int jdash = moves[k].second+j;
        //find accessibility of (id,jd)
        if(isSafe(idash,jdash,n)){
        int acc=0;
        for(int m = 0; m < 8; m++){
            int idoubledash = moves[m].first+idash;
            int jdoubledash = moves[m].second+jdash;
            if(isSafe(idoubledash,jdoubledash,n))acc++;
        }
        if(acc < mnacc){
            mnacc=acc;
            p.first=idash;
            p.second=jdash;
        }
        }
    }
    if(p.first==-1 && p.second==-1){
        v[i][j]=-1;
        return false;   
    }else{
        if(moveTheKnight(n,p.first,p.second,moveNo+1)) return true;
        return false;
    }
}


int main(){
    int n; cin>>n;
    v.resize(n,vector<int>(n,-1));
    bool ans = moveTheKnight(n,0,0,0);
    if(ans){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) cout<<v[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
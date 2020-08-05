#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define pb push_back
#define endl '\n'
using namespace std;
const int N=500,M=9,K=5000;
int n,m,k;
int mat[N][K],Count[N][M],sorted_mat[K][N],ans[N],dp[K],visited[N];
int x;
bool comp(int i,int j){
    return Count[i][x]>Count[j][x];
}
bool maxx(int &j,int &i){
    for(int x=0;x<n;x++){
        if(!visited[x]){
            i=x;
            visited[i]=true;
            return true;
        }
    }
    
    return false;
}
void give_ans(int j){
    int i;
    while(maxx(j,i)){
        int temp=mat[i][j];
        ans[i]=temp;
        int minn=dp[j]+1;
        for(int z=0;z<k;z++){
            if(mat[i][z]==temp)
                dp[z]++;
            if(minn>dp[z]){
                j=z;
                minn=dp[j];
            }
        }
    }
    
}
void solve(){
    cin>>n>>m>>k;
    
    memset(Count,0,sizeof(Count));
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cin>>mat[i][j],mat[i][j]--;
            Count[i][mat[i][j]]++;
        }
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++)
            sorted_mat[i][j]=j;
    }

    for(int i=0;i<k;i++){
        x=i;
        sort(sorted_mat[i],sorted_mat[i]+n,comp);
    }
    for(int i=0;i<k;i++)
        dp[i]=0;
    for(int i=0;i<n;i++)
        visited[i]=false;
    give_ans(0);
    
    for(int i=0;i<n;i++){
        cout<<ans[i]+1<<' ';
    }
    cout<<endl;
}
int main() {
	fastio;
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
	
	return 0;
}

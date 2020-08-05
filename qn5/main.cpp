#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define pb push_back
using namespace std;
void solve(){
    int n;
    cin>>n;
    int a[n];
    long x;
    for(int i=0;i<n;i++){
        cin>>x;
        x=abs(x);
        
        if(x%4==0)
            a[i]=4;
        else if(x%2==0)
            a[i]=2;
        else
           a[i]=1;
        
    }
    vector<pair<int,int>> vec;
    
    vec.pb({-1,4});
    for(int i=0;i<n;i++){
        if(a[i]==2 || a[i]==4)
            vec.pb({i,a[i]});
    }
    vec.pb({n,4});
    int s=vec.size();
    long r=0;
    for(int i=0;i<s;i++){
        if(vec[i].second==2){
            r+=((long)(vec[i].first-vec[i-1].first)*(long)(vec[i+1].first-vec[i].first));
        }
    }
    long temp=(n*(n+1))/2;
    cout<<temp-r<<'\n';
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

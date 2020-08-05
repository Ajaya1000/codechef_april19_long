#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define pb push_back
using namespace std;
int solve(){
    int x,k;
    cin>>x>>k;
    int count=0;
    int i=2;
    while(i<=x){
        while(x%i==0 && x>=i){
            count++;
            x=x/i;
        }
        if(count>=k)
            return 1;
        i++;
    }
    return 0;
}
int main() {
	fastio;
	int t;
	cin>>t;
	while(t--){
	    cout<<solve()<<'\n';
	}
	
	return 0;
}

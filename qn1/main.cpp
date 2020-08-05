#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define pb push_back
using namespace std;
string solve(){
    int n;
    cin>>n;
    int a[n],d=6;
    for(auto &x:a)
        cin>>x;
    for(auto &x:a){
        d++;
        if(x){
            if(d<6)
                return "NO\n";
            d=0;
        }
    }
    
    return "YES\n";
}
int main() {
	fastio;
	int t;
	cin>>t;
	while(t--){
	    cout<<solve();;
	}
	
	return 0;
}

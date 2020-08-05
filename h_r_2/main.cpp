#include <iostream>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    int res=1;
    int temp;
    while(k){
        temp=n/k;
        res*=temp;
        n-=temp;
        k--;
    }
    cout<<res<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
	return 0;
}

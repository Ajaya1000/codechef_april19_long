#include <iostream>
using namespace std;
void solve(){
    int n;cin>>n;
    string s,u;
    cin>>s>>u;
    int score=0;
    for(int i=0;i<n;i++){
        if(u[i]==s[i])
            score++;
        else if(u[i]!='N')
            i++;
    }
    cout<<score<<'\n';
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

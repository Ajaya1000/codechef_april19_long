#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define pb push_back
#define ll long long
#define endl '\n'
using namespace std;
//using namespace boost::multiprecision;
int main() {
	fastio;
	int n;cin>>n;
	long a[n];
	for(int i=0;i<n;i++)
	    cin>>a[i];
	ll pre[n];
	pre[0]=a[0];
	
	for(int i=1;i<n;i++)
	    pre[i]=pre[i-1]+a[i];
	sort(pre,pre+n);
	
	int count=1;
	ll temp=pre[0];
	vector<ll> vec;
	ll zeros=0;
    if(temp==0)
        zeros=1;
	for(int i=1;i<n;i++){
	    if(pre[i]==temp)
	        count++;
	    else{
	        if(count>1)
	            vec.pb(count);
	        count=1;
	        temp=pre[i];
	    }
	    
	    if(pre[i]==0)
	        zeros++;
	}
    if(count>1)
        vec.pb(count);
	ll res=0;
	for(auto x:vec){
	    res+=(x*(x-1)/2);
	}
	res+=zeros;
	ll total=n;
	total=n*(n+1)/2;
	cout<<total-res<<endl;
	
	return 0;
}

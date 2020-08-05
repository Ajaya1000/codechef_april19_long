#include <bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define pb push_back
//using namespace boost::multiprecision;
using namespace std;
const int M=1e9+7;
const int N=1e6+1;
const int K=1e5+1;
int n;
vector<bool> a(N,true);
vector<int> way(N);
vector<int> prime;
vector<long> V(K,0);


void sieve(){
    for(int i=2;i<N;i++){
        if(a[i])
            for(int j=i+i;j<N;j+=i)
                a[j]=false;
    }
    for(int i=2;i<N;i++)
        if(a[i])
            prime.pb(i);
}


void bfs(vector<vector<int>> &tree,int x,int y){
    vector<bool> visited(n,false);
    way[x]=-1;
    
    queue<int> q;
    q.push(x);
    
    int qt;
    while(!q.empty()){
        qt=q.front();
        q.pop();
        visited[qt]=true;
        for(auto i:tree[qt]){
            if(!visited[i]){
                q.push(i);
                way[i]=qt;
            }
            if(visited[y])
                    break;
        }
        if(visited[y])
                break;
    }
}

long long factorModulo(int x,int y){
    long maxx=0;
    vector<long> vec;
    while(y!=-1){
        maxx=max(maxx,V[y]);
        vec.pb(V[y]);
        y=way[y];
    }
    long sq_rt=sqrt(maxx);
    
    vector<long> factors;
    for(auto p:prime){
        if(p>sq_rt)
            break;
        int count=0;
        for(auto &value:vec){
            while(value%p==0 && value>0){
                value/=p;
                count++;
            }
        }
        factors.pb(count+1);
    }
    unordered_map<int,int> mymap;
    for(auto &value:vec){
        if(value>1)
            mymap[value]+=1;
    }
    for(auto m:mymap)
        factors.pb(m.second+1);
    long long res=1;
    for(auto f:factors){
        long long fcpp=f;
        res=(res*fcpp)%M;
    }
    
    return res;
}
void solve(){
    cin>>n;
    int x,y;
    vector<vector<int>> tree(n+1);
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        tree[x].pb(y);
        tree[y].pb(x);
    }
    long value;
    for(int i=1;i<=n;i++){
        cin>>value;
        V[i]=value;
    }
    int q;cin>>q;
    while(q--){
        cin>>x>>y;
        bfs(tree,x,y);
        cout<<factorModulo(x,y)<<endl;
    }
}
int main() {
	fastio;
	sieve();

	int t;
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}

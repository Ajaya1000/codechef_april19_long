#include <bits/stdc++.h>
//#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define pb push_back
using namespace std;
string func(string s){
        vector<int> vec(26,0);
        for(auto &ch:s)
            vec[ch-'a']++;
            
        string l{""};
        ostringstream str1;
        for(auto &num:vec){
          str1<<num;
          l+=str1.str();
        }
        return l;
}
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
    string key=func("abc");
        vector<string> strs{"eaat", "teea", "a", "fate", "", "a"};
        
        unordered_map<string,vector<string>> m;
        
        //surfing through the string vector
        for(auto &s:strs){
            string key=func(s);
            m[key].push_back(s);
        }
        
         vector<vector<string>> vstr;
        //surfing through map
        
        for(auto &n:m){
            vstr.push_back(n.second);
        }
        for(auto &sr:vstr){
            for(auto sch:sr){
                cout<<sch<<" ";
            }
            cout<<endl;
        }
	return 0;
}

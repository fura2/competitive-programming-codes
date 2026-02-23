#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int q; cin>>q;
	rep(_,q){
		string s; cin>>s;
		int n=s.length();

		int ans=0;
		for(int i=4;i<n;){
			if(s.substr(i-4,5)=="kyoto" || s.substr(i-4,5)=="tokyo"){
				ans++;
				i+=5;
			}
			else{
				i++;
			}
		}
		cout<<ans<<'\n';
	}

	return 0;
}

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();

	int ans=0;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<n;j++){
			int di=j-i;
			for(int k=j+1;k<n;k++){
				int dk=k-j;
				int l=k+dk;
				if(l>=n-di) continue;
				if(s.substr(j,dk)==s.substr(k,dk)
				&& s.substr(i,di)==s.substr(n-di,di)) ans++;
			}
		}
	}
	cout<<ans<<'\n';

	return 0;
}

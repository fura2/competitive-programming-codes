#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;
	rep(i,n) for(int j=i+1;j<n;j++) for(int k=j+1;k<n;k++) {
		if(s[i]=='I' && s[j]=='O' && s[k]=='I'){
			puts("Yes");
			return 0;
		}
	}
	puts("No");
	return 0;
}

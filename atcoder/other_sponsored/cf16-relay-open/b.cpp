#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();

	char f[128];
	f['b']='d';
	f['d']='b';
	f['p']='q';
	f['q']='p';

	rep(i,(n+1)/2){
		if(s[i]!=f[s[n-i-1]]){
			puts("No");
			return 0;
		}
	}
	puts("Yes");

	return 0;
}

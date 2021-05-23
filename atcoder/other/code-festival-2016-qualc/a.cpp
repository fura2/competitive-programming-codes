#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int cnt=0;
	rep(i,s.length()){
		if(s[i]=='C' && cnt==0) cnt++;
		if(s[i]=='F' && cnt==1) cnt++;
	}
	puts(cnt==2?"Yes":"No");
	return 0;
}

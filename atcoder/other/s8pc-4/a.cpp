#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	vector<string> s(n);
	rep(i,n) cin>>s[i];
	string t; cin>>t;

	auto S=s;
	rep(i,n) for(char& c:S[i]) if(c=='?') c='z';
	sort(S.begin(),S.end());

	int l=n;
	rep(i,n) if(t<=S[i]) {
		l=i;
		break;
	}

	S=s;
	rep(i,n) for(char& c:S[i]) if(c=='?') c='a';
	sort(S.begin(),S.end());

	int r=n;
	rep(i,n) if(t<S[i]) {
		r=i;
		break;
	}

	for(int i=l;i<=r;i++) printf("%d%c",i+1,i<r?' ':'\n');

	return 0;
}

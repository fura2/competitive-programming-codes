#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint x; cin>>x;

	set<string> S;
	for(lint i=1;i*i<=x;i++) if(x%i==0) {
		string s=to_string(i),t=to_string(x/i);
		S.emplace(s+t);
		S.emplace(t+s);
	}
	cout<<S.size()<<'\n';

	return 0;
}

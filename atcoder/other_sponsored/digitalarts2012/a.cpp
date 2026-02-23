#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	vector<string> S;
	int n;
	while(1){
		string s; cin>>s;
		if(isdigit(s[0])){
			n=stoi(s);
			break;
		}
		S.emplace_back(s);
	}
	vector<string> ng(n);
	rep(i,n) cin>>ng[i];

	rep(i,S.size()){
		bool ok=true;
		rep(j,n) if(S[i].length()==ng[j].length()) {
			bool b=false;
			rep(k,S[i].length()) if(S[i][k]!=ng[j][k] && ng[j][k]!='*') b=true;
			if(!b) ok=false;
		}
		if(!ok){
			rep(k,S[i].length()) S[i][k]='*';
		}
		cout<<S[i]<<(i+1<S.size()?' ':'\n');
	}

	return 0;
}

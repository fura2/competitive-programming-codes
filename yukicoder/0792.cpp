#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	int q[1<<12][12],r[1<<12];
	rep(i,1<<n){
		rep(j,n) scanf("%d",&q[i][j]);
		scanf("%d",&r[i]);
	}

	string ans="A=";
	if(count(r,r+(1<<n),0)==0){
		ans+="⊤";
	}
	else if(count(r,r+(1<<n),1)==0){
		ans+="⊥";
	}
	else{
		bool first=true;
		rep(i,1<<n) if(r[i]==1) {
			if(!first) ans+="∨";
			first=false;

			string tmp="(";
			rep(j,n){
				if(j>0) tmp+="∧";
				if(q[i][j]==0) tmp+="¬";
				tmp+="P_"+to_string(j+1);
			}
			tmp+=")";

			ans+=tmp;
		}
	}
	cout<<ans<<'\n';

	return 0;
}

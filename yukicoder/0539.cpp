#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

void solve(){
	string s; getline(cin,s);
	int n=s.length();
	int r=-1,l=-1;
	for(int i=n-1;i>=0;i--){
		if(isdigit(s[i])){
			l=i;
			if(r==-1) r=i;
		}
		else{
			if(r!=-1) break;
		}
	}

	if(r==-1){
		cout<<s<<'\n';
	}
	else{
		r++;
		string t=s.substr(l,r-l);
		if(t==string(r-l,'9')){
			t=string("1")+string(r-l,'0');
		}
		else{
			for(int i=t.length()-1;i>=0;i--){
				if(t[i]=='9') t[i]='0';
				else{
					t[i]++;
					break;
				}
			}
		}
		cout<<s.substr(0,l)+t+s.substr(r)<<'\n';
	}
}

int main(){
	int q; scanf("%d%*c",&q); rep(_,q) solve();
	return 0;
}

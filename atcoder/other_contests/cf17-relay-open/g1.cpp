// テストケースが弱くて AC するが正しくない (反例 : L=15, S=bab, T=babba)

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int L;
	string s,t; cin>>L>>s>>t;

	if(s>t) swap(s,t);

	int n1=s.length(),n2=t.length();

	if(n1<n2 && s==t.substr(0,n1)){
		bool b=false;
		rep(i,(n2+n1-1)/n1){
			string r=t.substr(i*n1,min(n1,n2-i*n1));
			if(r.length()<n1){
				r+=s.substr(0,n1-r.length());
			}
			if(s!=r){
				if(s>r) b=true;
				break;
			}
		}
		if(b){
			swap(s,t);
			swap(n1,n2);
		}
	}

	int a,b;
	for(int i=L/n1;i>=0;i--) if((L-i*n1)%n2==0) {
		a=i;
		b=(L-i*n1)/n2;
		break;
	}
	rep(i,a) cout<<s;
	rep(i,b) cout<<t;
	cout<<'\n';

	return 0;
}

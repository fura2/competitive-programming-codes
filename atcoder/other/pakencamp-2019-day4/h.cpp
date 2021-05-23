#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	random_device seed_gen;

	int n,total=0; cin>>n;
	vector<string> s(n);
	vector<int> ofs(n);
	rep(i,n){
		cin>>s[i];
		while(s[i][0]=='0') s[i]=s[i].substr(1), ofs[i]++;
		total+=s[i].length();
	}

	int ans=0;
	vector<int> p(n),tmp(n),res(n);
	iota(p.begin(),p.end(),0);

	string t(total,'0');
	rep(_,1e4){
		rep(i,total) t[i]='0';

		int pos=0;
		rep(i,n){
			tmp[p[i]]=pos;
			rep(j,s[p[i]].length()) if(t[pos+j]=='0') t[pos+j]=s[p[i]][j];
			while(t[pos]=='1') pos++;
		}

		if(ans<pos){
			ans=pos;
			rep(i,n) res[i]=tmp[i];
		}

		shuffle(p.begin(),p.end(),mt19937(seed_gen()));
	}

	rep(i,n) printf("%d\n",res[i]-ofs[i]+100);

	return 0;
}

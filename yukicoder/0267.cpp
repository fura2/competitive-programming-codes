#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int f[128];
	f['D']=0;
	f['C']=1;
	f['H']=2;
	f['S']=3;
	f['A']=1;
	for(int i=2;i<=9;i++) f['0'+i]=i;
	f['T']=10;
	f['J']=11;
	f['Q']=12;
	f['K']=13;

	int n; cin>>n;
	string s[52];
	rep(i,n) cin>>s[i];

	sort(s,s+n,[=](string s,string t){
		return make_pair(f[s[0]],f[s[1]])<make_pair(f[t[0]],f[t[1]]);
	});

	rep(i,n) cout<<s[i]<<(i<n-1?' ':'\n');

	return 0;
}

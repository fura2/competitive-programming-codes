#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int b[10],f[10];
	rep(i,10) cin>>b[i], f[b[i]]=i;
	int n; cin>>n;
	vector<string> s(n);
	rep(i,n) cin>>s[i];

	sort(s.begin(),s.end(),[&](string t1,string t2){
		int m1=t1.length();
		int m2=t2.length();
		if(m1!=m2) return m1<m2;
		rep(i,m1) if(t1[i]!=t2[i]) return f[t1[i]-'0']<f[t2[i]-'0'];
		return false;
	});

	rep(i,n) cout<<s[i]<<'\n';

	return 0;
}

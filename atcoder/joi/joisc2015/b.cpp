// Day 1: En-JOI-able Logo Design

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int k;
	string s; cin>>k>>s;

	s=s+s;
	int n=s.length();

	vector<int> Jcum(n+1),Ocum(n+1),Icum(n+1);
	rep(i,n){
		Jcum[i+1]=Jcum[i]+(s[i]=='J'?1:0);
		Ocum[i+1]=Ocum[i]+(s[i]=='O'?1:0);
		Icum[i+1]=Icum[i]+(s[i]=='I'?1:0);
	}

	int ans=n;
	rep(i,n/2){
		int pos=i,len=1<<2*(k-1),tmp=0;
		rep(d,k){
			tmp+=len-(Jcum[pos+len]-Jcum[pos]); pos+=len;
			tmp+=len-(Ocum[pos+len]-Ocum[pos]); pos+=len;
			tmp+=len-(Icum[pos+len]-Icum[pos]); pos+=len;
			len/=4;
		}
		ans=min(ans,tmp);
	}
	printf("%d\n",ans);

	return 0;
}

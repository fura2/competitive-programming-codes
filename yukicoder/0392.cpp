#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int q; scanf("%d",&q);
	rep(_,q){
		int x; cin>>x; x++;
		string s;
		for(;x!=1;x>>=1) s+=((x&1)==0?'L':'R');
		reverse(s.begin(),s.end());
		cout<<s<<'\n';
	}
	return 0;
}

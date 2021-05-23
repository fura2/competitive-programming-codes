#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int q,base; scanf("%d%d",&q,&base);
	rep(_,q){
		int n; scanf("%d",&n);
		string s;
		while(n!=0){
			int d=n%base;
			if(d<0) d-=base;
			s+='0'+d;
			n=(n-d)/base;
		}
		reverse(s.begin(),s.end());
		if(s=="") s="0";
		cout<<s<<'\n';
	}
	return 0;
}

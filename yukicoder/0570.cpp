#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	pair<int,char> p[3];
	rep(i,3){ cin>>p[i].first; p[i].second='A'+i; }
	sort(p,p+3);
	rep(i,3) cout<<p[2-i].second<<'\n';
	return 0;
}

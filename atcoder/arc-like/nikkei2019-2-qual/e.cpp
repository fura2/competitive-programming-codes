// 全探索解の出力を見てパターンを見つけた

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; cin>>n>>k;

	if(2*k>n+1){ cout<<-1<<'\n'; return 0; }

	vector<int> a(n),b(n),c(n);
	int num=k+3*n;
	rep(i,n) c[n-i-1]=--num;
	rep(i,n) b[(i+k)%n]=--num;

	vector<pair<int,int>> p(n);
	rep(i,n) p[i]={c[i]-b[i],i};
	sort(p.rbegin(),p.rend());

	rep(i,n) a[p[i].second]=--num;

	rep(i,n) cout<<a[i]<<' '<<b[i]<<' '<<c[i]<<'\n';

	return 0;
}

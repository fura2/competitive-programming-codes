#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	vector<tuple<int,int,char>> a(3);
	rep(i,3){
		int h,w; cin>>h>>w;
		a[i]={-h,w,'A'+i};
	}
	sort(a.begin(),a.end());
	rep(i,3) cout<<get<2>(a[i])<<'\n';
	return 0;
}

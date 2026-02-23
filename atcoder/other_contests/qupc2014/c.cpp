#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w,q; cin>>h>>w>>q;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	vector<pair<int,int>> pos(128,{-1,-1});
	rep(i,h) rep(j,w) pos[B[i][j]]={i,j};

	rep(_,q){
		char c; cin>>c;
		if(pos[c].first==-1){
			cout<<"NA\n";
		}
		else{
			cout<<pos[c].first+1<<' '<<pos[c].second+1<<'\n';
		}
	}

	return 0;
}

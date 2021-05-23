#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;

	int lo=0,hi=n;
	while(hi-lo>1){
		int mi=(lo+hi)/2;

		vector<bool> used(n);
		vector<int> I(mi);
		int idx=0;
		for(int i=n-1;i>=0;i--) if(s[i]=='I') {
			used[i]=true;
			I[idx++]=i;
			if(idx==mi) break;
		}
		if(idx<mi){ hi=mi; continue; }

		vector<int> O(mi);
		idx=0;
		for(int i=n-1;i>=0;i--) if(s[i]=='O' && i<I[idx]) {
			O[idx++]=i;
			if(idx==mi) break;
		}
		if(idx<mi){ hi=mi; continue; }

		idx=0;
		for(int i=n-1;i>=0;i--) if(s[i]!='O' && i<O[idx] && !used[i]) {
			idx++;
			if(idx==mi) break;
		}
		if(idx<mi) hi=mi;
		else       lo=mi;
	}

	cout<<lo<<'\n';

	return 0;
}

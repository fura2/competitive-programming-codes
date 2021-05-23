#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; cin>>n>>k;

	int hist[128]={};
	rep(i,n){
		string s; cin>>s;
		hist[s[0]]++;
	}

	int lo=0,hi=2e4;
	while(hi-lo>1){
		int mi=(lo+hi)/2;

		int cnt=0;
		for(char c='A';c<='Z';c++) cnt+=min(hist[c],mi);
		if(cnt/mi>=k) lo=mi;
		else          hi=mi;
	}
	printf("%d\n",lo);

	return 0;
}

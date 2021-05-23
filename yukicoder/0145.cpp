#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;

	int hist[128]={};
	for(char c:s) hist[c]++;

	int ans=0;
	rep(x0,hist['y']+1){
		int tmp[128];
		copy(hist,hist+128,tmp);

		int res=0,x=x0,t;
		for(int c='v';c<'y';c++){
			t=min(x,hist[c]);
			res+=t;
			x-=t;
		}
		t=min(x,hist['u']);
		x=t;
		hist['u']-=t;
		for(int c='l';c<='u';c++){
			t=min(x,hist[c]);
			res+=t;
			x-=t;
		}
		t=min(x,hist['k']);
		x=t;
		hist['k']-=t;
		for(int c='j';c<='k';c++){
			t=min(x,hist[c]);
			res+=t;
			x-=t;
		}
		t=min(x,hist['i']);
		x=t;
		hist['i']-=t;
		for(int c='a';c<='i';c++){
			t=min(x,hist[c]);
			res+=t;
			x-=t;
		}
		ans=max(ans,res+hist['z']+(hist['y']-x0)/2);

		copy(tmp,tmp+128,hist);
	}
	printf("%d\n",ans);

	return 0;
}

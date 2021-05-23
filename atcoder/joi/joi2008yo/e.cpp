#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

inline int popcount(int x){
	x=((x>>1)&0x55555555)+(x&0x55555555);
	x=((x>>2)&0x33333333)+(x&0x33333333);
	x=((x>>4)+x)&0x0f0f0f0f;
	x+=(x>>8);
	x+=(x>>16);
	return x&0x3f;
}

int main(){
	int h,w; scanf("%d%d",&h,&w);
	vector<int> a(w);
	rep(i,h) rep(j,w) {
		int b; scanf("%d",&b);
		a[j]|=b<<i;
	}

	int ans=0;
	rep(S,1<<h){
		int tmp=0;
		rep(j,w){
			int p=popcount(a[j]^S);
			tmp+=max(p,h-p);
		}
		ans=max(ans,tmp);
	}
	printf("%d\n",ans);

	return 0;
}

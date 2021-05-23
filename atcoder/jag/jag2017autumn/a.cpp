#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,h,w; scanf("%d%d%d",&n,&h,&w);
	vector<int> x(n);
	rep(i,n) scanf("%d",&x[i]);

	int ans=0;
	for(int i=0;i<n;i+=2){
		ans+=2*w-(max(w+x[i],2*w-x[i+1])-min(x[i],w-x[i+1]));
	}
	ans*=h;
	printf("%d\n",ans);

	return 0;
}

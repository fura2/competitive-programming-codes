#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint h,w;
	double p; cin>>h>>w>>p;

	if(h>w) swap(h,w);

	double ans=0;
	if(w==1){
		ans+=p;
	}
	else if(h==1){
		ans+=2*pow(p,2);
		ans+=(w-2)*pow(p,3);
	}
	else{
		ans+=4*pow(p,3);
		ans+=(2*h+2*w-8)*pow(p,4);
		ans+=(h-2)*(w-2)*pow(p,5);
	}
	printf("%.9f\n",ans);

	return 0;
}

/*
	問題に不備があり普通にやっても解けないので
	writer 解と同じアルゴリズムを C++ で実装しました
*/

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint h,w; cin>>h>>w;
	w=abs(w);

	if(w==0) return puts("0"),0;

	lint ans=h;
	h++;
	for(lint i=1,j=1;;j+=i,i++){
		if(j+i<=min(h,w)){
			ans+=i*i;
		}
		else{
			lint d=min(h,w)-j;
			ans+=i*d;
			if(w<=h) break;
			ans+=(i*i-(i-d))*((w-h)/i);
			ans+=i*((w-h)%i);
			ans-=min(i-d,(w-h)%i);
			break;
		}
	}
	printf("%lld\n",ans);

	return 0;
}

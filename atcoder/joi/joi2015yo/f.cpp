#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n;
	lint d; scanf("%d%lld",&n,&d);
	vector<lint> x(n),y(n);
	rep(i,n) scanf("%lld%lld",&x[i],&y[i]);

	vector<pair<lint,lint>> P1,P2;
	rep(S,1<<n/2) for(int T=S;T>=0;T--) {
		T&=S;
		lint xdif=0,ydif=0;
		rep(i,n/2) if(S>>i&1) {
			if(T>>i&1) xdif+=x[i], ydif+=y[i];
			else       xdif-=x[i], ydif-=y[i];
		}
		P1.emplace_back(xdif,ydif);
	}
	rep(S,1<<(n+1)/2) for(int T=S;T>=0;T--) {
		T&=S;
		lint xdif=0,ydif=0;
		rep(i,(n+1)/2) if(S>>i&1) {
			if(T>>i&1) xdif+=x[n/2+i], ydif+=y[n/2+i];
			else       xdif-=x[n/2+i], ydif-=y[n/2+i];
		}
		P2.emplace_back(xdif,ydif);
	}

	sort(P1.rbegin(),P1.rend());
	sort(P2.begin(),P2.end());

	lint ans=-INF;
	int l=0,r=0;
	deque<lint> D;
	rep(i,P1.size()){
		while(r<P2.size() && P1[i].first+P2[r].first<=d){
			while(!D.empty() && P2[D.back()].second<=P2[r].second) D.pop_back();
			D.emplace_back(r);
			r++;
		}
		while(l<P2.size() && P1[i].first+P2[l].first<-d){
			while(!D.empty() && D.front()<=l) D.pop_front();
			l++;
		}
		if(!D.empty()) ans=max(ans,P1[i].second+P2[D.front()].second);
	}
	printf("%lld\n",ans);

	return 0;
}

// Day 4: Starry Sky

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class T>
class starry_sky_tree{
	int sz;
	vector<T> seg;

	void maintain(int u){
		if(1<=u && u<sz){
			T mx=std::max(seg[2*u],seg[2*u+1]);
			seg[u]+=mx;
			seg[2*u  ]-=mx;
			seg[2*u+1]-=mx;
		}
	}
	T max(int l,int r,int a,int b,int u,T cum)const{
		if(b<=l || r<=a) return numeric_limits<T>::min();
		if(l<=a && b<=r) return cum+seg[u];
		T lmax=max(l,r,a,(a+b)/2,2*u  ,cum+seg[u]);
		T rmax=max(l,r,(a+b)/2,b,2*u+1,cum+seg[u]);
		return std::max(lmax,rmax);
	}
public:
	starry_sky_tree(int n){
		for(sz=1;sz<n;sz<<=1);
		seg.assign(2*sz,T());
	}
	void add(int l,int r,const T& val){
		int a,b;
		for(a=l+sz,b=r+sz;a<b;a>>=1,b>>=1){
			if(a&1){ seg[a]+=val; a++; }
			if(b&1){ b--; seg[b]+=val; }
			maintain((a-1)>>1);
			maintain(b>>1);
		}
		for(int u=a-1;u>=1;u>>=1) maintain(u);
		for(int u= b ;u>=1;u>>=1) maintain(u);
	}
	T max(int l,int r)const{ return max(l,r,0,sz,1,0); }
};

int main(){
	int n; scanf("%d",&n);
	vector<int> x(n),y(n),w(n);
	rep(i,n) scanf("%d%d%d",&x[i],&y[i],&w[i]);

	{
		vector<int> p(n);
		iota(p.begin(),p.end(),0);
		sort(p.begin(),p.end(),[&](int i,int j){
			return w[i]<w[j];
		});
		auto xtmp=x,ytmp=y,wtmp=w;
		rep(i,n){
			x[i]=xtmp[p[i]];
			y[i]=ytmp[p[i]];
			w[i]=wtmp[p[i]];
		}
	}

	int ans=0;
	for(int i=n-1;i>=0;i--){
		vector<pair<int,int>> P;
		for(int j=i;j<n;j++){
			if(abs(x[j]-x[i])<=w[i] && abs(y[j]-y[i])<=w[i]){ // 枝刈り
				P.emplace_back(x[j],y[j]);
			}
		}
		sort(P.begin(),P.end());
		int N=P.size();

		vector<int> X(N),Y(N),lidx(N),ridx(N);
		rep(j,N) tie(X[j],Y[j])=P[j];
		sort(Y.begin(),Y.end());
		rep(j,N){
			lidx[j]=lower_bound(Y.begin(),Y.end(),P[j].second-w[i])-Y.begin();
			ridx[j]=upper_bound(Y.begin(),Y.end(),P[j].second)-Y.begin();
		}

		starry_sky_tree<int> SS(N);
		int l=0,r=0;
		while(r<N){
			SS.add(lidx[r],ridx[r],1);
			r++;
			while(l<r && X[r-1]-X[l]>w[i]){
				SS.add(lidx[l],ridx[l],-1);
				l++;
			}
			ans=max(ans,SS.max(0,N));
		}
	}
	printf("%d\n",ans);

	return 0;
}

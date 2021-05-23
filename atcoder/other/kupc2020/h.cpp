// thanks https://emtubasa.hateblo.jp/entry/2020/10/11/141319

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class M>
class segment_tree{
	int sz;
	vector<M> seg;
public:
	segment_tree(){}
	segment_tree(int n){ build(n); }
	template<class T>
	segment_tree(const vector<T>& a){ build(a); }
	void build(int n){
		for(sz=1;sz<n;sz<<=1);
		seg.assign(2*sz,M());
	}
	template<class T>
	void build(const vector<T>& a){
		int n=a.size();
		build(n);
		rep(i,n) seg[sz+i]=a[i];
		for(int i=sz-1;i>0;i--){
			seg[i]=seg[2*i]*seg[2*i+1];
		}
	}
	const M& operator[](int i)const{
		return seg[sz+i];
	}
	void update(int i,const M& x){
		i+=sz;
		seg[i]=x;
		for(i>>=1;i>0;i>>=1) seg[i]=seg[2*i]*seg[2*i+1];
	}
	M get(int l,int r)const{
		M lcum,rcum;
		for(int a=l+sz,b=r+sz;a<b;a>>=1,b>>=1){
			if(a&1) lcum=lcum*seg[a++];
			if(b&1) rcum=seg[--b]*rcum;
		}
		return lcum*rcum;
	}
};

class monoid_L{
	int f[5];
public:
	monoid_L(){
		iota(f,f+5,0);
	}
	monoid_L(const int* F){
		rep(x,5) f[x]=F[x];
	}
	monoid_L operator*(const monoid_L& a)const{
		int res[5];
		rep(x,5) res[x]=a.f[f[x]];
		return res;
	}
	int operator[](int x)const{ return f[x]; }
};

class monoid_R{
	int f[5];
public:
	monoid_R(){
		iota(f,f+5,0);
	}
	monoid_R(const int* F){
		rep(x,5) f[x]=F[x];
	}
	monoid_R operator*(const monoid_R& a)const{
		int res[5];
		rep(x,5) res[x]=f[a.f[x]];
		return res;
	}
	int operator[](int x)const{ return f[x]; }
};

int mex(vector<int> a){
	bool b[5]={};
	for(int x:a) b[x]=true;
	rep(x,5) if(!b[x]) return x;
	abort();
}

int main(){
	int h,w; cin>>h>>w;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	vector Grundy(h+1,vector(w,4));
	for(int i=h-1;i>=0;i--){
		// go left
		segment_tree<monoid_L> SL(2*w);
		rep(j,w){
			if(B[i][j]=='#'){
				int ng[5]={4,4,4,4,4};
				SL.update( j ,ng);
				SL.update(j+w,ng);
			}
			else{
				int f[5];
				rep(x,5) f[x]=mex({x,Grundy[i+1][j]});
				SL.update( j ,f);
				SL.update(j+w,f);
			}
		}

		// go right
		segment_tree<monoid_R> SR(2*w);
		rep(j,w){
			if(B[i][j]=='#'){
				int ng[5]={4,4,4,4,4};
				SR.update( j ,ng);
				SR.update(j+w,ng);
			}
			else{
				int f[5];
				rep(x,5) f[x]=mex({x,Grundy[i+1][j]});
				SR.update( j ,f);
				SR.update(j+w,f);
			}
		}

		rep(j,w) if(B[i][j]!='#') {
			int gl=SL.get(j+1,j+w)[4];
			int gr=SR.get(j+1,j+w)[4];
			Grundy[i][j]=mex({gl,gr,Grundy[i+1][j]});
		}
	}

	int ans=0;
	rep(i,h) rep(j,w) if(B[i][j]=='B') ans^=Grundy[i][j];
	puts(ans!=0?"Alice":"Bob");

	return 0;
}

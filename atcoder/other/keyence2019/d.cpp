#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class mint{
	static const int MOD=1e9+7;
	int x;
public:
	mint():x(0){}
	mint(long long y){ x=y%MOD; if(x<0) x+=MOD; }

	mint& operator+=(const mint& m){ x+=m.x; if(x>=MOD) x-=MOD; return *this; }
	mint& operator-=(const mint& m){ x-=m.x; if(x<   0) x+=MOD; return *this; }
	mint& operator*=(const mint& m){ x=1LL*x*m.x%MOD; return *this; }
	mint& operator/=(const mint& m){ return *this*=inverse(m); }
	mint operator+(const mint& m)const{ return mint(*this)+=m; }
	mint operator-(const mint& m)const{ return mint(*this)-=m; }
	mint operator*(const mint& m)const{ return mint(*this)*=m; }
	mint operator/(const mint& m)const{ return mint(*this)/=m; }
	mint operator-()const{ return mint(-x); }

	friend mint inverse(const mint& m){
		int a=m.x,b=MOD,u=1,v=0;
		while(b>0){ int t=a/b; a-=t*b; swap(a,b); u-=t*v; swap(u,v); }
		return u;
	}

	friend istream& operator>>(istream& is,mint& m){ long long t; is>>t; m=mint(t); return is; }
	friend ostream& operator<<(ostream& os,const mint& m){ return os<<m.x; }
	int to_int()const{ return x; }
};

int main(){
	int h,w; scanf("%d%d",&h,&w);

	vector<bool> row(h*w),col(h*w);
	rep(i,h){
		int a; scanf("%d",&a); a--;
		if(row[a]) return puts("0"),0;
		row[a]=true;
	}
	rep(j,w){
		int b; scanf("%d",&b); b--;
		if(col[b]) return puts("0"),0;
		col[b]=true;
	}

	mint ans=1;
	int cnt1=0,cnt2=0;
	rep(t,h*w){
		int num=h*w-t-1;
		if(row[num] && col[num]){
			cnt1++;
			cnt2++;
		}
		else if(row[num]){
			ans*=cnt2;
			cnt1++;
		}
		else if(col[num]){
			ans*=cnt1;
			cnt2++;
		}
		else{
			if(cnt1*cnt2<t) return puts("0"),0;
			ans*=cnt1*cnt2-t;
		}
	}
	printf("%d\n",ans.to_int());

	return 0;
}

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class Eratosthenes_sieve{
	vector<bool> er;
	vector<int> p;
public:
	Eratosthenes_sieve(int n):er(n+1,true){
		if(n>=0) er[0]=false;
		if(n>=1) er[1]=false;
		for(int i=2;i*i<=n;i++) if(er[i]) for(int j=i*i;j<=n;j+=i) er[j]=false;
		rep(i,n+1) if(er[i]) p.emplace_back(i);
	}

	vector<int> primes()const{ return p; }

	bool is_prime(int a)const{
		assert(a<=(int)er.size()-1);
		return a>=0 && er[a];
	}
};

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n),val(n);
	rep(i,n) scanf("%d%d",&a[i],&val[i]);

	vector<int> p=Eratosthenes_sieve(300).primes();
	int m=p.size();

	vector<int> I0; // すべての素因数が 17 以下のもの
	vector I(m,vector<int>()); // I[j] : 素因数 p[j] をもつもの (p[j]>17)
	rep(i,n){
		bool b=false;
		for(int j=7;j<m;j++) if(a[i]%p[j]==0) {
			I[j].emplace_back(i);
			b=true;
		}
		if(!b) I0.emplace_back(i);
	}

	int ans=0;
	rep(i2,9) rep(i3,6) rep(i5,4) rep(i7,3) rep(i11,3) rep(i13,3) rep(i17,3) {
		int i[7]={i2,i3,i5,i7,i11,i13,i17};

		auto x=a;
		rep(j,n) rep(k,7) rep(_,i[k]) if(x[j]%p[k]==0) x[j]/=p[k];

		int sum=0;
		for(int j:I0){
			if(x[j]==1) sum+=val[j];
		}
		for(int k=7;k<m;k++){
			int tmp=0;
			for(int j:I[k]) if(x[j]==p[k]) tmp+=val[j];
			if(tmp>0) sum+=tmp;
		}
		ans=max(ans,sum);
	}
	printf("%d\n",ans);

	return 0;
}

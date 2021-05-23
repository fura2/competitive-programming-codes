// 判定が IE になる
// サンプルは一致した

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

typedef long long lint;

template<class G>
class Fenwick_tree{
	vector<G> a;
public:
	Fenwick_tree(int n):a(n){}
	void add(int i,G val){
		for(i++;i<=a.size();i+=i&-i) a[i-1]+=val;
	}
	G sum(int l,int r)const{
		if(l==0){
			G res{};
			for(;r>0;r-=r&-r) res+=a[r-1];
			return res;
		}
		return sum(0,r)-sum(0,l);
	}
	int lower_bound(G val)const{
		if(val<=G{}) return 0;
		int x=0,k;
		for(k=1;k<=a.size();k<<=1);
		for(k>>=1;k>0;k>>=1) if(x+k<=a.size() && a[x+k-1]<val) val-=a[x+k-1], x+=k;
		return x;
	}
	int upper_bound(G val)const{
		if(val<G{}) return 0;
		int x=0,k;
		for(k=1;k<=a.size();k<<=1);
		for(k>>=1;k>0;k>>=1) if(x+k<=a.size() && a[x+k-1]<=val) val-=a[x+k-1], x+=k;
		return x;
	}
};

Fenwick_tree<lint> F1(100000),F2(100000);

void init(int n,int* a){
	rep(i,n){
		F1.add(i,a[i]);
		F2.add(i,1LL*a[i]*a[i]);
	}
}

void update(int i,int x){
	lint a1=F1.sum(i,i+1);
	lint a2=F2.sum(i,i+1);
	F1.add(i,x-a1);
	F2.add(i,1LL*x*x-a2);
}

int variance(int l,int r){
	r++;
	lint s1=F1.sum(l,r);
	lint s2=F2.sum(l,r);
	int n=r-l;
	return (s2*n-s1*s1)/(n*n);
}

/*
int main(){
	int n,a[100];
	scanf("%d",&n);
	rep(i,n) scanf("%d",&a[i]);

	init(n,a);
	printf("%d\n",variance(0,2));
	printf("%d\n",variance(1,2));
	update(2,0);
	printf("%d\n",variance(0,2));
	printf("%d\n",variance(1,2));
	update(1,11);
	printf("%d\n",variance(0,2));

	return 0;
}
*/

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class G>
class Fenwick_tree_dual{
	vector<G> a;
public:
	Fenwick_tree_dual(int n):a(n){}
	void add(int l,int r,const G& val){
		if(l==0){
			for(;r>0;r-=r&-r) a[r-1]+=val;
			return;
		}
		add(0,r,val);
		add(0,l,-val);
	}
	G sum(int i)const{
		G res{};
		for(i++;i<=a.size();i+=i&-i) res+=a[i-1];
		return res;
	}
};

int main(){
	int n; scanf("%d",&n);

	Fenwick_tree_dual<lint> F(n+1);
	rep(i,n){
		int a; scanf("%d",&a);
		F.add(i+1,i+2,a);
	}

	for(int i=n;i>0;i--){
		lint x=F.sum(i);
		if(x%i!=0){
			puts("No");
			return 0;
		}
		F.add(0,i,x/i);
	}
	puts("Yes");

	return 0;
}

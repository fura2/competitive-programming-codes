#include <bits/stdc++.h>
#include <atcoder/all>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using namespace atcoder;

int op(int x,int y){ return max(x,y); }
int e(){ return -1; }

int main(){
	int n,q; scanf("%d%d",&n,&q);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	segtree<int,op,e> S(a);

	rep(_,q){
		int type,x,y; scanf("%d%d%d",&type,&x,&y);
		x--;
		if(type==1){
			S.set(x,y);
		}
		else if(type==2){
			printf("%d\n",S.prod(x,y));
		}
		else{
			printf("%d\n",S.max_right(x,[&](int v){ return v<y; })+1);
		}
	}

	return 0;
}

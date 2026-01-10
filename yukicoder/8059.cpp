#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int q; scanf("%d",&q);
	rep(_,q){
		int x; scanf("%d",&x);
		puts(x%45==0?"Y":"N");
	}
	return 0;
}

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int q; scanf("%*d%d",&q);
	rep(_,q){
		int a,b,s,t; scanf("%d%d%d%d",&a,&b,&s,&t);
		printf("%d\n",100*(t-s-max(min(t,b)-max(s,a),0)));
	}
	return 0;
}

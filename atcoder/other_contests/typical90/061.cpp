#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int q; scanf("%d",&q);
	deque<int> D;
	rep(_,q){
		int type,x; scanf("%d%d",&type,&x);
		if     (type==1) D.emplace_front(x);
		else if(type==2) D.emplace_back(x);
		else printf("%d\n",D[x-1]);
	}
	return 0;
}

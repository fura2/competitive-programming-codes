#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,q; scanf("%d%d",&n,&q);

	vector<int> a(n);
	rep(i,n) a[i]=i;
	rep(_,q){
		int x; scanf("%d",&x); x--;
		vector<int> b(n);
		b[0]=a[x];
		int idx=1;
		rep(i,n) if(i!=x) b[idx++]=a[i];
		a=b;
	}
	printf("%d\n",a[0]+1);

	return 0;
}

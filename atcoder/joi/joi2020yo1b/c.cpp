#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	int hist[101]={};
	rep(i,n){
		int a; scanf("%d",&a);
		hist[a]++;
	}
	printf("%d\n",*max_element(hist,hist+m+1));
	return 0;
}

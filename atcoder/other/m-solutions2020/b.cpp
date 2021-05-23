#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c,k; scanf("%d%d%d%d",&a,&b,&c,&k);
	while(a>=b && k>0) b*=2, k--;
	while(b>=c && k>0) c*=2, k--;
	puts(a<b&&b<c?"Yes":"No");
	return 0;
}

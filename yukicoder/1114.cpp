#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	for(int i=n/2+1;i<=n;i++) printf("%d%c",i,i<n?' ':'\n');
	return 0;
}

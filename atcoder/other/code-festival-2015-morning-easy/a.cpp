#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	for(int i=1;;i++) if(i*i>=n) {
		printf("%d\n",i*i-n);
		break;
	}
	return 0;
}

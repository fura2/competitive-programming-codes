#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	n--;
	printf("%d\n",n%40<20?n%20+1:20-n%20);
	return 0;
}

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int sum; scanf("%d",&sum);
	rep(i,9){
		int a; scanf("%d",&a);
		sum-=a;
	}
	printf("%d\n",sum);
	return 0;
}

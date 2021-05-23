#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	int even=0;
	rep(i,n){
		int x; scanf("%d",&x);
		if(x%2==0) even++;
	}
	int odd=n-even;
	printf("%d\n",abs(even-odd));
	return 0;
}

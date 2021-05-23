#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	lint sum=0;
	vector<int> c(n);
	rep(i,n){
		int a,b; scanf("%d%d",&a,&b);
		sum+=b;
		c[i]=a+b;
	}

	sort(c.begin(),c.end());

	rep(i,n){
		sum-=c[i];
		if(sum<0){
			printf("%d\n",i);
			return 0;
		}
	}
	printf("%d\n",n);

	return 0;
}

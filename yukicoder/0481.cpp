#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	bool f[11]={};
	rep(i,9){
		int a; scanf("%d",&a);
		f[a]=true;
	}

	rep(a,10) if(!f[a+1]) printf("%d\n",a+1);

	return 0;
}

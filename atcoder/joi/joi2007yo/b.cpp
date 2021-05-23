#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	bool f[30]={};
	rep(i,28){
		int a; scanf("%d",&a); a--;
		f[a]=true;
	}
	rep(a,30) if(!f[a]) printf("%d\n",a+1);
	return 0;
}

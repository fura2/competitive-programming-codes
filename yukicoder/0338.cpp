#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b; scanf("%d%d",&a,&b);
	for(int k=1;;k++){
		bool ok=false;
		rep(i,k+1){
			if(int(100.0*i/k+0.5)==a && int(100.0*(k-i)/k+0.5)==b){
				ok=true;
				break;
			}
		}
		if(ok){
			printf("%d\n",k);
			break;
		}
	}
	return 0;
}

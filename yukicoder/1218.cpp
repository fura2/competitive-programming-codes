#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,z; scanf("%d%d",&n,&z);

	if(n>=3){
		puts("No");
	}
	else if(n==1){
		puts(z>=2?"Yes":"No");
	}
	else{
		bool ok=false;
		for(int x=1;x<=1000;x++) for(int y=1;y<=1000;y++) {
			if(x*x+y*y==z*z) ok=true;
		}
		puts(ok?"Yes":"No");
	}

	return 0;
}

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int t,a,b,c,d; cin>>t>>a>>b>>c>>d;

	if(a+c<=t){
		printf("%d\n",b+d);
	}
	else if(c<=t){
		printf("%d\n",d);
	}
	else if(a<=t){
		printf("%d\n",b);
	}
	else{
		puts("0");
	}

	return 0;
}

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c; scanf("%d%d%d",&a,&b,&c);
	int sum=0;
	for(int i=1;;i++){
		sum+=a;
		if(i%7==0) sum+=b;
		if(sum>=c){
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}

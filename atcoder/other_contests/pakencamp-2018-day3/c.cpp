#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int b; scanf("%d",&b);

	int ans=0;
	for(int a=2;a<b;a++){
		int x=a;
		while(x<b) x=x*3/2;
		if(x==b) ans++;
	}
	printf("%d\n",ans);

	return 0;
}

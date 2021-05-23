#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int ans=0;
	for(int i=1;i<=100;i++){
		if(i%3!=0 && i%5!=0) ans+=i;
	}
	printf("%d\n",ans);
	return 0;
}

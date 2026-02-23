#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int ans[20]={};
	rep(i,200){
		if(i/20%2==0){
			ans[i%20]+=i+1;
		}
		else{
			ans[19-i%20]+=i+1;
		}
	}

	int t; scanf("%d",&t); t--;
	printf("%d\n",ans[t]);

	return 0;
}

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b; scanf("%d%d",&a,&b);

	int ans=-1;
	while(a!=0){
		if(a<b){
			swap(a,b);
			ans++;
		}
		else{
			ans+=a/b;
			a-=a/b*b;
		}
	}
	printf("%d\n",ans);

	return 0;
}

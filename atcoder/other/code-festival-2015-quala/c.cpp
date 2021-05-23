#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,T; scanf("%d%d",&n,&T);

	vector<int> d(n);
	int sum=0;
	rep(i,n){
		int a,b; scanf("%d%d",&a,&b);
		d[i]=a-b;
		sum+=b;
	}

	sort(d.begin(),d.end());

	if(sum>T){
		puts("-1");
		return 0;
	}

	int ans=0;
	rep(i,n){
		if(sum+d[i]>T){
			ans=n-i;
			break;
		}
		sum+=d[i];
	}
	printf("%d\n",ans);

	return 0;
}

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	while(1){
		int n,k; scanf("%d%d",&n,&k);
		if(n==0 && k==0) break;
		vector<int> a(n);
		rep(i,n) scanf("%d",&a[i]);
		sort(a.begin(),a.end());
		printf("%d\n",accumulate(a.begin(),a.begin()+k,0));
	}
	return 0;
}

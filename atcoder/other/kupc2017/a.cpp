#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	sort(a.rbegin(),a.rend());

	int sum=0;
	rep(i,n){
		sum+=a[i];
		if(sum>=k){
			printf("%d\n",i+1);
			return 0;
		}
	}
	puts("-1");

	return 0;
}

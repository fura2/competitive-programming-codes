#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	sort(a.begin(),a.end());

	int ans=0,sum=0;
	rep(i,n){
		if(sum<a[i]){
			ans++;
			sum+=a[i];
		}
	}
	printf("%d\n",ans);

	return 0;
}

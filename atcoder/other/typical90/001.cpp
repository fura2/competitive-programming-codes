#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,l,k; scanf("%d%d%d",&n,&l,&k);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int lo=0,hi=l;
	while(hi-lo>1){
		int mi=(lo+hi)/2;

		int cnt=0,pre=0;
		rep(i,n){
			if(a[i]-pre>=mi && cnt<k){
				cnt++;
				pre=a[i];
			}
		}
		if(cnt==k && l-pre>=mi) lo=mi; else hi=mi;
	}
	printf("%d\n",lo);

	return 0;
}

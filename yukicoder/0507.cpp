#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	sort(a.begin()+1,a.end());
	int lo=0,hi=n;
	while(hi-lo>1){
		int mi=(lo+hi)/2;
		int a_mi=a[mi],sum=a[0]+a_mi;

		a.erase(a.begin()+mi);

		int cnt=0;
		for(int i=1,j=n-2;;i++,j--){
			while(i<j && a[i]+a[j]<=sum) i++;
			if(i>=j) break;
			cnt++;
		}
		if(cnt<m) hi=mi;
		else      lo=mi;

		a.insert(a.begin()+mi,a_mi);
	}
	printf("%d\n",hi==n?-1:a[hi]);

	return 0;
}

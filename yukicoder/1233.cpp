#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int amax=*max_element(a.begin(),a.end());

	vector<lint> freq(amax+1);
	rep(i,n) freq[a[i]]++;

	vector<lint> sum1(amax+1),sum2(amax+1);
	for(int x=1;x<=amax;x++){
		sum1[x]=sum1[x-1]+freq[x];
		sum2[x]=sum2[x-1]+x*freq[x];
	}

	lint ans=0;
	for(int y=1;y<=amax;y++) if(freq[y]>0) {
		for(int q=0;q*y<=amax;q++){
			int l=q*y,r=min((q+1)*y-1,amax);
			ans+=((sum2[r]-sum2[l])-q*y*(sum1[r]-sum1[l]))*freq[y];
		}
	}
	printf("%lld\n",ans);

	return 0;
}

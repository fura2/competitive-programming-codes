#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int sum=accumulate(a.begin(),a.end(),0);

	for(int i=min(sum,n);i>0;i--) if(sum%i==0) {
		int tar=sum/i;
		bool ok=true;
		int tmp=0;
		rep(j,n){
			tmp+=a[j];
			if(tmp>tar){ ok=false; break; }
			if(tmp==tar) tmp=0;
		}
		if(tmp!=0) ok=false;
		if(ok){
			printf("%d\n",i);
			break;
		}
	}

	return 0;
}

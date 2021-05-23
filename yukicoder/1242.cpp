#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int k; scanf("%*lld%d",&k);
	vector<lint> a(k);
	rep(i,k) scanf("%lld",&a[i]), a[i]--;

	rep(i,k) if(a[i]>=100) for(int j=i+1;j<k;j++) {
		lint d=a[j]-a[i];
		if(d==1 || d==3 || d==5){
			puts("No");
			return 0;
		}
	}

	bool ng[200]={};
	rep(i,k) if(a[i]<200) ng[a[i]]=true;
	for(int x=190;x>=0;x--) if(!ng[x]) {
		if(ng[x+1] && ng[x+6]) ng[x]=true;
		if(ng[x+2] && ng[x+5]) ng[x]=true;
		if(ng[x+3] && ng[x+4]) ng[x]=true;
	}
	puts(!ng[0]?"Yes":"No");

	return 0;
}

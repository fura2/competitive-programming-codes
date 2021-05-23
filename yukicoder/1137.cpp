#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	vector<int> cum(800001);
	rep(i,n){
		int x,r; scanf("%d%d",&x,&r);
		cum[400000+2*(x-r)+1]++;
		cum[400000+2*(x+r)]--;
	}
	rep(x,800000) cum[x+1]+=cum[x];

	printf("%d\n",*max_element(cum.begin(),cum.end()));

	return 0;
}

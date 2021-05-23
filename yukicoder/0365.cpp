#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]), a[i]--;

	vector<int> pos(n);
	rep(i,n) pos[a[i]]=i;

	int x;
	for(x=n-1;x>0;x--) if(pos[x-1]>pos[x]) break;
	printf("%d\n",x);

	return 0;
}

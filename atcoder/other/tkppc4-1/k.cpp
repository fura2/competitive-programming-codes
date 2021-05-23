#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	priority_queue<pair<int,int>> Q;
	Q.emplace(a[n-1],n-1);

	int ans=0,pos=n-1;
	while(pos>=0){
		int i=Q.top().second; Q.pop();
		ans++;
		rep(j,a[i]){
			pos--;
			if(pos<0) break;
			Q.emplace(a[pos],pos);
		}
	}
	printf("%d\n",ans);

	return 0;
}

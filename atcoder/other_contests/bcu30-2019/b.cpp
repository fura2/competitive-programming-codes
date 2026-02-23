#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	while(!a.empty() && a.back()==0) a.pop_back();
	n=a.size();

	if(n==0){
		puts("0");
		return 0;
	}

	int ans=1;
	rep(i,n-1) if(a[i]>a[i+1]) ans++;
	printf("%d\n",ans);

	return 0;
}

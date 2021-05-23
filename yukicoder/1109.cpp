#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<int> ans;
	rep(d,12){
		bool ok=true;
		rep(i,n) if(a[i]!=d && a[i]!=(d+2)%12 && a[i]!=(d+4)%12 && a[i]!=(d+5)%12 && a[i]!=(d+7)%12 && a[i]!=(d+9)%12 && a[i]!=(d+11)%12) ok=false;
		if(ok) ans.emplace_back(d);
	}

	printf("%d\n",ans.size()==1?ans[0]:-1);

	return 0;
}

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	vector<int> ans;
	for(int i=1;i<100;i++){
		int sum=0;
		for(int j=1;j<=i;j++) if(i%j==0) sum+=j;
		if(sum==98) ans.emplace_back(i);
	}
	rep(i,ans.size()) printf("%d%c",ans[i],i+1<ans.size()?' ':'\n');
	return 0;
}

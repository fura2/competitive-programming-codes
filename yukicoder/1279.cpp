#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d",&a[i]);
	rep(i,n) scanf("%d",&b[i]);

	int mx=-1,ans=0;
	vector<int> p(n);
	iota(p.begin(),p.end(),0);
	do{
		int tmp=0;
		rep(i,n) tmp+=max(a[p[i]]-b[i],0);
		if(mx<tmp){
			mx=tmp;
			ans=1;
		}
		else if(mx==tmp){
			ans++;
		}
	}while(next_permutation(p.begin(),p.end()));

	printf("%d\n",ans);

	return 0;
}

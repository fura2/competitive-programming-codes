#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(m),b(m),score(m);
	rep(i,m) scanf("%d%d%d",&a[i],&b[i],&score[i]);

	int ans=0;
	vector<int> p(n);
	iota(p.begin(),p.end(),0);
	do{
		int tmp=0;
		rep(i,m){
			int x=find(p.begin(),p.end(),a[i])-p.begin();
			int y=find(p.begin(),p.end(),b[i])-p.begin();
			if(x<y) tmp+=score[i];
		}
		ans=max(ans,tmp);
	}while(next_permutation(p.begin(),p.end()));
	printf("%d\n",ans);

	return 0;
}

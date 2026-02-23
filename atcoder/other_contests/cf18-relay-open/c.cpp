#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,h; scanf("%d%d",&n,&h);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int ans=0;
	vector<int> p(n);
	iota(p.begin(),p.end(),0);
	do{
		bool ok=true,b[10]={};
		for(int i:p){
			int y=0;
			rep(j,i+1) if(!b[j]) y+=a[j];
			if(y<=h) b[i]=true;
			else     ok=false;
		}
		if(ok) ans++;
	}while(next_permutation(p.begin(),p.end()));

	printf("%d\n",ans);

	return 0;
}

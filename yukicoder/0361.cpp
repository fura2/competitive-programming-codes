#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,d; scanf("%d%d",&n,&d);

	vector<int> grundy(n+1);
	for(int l=1;l<=n;l++){
		vector<bool> vis(n);
		for(int i=1;i<l;i++){
			for(int j=i+1;j<l;j++){
				int k=l-i-j;
				if(j>=k) break;
				if(k-i<=d){
					vis[grundy[i]^grundy[j]^grundy[k]]=true;
				}
			}
		}
		rep(x,n) if(!vis[x]) {
			grundy[l]=x;
			break;
		}
	}
	puts(grundy[n]>0?"kado":"matsu");

	return 0;
}

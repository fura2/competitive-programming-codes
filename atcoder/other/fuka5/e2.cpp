#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	while(1){
		int n; scanf("%d",&n);
		if(n==0) break;
		vector<int> a(n);
		rep(i,n) scanf("%d",&a[i]);

		vector<int> nxt(n);
		for(int x=n-1;x>=0;x--){
			if     (a[x]==-1) nxt[x]=0;
			else if(a[x]== 0) nxt[x]=x;
			else              nxt[x]=nxt[min(x+a[x],n-1)];
		}

		vector<double> c1(n),c2(n); // E[i] = c1[i] + c2[i] * E[0]
		for(int x=n-2;x>=0;x--){
			c1[x]=1;
			for(int d=1;d<=6;d++){
				int x2=nxt[min(x+d,n-1)];
				if(x2==0){
					c2[x]+=1.0/6;
				}
				else{
					c1[x]+=c1[x2]/6;
					c2[x]+=c2[x2]/6;
				}
			}
		}
		printf("%.9f\n",c1[0]/(1-c2[0]));
	}

	return 0;
}

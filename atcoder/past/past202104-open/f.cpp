#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,l,t,x; scanf("%d%d%d%d",&n,&l,&t,&x);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d%d",&a[i],&b[i]);

	rep(i,n){
		if(a[i]>t && b[i]>=l){
			puts("forever");
			return 0;
		}
	}

	int ans=0,cons=0;
	rep(i,n){
		if(b[i]<l){
			ans+=a[i];
			cons=0;
		}
		else{
			if(cons+a[i]>t){
				ans+=t-cons+x;
				cons=0;
				i--;
			}
			else if(cons+a[i]==t){
				ans+=t-cons+x;
				cons=0;
			}
			else{
				ans+=a[i];
				cons+=a[i];
			}
		}
	}
	printf("%d\n",ans);

	return 0;
}

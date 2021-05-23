#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	string s; cin>>s;
	int n=s.length();

	int ans=INF;
	rep(i,n) for(int j=i+1;j<=n;j++) {
		int stage=0;
		for(int x=i;x<j;x++){
			if     (stage==0 && s[x]=='c') stage++;
			else if(stage==1 && s[x]=='w') stage++;
			else if(stage==2 && s[x]=='w') stage++;
		}
		if(stage==3) ans=min(ans,j-i);
	}
	printf("%d\n",ans<INF?ans:-1);

	return 0;
}

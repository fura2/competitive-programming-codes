#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int D[]={0,31,29,31,30,31,30,31,31,30,31,30,31};

	bool h[13][32]={};
	int w=0;
	for(int m=1;m<=12;m++) for(int d=1;d<=D[m];d++) {
		h[m][d]=(w==0||w==6);
		w=(w+1)%7;
	}

	int n; scanf("%d",&n);
	rep(_,n){
		int m,d; scanf("%d/%d",&m,&d);
		while(m<=12 && h[m][d]){
			d++;
			if(d>D[m]) d=1, m++;
		}
		if(m<=12) h[m][d]=true;
	}

	int ans=0,cnt=0;
	for(int m=1;m<=12;m++) for(int d=1;d<=D[m];d++) {
		if(h[m][d]){
			cnt++;
			ans=max(ans,cnt);
		}
		else cnt=0;
	}
	printf("%d\n",ans);

	return 0;
}

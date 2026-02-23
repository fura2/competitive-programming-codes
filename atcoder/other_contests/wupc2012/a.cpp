#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int day[]={0,31,29,31,30,31,30,31,31,30,31,30,31};

	int m1,d1,m2,d2; scanf("%d%d%d%d",&m1,&d1,&m2,&d2);

	int ans=0;
	while(m1!=m2 || d1!=d2){
		if(d1==day[m1]) d1=1, m1++;
		else            d1++;
		ans++;
	}
	printf("%d\n",ans);

	return 0;
}

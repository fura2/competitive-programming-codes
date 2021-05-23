#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int p,q,a; scanf("%d%d%d",&p,&q,&a);

	if(p==q){
		printf("%d\n",a==0?0:int(1e9));
	}
	else if(p>q){
/*
	floor(p * x / 100) < floor(q * x / 100) + a
	<=
	p * x / 100 < q * x / 100 + a - 1
	<=>
	x < (a - 1) * 100 / (p - q)

	floor(p * x / 100) >= floor(q * x / 100) + a
	<=
	p * x / 100 >= q * x / 100 + a + 1
	<=>
	x >= (a + 1) * 100 / (p - q)
*/
		int lb=(a-1)*100/(p-q); if(lb<1) lb=1;
		int ub=(a+1)*100/(p-q);

		int ans=lb-1;
		for(int x=lb;x<ub;x++) if(p*x/100<q*x/100+a) ans++;
		printf("%d\n",ans);
	}
	else{ // p<q
		if(a>0){
			printf("%d\n",int(1e9));
		}
		else{
/*
	floor(p * x / 100) < floor(q * x / 100)
	<=
	p * x / 100 < q * x / 100 - 1
	<=>
	x > 100 / (q - p)
*/
			int ans=1e9-100/(q-p);
			for(int x=1;x<=100/(q-p);x++) if(p*x/100<q*x/100) ans++;
			printf("%d\n",ans);
		}
	}

	return 0;
}

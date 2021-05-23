#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

tuple<int,int,int> ask(vector<int> dice){
	rep(i,6) printf("%d%c",dice[i],i<5?' ':'\n');
	fflush(stdout);
	int d,v,x; scanf("%d%d%d",&d,&v,&x);
	return {d,v,x};
}

int main(){
	int n,m; scanf("%d%d",&n,&m);

	vector<int> B(n+1,-1);
	B[0]=B[n-5]=B[n-4]=B[n-3]=B[n-2]=B[n-1]=0;
	B[n]=5000;

	int x;
	vector<int> dice={1,2,3,4,5,6};
	rep(t,4){
		int d,v;
		tie(d,v,x)=ask(dice);

		B[x]=v;

		if(t==0) dice[1]=6; // 2 -> 6
		if(t==1) dice[2]=6; // 3 -> 6
		if(t==2) dice[3]=6; // 4 -> 6
		if(t==3) dice[4]=6; // 5 -> 6
	}
	rep(t,m-4){
		int d,v;
		tie(d,v,x)=ask(dice);

		B[x]=v;

		if((500-x)%6==0) dice[0]=6; // 1 -> 6
		else             dice[0]=1; // 1 -> 1
	}

	return 0;
}

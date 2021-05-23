#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int r,g,b; cin>>r>>g>>b;
	int lo=0,hi=1e7+1;
	while(hi-lo>1){
		int mi=(lo+hi)/2;
		int d=0;
		if(r>=mi) d+=(r-mi)/2;
		else      d-=mi-r;
		if(g>=mi) d+=(g-mi)/2;
		else      d-=mi-g;
		if(b>=mi) d+=(b-mi)/2;
		else      d-=mi-b;
		if(d>=0) lo=mi;
		else     hi=mi;
	}
	printf("%d\n",lo);
	return 0;
}

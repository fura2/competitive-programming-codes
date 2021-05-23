#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int y,m,d; scanf("%d%d%d",&y,&m,&d);
	puts(make_tuple(1989,1,8)<=make_tuple(y,m,d) && make_tuple(y,m,d)<=make_tuple(2019,4,30)?"Yes":"No");
	return 0;
}

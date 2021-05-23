#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

bool is_prime(long long a){
	if(a%2==0) return a==2;
	for(long long i=3;i*i<=a;i+=2) if(a%i==0) return false;
	return a!=1;
}

int main(){
	int x,y; scanf("%d%d",&y,&x);

	if(x==2 || y==2) return puts("Second"),0;

	bool bx=is_prime(x),by=is_prime(y);
	if(bx && by) return puts("Second"),0;

	int cnt=0;
	if(bx) cnt++, x++;
	if(by) cnt++, y++;
	while(!is_prime(x)) cnt++, x++;
	while(!is_prime(y)) cnt++, y++;
	puts(cnt%2==1?"First":"Second");

	return 0;
}

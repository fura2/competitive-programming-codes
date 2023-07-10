#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	char a,b; scanf("%c %c",&a,&b);
	printf("%c\n",a=='Y'?toupper(b):b);
	return 0;
}

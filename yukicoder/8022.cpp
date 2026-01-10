#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; scanf("%d",&n);
	for(int i='b'-'a';i<=n;i++){
		if(!(i%('p'-'a'))) puts("FizzBuzz");
		else if(!(i%('d'-'a'))) puts("Fizz");
		else if(!(i%('f'-'a'))) puts("Buzz");
		else printf("%d\n",i);
	}
	return NULL;
}

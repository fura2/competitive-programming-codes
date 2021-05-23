#include <cstdio>

using namespace std;

int main(){
	int n; scanf("%d",&n);
	bool ok=true;
	if(n=='B'%'A') ok=false;
	for(int i='C'%'A';i<n;){
		if(!(n%i)) ok=false;
		int m=true;
		while(i&m){ i=i^m; m<<=true; }
		i=i^m;
	}
	puts(ok?"YES":"NO");
}

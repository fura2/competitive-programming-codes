#include <cstdio>

using namespace std;

int main(){
	bool pre=false;
	while(1){
		int c=getchar();
		if(c==' '){
			if(!pre) putchar(',');
			pre=true;
		}
		else{
			putchar(c);
			pre=false;
		}
		if(c=='\n') break;
	}

	return 0;
}

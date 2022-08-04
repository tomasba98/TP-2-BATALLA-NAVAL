#include <iostream>
#include <stdlib.h>
#include<time.h>
using namespace std;

int main(int argc, char *argv[]) {
	
	srand(time(NULL));
	
	int posMovimiento = rand()%9+1;
	
	for(int i=0;i<20;i++){
		posMovimiento = rand()%9+1;
		cout<<posMovimiento<<endl;
	}
	
	
	
	return 0;
}


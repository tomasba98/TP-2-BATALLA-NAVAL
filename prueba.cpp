#include <iostream>
#include <stdlib.h>
#include<time.h>
using namespace std;

int main(int argc, char *argv[]) {
	
	srand(time(NULL));
	
	int posMovimiento = rand()%(4);
	
	cout<<posMovimiento;
	
	return 0;
}


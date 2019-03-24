#include "rand.h"
#include "mat.h"


int main(int argc, char *argv[]){

	if(argc != 2){
		printf("Please enter K on the command line and nothing else\n");
		return 1;
	}

	printf("K = %d!\n", atoi(argv[1]));


	return 0;
}

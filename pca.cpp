#include "rand.h"
#include "mat.h"
#include <math.h>


int main(int argc, char *argv[]){

	if(argc != 2){
		printf("Please enter K on the command line and nothing else\n");
		return 1;
	}

	int K = atoi(argv[1]);

	//Read in matrix of image
	Matrix mIn("Raw Image Data");
	bool mInColor;
	mIn.readImagePixmap("", "mIn", mInColor);

	//If K is negative transpose input and set flag to undo at the end
	bool transposed = false;
	if( K > 0 ){
		mIn.transposeSelf();
		K = abs(K);
		transposed = true;
	}

	//TODO:Use Z-score/stdev to normalize?
	//Mean Normalization of input matrix
	double mInMean = mIn.mean();
	mIn.scalarPostSub(mInMean);

	//compute covariance Matrix
	Matrix mCov = mIn.cov();





	//Untranspose output before finishing if transposed flag is set

	return 0;
}

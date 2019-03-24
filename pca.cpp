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

	//produce eigenvectors and values from mCov
	Matrix mEigVals = mCov.eigenSystem();

	mCov.printSize();
	mEigVals.print();

	//cut down eighenvectors matrix based on K
	Matrix mCovCut = mCov.extract(0,0,K,0);		//TODO:Ensure I didn't do this sideways
	Matrix mEigValsCut = mEigVals.extract(0,0,0,K);

	mCovCut.printSize();
	mEigValsCut.print();

	//produce mX from Normalized mIn and cut down mCov
	Matrix mX = mIn.dotT(mCovCut);

	mX.printSize();
	mIn.printSize();





	//Untranspose output before finishing if transposed flag is set

	return 0;
}

#include <Rcpp.h>

using namespace Rcpp;


//' @title NotNull returns the amount of not zwero entries in the matrix/vector
//' @aliases NotNull,Dense2SparseHDF5-method
//' @rdname NotNull
//' @description count the not zeros in a dense matrix
//' @param X a dense vector
//' @return the amount of not zero entries
//' @export
// [[Rcpp::export]]
int NotNull( NumericMatrix X ) {
	int ret = 0;
	for (int c=0; c < X.ncol(); c++ ){
		for (int r=0; r < X.nrow(); r++ ){
			if ( X(r,c) != 0 )
				ret++;
		}
	}
	return ( ret );
}


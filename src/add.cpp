#include <Rcpp.h>
#include <RcppEigen.h>
#include <progress.hpp>

using namespace Rcpp;


//' @title add runs wilcox test on the columns of the sparse matrix
//' @aliases add,Dense2SparseHDF5-method
//' @rdname add
//' @description count the not zeros in a dense matrix
//' @param X the sparse matrix 
//' @param dat the dense matrix
//' @param alloc the amount of data that has to fit into the object
//' @return null
//' @export
// [[Rcpp::export]]
Eigen::SparseMatrix<double> add( Eigen::SparseMatrix<double> X, NumericMatrix dat, int offset, int alloc ) {
	

	Rcout << "allocating " << alloc << " free data slots" << std::endl;

	X.reserve( alloc );

	Progress p(dat.ncol(), true);

	for (int c=0; c < dat.ncol(); c++ ){
		p.increment();
		for (int r=0; r < dat.nrow(); r++ ){
			if ( dat(r,c) != 0 ){
				X.insert( r, c+offset ) = dat( r,c);
			}
		}
	}
	return (X);
}
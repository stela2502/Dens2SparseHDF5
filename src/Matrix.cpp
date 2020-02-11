#include <Rcpp.h>
#include <RcppEigen.h>

using namespace Rcpp;


//' @title Matr will create an R saprse matrix resized to the correct number of entries, but not filled
//' @aliases Matr,Dense2SparseHDF5-method
//' @rdname Matr
//' @description count the not zeros in a dense matrix
//' @param nrow row count
//' @param ncol col count
//' @param size the amount of not zero entries 
//' @return the propper resized dense matrix (hopefully)
//' @export
// [[Rcpp::export]]
Eigen::SparseMatrix<double> Matr( int nrow, int ncol, int size ) {
	Eigen::SparseMatrix<double> ret(nrow,ncol);
	ret.reserve( size );
	return (ret);
}
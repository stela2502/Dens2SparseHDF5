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
	

	Rcout << "allocating " << alloc << " free data slots" << " size was: " << X.size() << std::endl;

	X.reserve( alloc );

	Rcout << "setting size to " << X.size() << std::endl;

	Progress p(dat.ncol(), true);
	int colA;
	for (int c=0; c < dat.ncol(); c++ ){
		p.increment();
		colA = c+offset;
		for (int r=0; r < dat.nrow(); r++ ){
			if ( dat(r,c) != 0 ){
				X.insert( r, colA ) = dat( r,c);
			}
		}
	}
	return (X);
}


//' @title addVector runs wilcox test on the columns of the sparse matrix
//' @aliases addVector,Dense2SparseHDF5-method
//' @rdname addVector
//' @description count the not zeros in a dense matrix
//' @param dat the dense matrix
//' @param alloc the amount of data that has to fit into the object
//' @return null
//' @export
// [[Rcpp::export]]
NumericMatrix addVector( NumericMatrix dat, int offset, int alloc ) {

	NumericMatrix X (alloc, 3 );

	Progress p(dat.ncol(), true);

	int colA;
	int id = 0;
	for (int c=0; c < dat.ncol(); c++ ){
		p.increment();
		colA = c+offset;
		for (int r=0; r < dat.nrow(); r++ ){
			if ( dat(r,c) != 0 ){
				X(id,0) = r;
				X(id,1) = colA;
				X(id,2) = dat( r,c);
				id ++;
				//X.insert( r, colA ) = dat( r,c);
			}
		}
	}
	return (X);
}

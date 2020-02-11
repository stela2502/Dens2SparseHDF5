#include <Rcpp.h>
#include <RcppEigen.h>

using namespace Rcpp;

class GrowingSparse {
public:

	GrowingSparse ( ) {

		mat = Eigen::SparseMatrix<double> (1,1);
		size = 1;
		ncol = 0;
		nrow = 0;

	};
	GrowingSparse ( Eigen::SparseMatrix<double> Mat, int Size, int Ncol, int Nrow) {

		mat = Mat;
		size = Size;
		ncol = Ncol;
		nrow = Nrow;
	};
	void add ( NumericMatrix X ) {
		// identify the not 0 values and add them to the GROWN matrix
		int total = 0;
		for ( int r = 0; r < X.nrow(); r ++ ) {
			for ( int c=0; c < X.ncol(); c++ ) {
				if ( X(r,c) > 0 )
					total ++;
			}
		}
		mat.reserve( size + total ); //resize
		for ( int r = 0; r < X.nrow(); r ++ ) {
			for ( int c=0; c < X.ncol(); c++ ) {
				if ( X(r,c) > 0 )
					mat.insert(c,r) = X(r,c);
			}
		}

	};
	Eigen::SparseMatrix<double> getMatrix() {
		return (mat);
	};

private:
	Eigen::SparseMatrix<double> mat;

	int size;
	int ncol;
	int nrow;

};	


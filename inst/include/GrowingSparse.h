

#include <Rcpp.h>
#include <RcppEigen.h>

#include <RcppCommon.h>

RCPP_EXPOSED_CLASS(GrowingSparse)

using namespace Rcpp;


class GrowingSparse {
public:

	int colA;
	int size;
	int ncol;
	int nrow;

	GrowingSparse ( int Nrow, int Ncol, int Size ) {

		mat = Eigen::SparseMatrix<double> (Nrow,Ncol);
		mat.reserve( Size );
		size = Size;
		ncol = Ncol;
		nrow = Nrow;
		colA=0;

	};

	void resize2( int size){
		mat.reserve( size );
	};
	void add ( NumericMatrix X ) {
		// identify the not 0 values and add them to the GROWN matrix
		for ( int c=0; c < X.ncol(); c++ ) {
			for ( int r = 0; r < X.nrow(); r ++ ) {
				if ( X(r,c) > 0 )
					mat.insert(r, colA) = X(r,c);
			}
			colA ++;
		}

	};
	Eigen::SparseMatrix<double> getMatrix() {
		return (mat);
	};

private:
	Eigen::SparseMatrix<double> mat;



};	


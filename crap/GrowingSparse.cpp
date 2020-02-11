#include <Rcpp.h>
using namespace Rcpp;
#include <RcppEigen.h>
#include <GrowingSparse.h>

RCPP_MODULE(GrowingSparse) {
	class_<GrowingSparse>( "GrowingSparse" )

	.constructor<Eigen::SparseMatrix<double>,  int, int, int>()

	// .field_readonly( "size", &GrowingSparse::size )
	// .field_readonly( "ncol", &GrowingSparse::ncol )

	.method( "add", &GrowingSparse::add )
	.method( "getMatrix", &GrowingSparse::getMatrix )
	;
}


//' @title create a new R object being a growing sparse matrix
//' @aliases new,Dense2SparseHDF5-method
//' @rdname new
//' @description create a new GroingsSparse c++ object in R
//' @return GrowingSparse c++ object
//' @export
// [[Rcpp::export]]
RcppExport SEXP GrowingSparse__new(){
	// create pointer to an GrowingSparse object and
	// wrap it as an external pointer
	Rcpp::XPtr<GrowingSparse>
	ptr( new GrowingSparse(  ), true );
	// return the external pointer to the R side
	return ptr;
}

//' @title create a new R object being a growung sparse matrix
//' @aliases GrowingSparse,Dense2SparseHDF5-method
//' @rdname GrowingSparse
//' @description create a new GroingsSparse c++ object in R
//' @return GrowingSparse c++ object
//' @export
// [[Rcpp::export]]
RcppExport SEXP GrowingSparse__GrowingSparse(){
	// create pointer to an GrowingSparse object and
	// wrap it as an external pointer
	Rcpp::XPtr<GrowingSparse>
	ptr( new GrowingSparse(  ), true );
	// return the external pointer to the R side
	return ptr;
}

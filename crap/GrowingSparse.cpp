#include <GrowingSparse.h>

void printGR (GrowingSparse gr){
/*	cat("containing a sparse matrix of size")
	if( ! is.null(self$Matrix) ){
		cat( paste( nrow(self$Matrix),'rows and', ncol(self$Matrix), "cols"))
	}else {
		cat ("0" )
	}*/
	Rcout << "containing a sparse matrix of size " << gr.nrow << " X " << gr.ncol << " with " << gr.size << " data slots" << std::endl;
	Rcout << "At the moment " << gr.colA << " columns have been filled" << std::endl;
}

RCPP_MODULE(GrSparse) {
	Rcpp::class_<GrowingSparse>("GrSparse") 

		.constructor<int,int,int>("constructor with nrow, ncol and (total) size")

		.method("resize2",         &GrowingSparse::resize2,            "reserve size many entries to be stored in the object")
		.method("add",             &GrowingSparse::add,                "add a normal matrix slice to the object")
		.method("getMatrix",       &GrowingSparse::getMatrix,          "return the sparse matrix object from within the object")
	;

	Rcpp::function( "print",            &printGR ) ; 
}

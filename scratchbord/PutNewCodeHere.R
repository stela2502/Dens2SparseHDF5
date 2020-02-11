ToSparse <- function( fname, block_size = 1000 ) {
	
	x= hdf5r::h5file(fname)

	cols_grouped <- split(1:x[['matrix']]$dims[2],  (1:x[['matrix']]$dims[2]-1) %/% block_size)

	n = sum( unlist(lapply( cols_grouped, function(cs) { NotNull( x[['matrix']][, cs ]) } )))

	

}
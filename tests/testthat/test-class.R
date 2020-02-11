context('class')


m = matrix(rep(1,10000), ncol=100 )

expect_true( NotNull(m) == 10000 )

obj = Dense2SparseHDF5$new('useless')
obj$Matrix = Matr( 100, 100, 10000)

ret = add(obj$Matrix, m, 0 )

expect_true(all(Matrix::rowSums( m - ret) ==0))

obj = Dense2SparseHDF5$new('/mnt/VR_Project/Organogenesis/organo2.loom')

obj$toSparse()



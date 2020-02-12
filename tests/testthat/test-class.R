context('class')


m = matrix(rep(1,10000), ncol=100 )

expect_true( NotNull(m) == 10000 )

obj = Dense2SparseHDF5$new('useless')
obj$Matrix = Matr( 100, 100, 10000)

ret = add(obj$Matrix, m, 0, 10000 )

expect_true(all(Matrix::rowSums( m - ret) ==0))

#obj = Dense2SparseHDF5$new('/mnt/VR_Project/Organogenesis/organo2.loom')

#obj$toSparse()

if ( ! file.exists('/mnt/VR_Project/Organogenesis/organo2.loom')){
	skip("workload tests lack input loom files (developer machine specific)")
}
obj2 = Dense2SparseHDF5$new('/mnt/VR_Project/Organogenesis/organo2.loom')

obj2$toSparseVector()

mat = obj2$file[['matrix']][,]

all.equal( Matrix::Matrix( mat, sparse=T), obj2$Matrix )


skip("far too slow")

save( obj$Matrix, file="/mnt/VR_Project/Organogenesis/organo2.sparse.RData")

obj = Dense2SparseHDF5$new('~/NAS/MattiasMagnusson/Pavan_Prabhala/Hongzeh_merged/Pavan_Honhzhe_healthy_raw_merged.loom')

save( obj$Matrix, file="~/NAS/MattiasMagnusson/Pavan_Prabhala/Hongzeh_merged/Pavan_Honhzhe_healthy_raw_merged.sparse.RData")

# Dens2SparseHDF5

This R package is meant to easily convert a HDF5 dense matrix, which is found in several .loom files 
and can easily be too big for a normal analysis desktop (64Gb RAM), into a R sparse matrix.

The process in implemented in c++ using the Rcpp package, but needs further speed improvements.

# Install

```
install.packagaes('devtools')

devtools::install_git('https://github.com/stela2502/Dens2SparseHDF5.git')

//
// auto-generated by ops.py
//
#include "./MPI_inline/multidim_common.h"

int xdim0_multidim_kernel;
int ydim0_multidim_kernel;



#define OPS_ACC_MD0(d,x,y) (n_x*1 + n_y*xdim0_multidim_kernel*1 + (x)+(d)*xdim0_multidim_kernel*ydim0_multidim_kernel+(xdim0_multidim_kernel*(y)))
//user function



void multidim_kernel_c_wrapper(
  double * restrict val,
  int * restrict idx,
  int arg_idx0, int arg_idx1,
  int x_size, int y_size) {
  #pragma omp parallel for
  for ( int n_y=0; n_y<y_size; n_y++ ){
    for ( int n_x=0; n_x<x_size; n_x++ ){
      int idx[] = {arg_idx0+n_x, arg_idx1+n_y};
      
  val[OPS_ACC_MD0(0,0,0)] = (double)(idx[0]);
  val[OPS_ACC_MD0(1,0,0)] = (double)(idx[1]);
  printf("%d %d: %p %p\n",idx[0],idx[1],&val[OPS_ACC_MD0(0,0,0)],&val[OPS_ACC_MD0(1,0,0)]);

    }
  }
}

#undef OPS_ACC_MD0

//
<<<<<<< HEAD
<<<<<<< HEAD
// auto-generated by ops.py on 2014-07-31 11:59
=======
// auto-generated by ops.py on 2014-07-10 14:54
>>>>>>> 901c039... Initial setup, mostly working for single node
=======
// auto-generated by ops.py on 2014-07-11 14:02
>>>>>>> ac031df... Refactored single-block stuff, works
//

#include "./OpenACC/clover_leaf_common.h"

#define OPS_GPU

int xdim0_update_halo_kernel2_yvel_plus_2_b;
int xdim1_update_halo_kernel2_yvel_plus_2_b;

#define OPS_ACC0(x,y) (x+xdim0_update_halo_kernel2_yvel_plus_2_b*(y))
#define OPS_ACC1(x,y) (x+xdim1_update_halo_kernel2_yvel_plus_2_b*(y))

//user function

inline void update_halo_kernel2_yvel_plus_2_b(double *yvel0, double *yvel1, const int* fields) {
  if(fields[FIELD_YVEL0] == 1) yvel0[OPS_ACC0(0,0)] = yvel0[OPS_ACC0(-2,0)];
  if(fields[FIELD_YVEL1] == 1) yvel1[OPS_ACC1(0,0)] = yvel1[OPS_ACC1(-2,0)];
}



#undef OPS_ACC0
#undef OPS_ACC1


void update_halo_kernel2_yvel_plus_2_b_c_wrapper(
  double *p_a0,
  double *p_a1,
  int *p_a2,
  int x_size, int y_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2)
  #pragma acc loop
  #endif
  for ( int n_y=0; n_y<y_size; n_y++ ){
    #ifdef OPS_GPU
    #pragma acc loop
    #endif
    for ( int n_x=0; n_x<x_size; n_x++ ){
      update_halo_kernel2_yvel_plus_2_b(  p_a0 + n_x*1 + n_y*xdim0_update_halo_kernel2_yvel_plus_2_b*1,
           p_a1 + n_x*1 + n_y*xdim1_update_halo_kernel2_yvel_plus_2_b*1, p_a2 );

    }
  }
}

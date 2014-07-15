//
// auto-generated by ops.py on 2014-07-15 16:00
//


#pragma OPENCL EXTENSION cl_khr_fp64:enable

#include "user_types.h"
#include "ops_opencl_reduction.h"

#ifndef MIN
#define MIN(a,b) ((a<b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a,b) ((a>b) ? (a) : (b))
#endif
#ifndef SIGN
#define SIGN(a,b) ((b<0.0) ? (a*(-1)) : (a))
#endif
#define OPS_READ 0
#define OPS_WRITE 1
#define OPS_RW 2
#define OPS_INC 3
#define OPS_MIN 4
#define OPS_MAX 5
#define ZERO_double 0.0;
#define INFINITY_double INFINITY;
#define ZERO_float 0.0f;
#define INFINITY_float INFINITY;
#define ZERO_int 0;
#define INFINITY_int INFINITY;
#define ZERO_uint 0;
#define INFINITY_uint INFINITY;
#define ZERO_ll 0;
#define INFINITY_ll INFINITY;
#define ZERO_ull 0;
#define INFINITY_ull INFINITY;
#define ZERO_bool 0;
#define OPS_ACC0(x,y,z) (x+xdim0_flux_calc_kernely*(y)+xdim0_flux_calc_kernely*ydim0_flux_calc_kernely*(z))
#define OPS_ACC1(x,y,z) (x+xdim1_flux_calc_kernely*(y)+xdim1_flux_calc_kernely*ydim1_flux_calc_kernely*(z))
#define OPS_ACC2(x,y,z) (x+xdim2_flux_calc_kernely*(y)+xdim2_flux_calc_kernely*ydim2_flux_calc_kernely*(z))
#define OPS_ACC3(x,y,z) (x+xdim3_flux_calc_kernely*(y)+xdim3_flux_calc_kernely*ydim3_flux_calc_kernely*(z))


//user function
void flux_calc_kernely( __global double * restrict vol_flux_y, const __global double * restrict yarea, const __global double * restrict yvel0, 
const __global double * restrict yvel1, 
  const double dt)

  {

  vol_flux_y[OPS_ACC0(0,0,0)] = 0.125 * dt * (yarea[OPS_ACC1(0,0,0)]) *
  ( yvel0[OPS_ACC2(0,0,0)] + yvel0[OPS_ACC2(1,0,0)] + yvel0[OPS_ACC2(0,0,1)] + yvel0[OPS_ACC2(1,0,1)] +
    yvel1[OPS_ACC3(0,0,0)] + yvel1[OPS_ACC3(1,0,0)] + yvel1[OPS_ACC3(0,0,1)] + yvel1[OPS_ACC3(1,0,1)]);
}



 #undef OPS_ACC0
 #undef OPS_ACC1
 #undef OPS_ACC2
 #undef OPS_ACC3


 __kernel void ops_flux_calc_kernely(
 __global double* restrict arg0,
 __global const double* restrict arg1,
 __global const double* restrict arg2,
 __global const double* restrict arg3,
 __global const double * restrict dt,
 const int base0,
 const int base1,
 const int base2,
 const int base3,
 const int size0,
 const int size1,
 const int size2 ){


   int idx_z = get_global_id(2);
   int idx_y = get_global_id(1);
   int idx_x = get_global_id(0);

   if (idx_x < size0 && idx_y < size1 && idx_z < size2) {
     flux_calc_kernely(&arg0[base0 + idx_x * 1 + idx_y * 1 * xdim0_flux_calc_kernely+ idx_z * 1 * xdim0_flux_calc_kernely * ydim0_flux_calc_kernely],
                      &arg1[base1 + idx_x * 1 + idx_y * 1 * xdim1_flux_calc_kernely+ idx_z * 1 * xdim1_flux_calc_kernely * ydim1_flux_calc_kernely],
                      &arg2[base2 + idx_x * 1 + idx_y * 1 * xdim2_flux_calc_kernely+ idx_z * 1 * xdim2_flux_calc_kernely * ydim2_flux_calc_kernely],
                      &arg3[base3 + idx_x * 1 + idx_y * 1 * xdim3_flux_calc_kernely+ idx_z * 1 * xdim3_flux_calc_kernely * ydim3_flux_calc_kernely],
                      *dt);
   }

 }

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
#define OPS_ACC0(x,y,z) (x+xdim0_update_halo_kernel3_minus_4_b*(y)+xdim0_update_halo_kernel3_minus_4_b*ydim0_update_halo_kernel3_minus_4_b*(z))
#define OPS_ACC1(x,y,z) (x+xdim1_update_halo_kernel3_minus_4_b*(y)+xdim1_update_halo_kernel3_minus_4_b*ydim1_update_halo_kernel3_minus_4_b*(z))


//user function
inline void update_halo_kernel3_minus_4_b(__global double * restrict vol_flux_x, __global double * restrict mass_flux_x, const __global int* restrict  fields)

  {
  if(fields[FIELD_VOL_FLUX_X] == 1)  vol_flux_x[OPS_ACC0(0,0,0)]  = -(vol_flux_x[OPS_ACC0(-4,0,0)]);
  if(fields[FIELD_MASS_FLUX_X] == 1) mass_flux_x[OPS_ACC1(0,0,0)] = -(mass_flux_x[OPS_ACC1(-4,0,0)]);
}



 #undef OPS_ACC0
 #undef OPS_ACC1


 __kernel void ops_update_halo_kernel3_minus_4_b(
 __global double* restrict arg0,
 __global double* restrict arg1,
 __global const int* restrict arg2,
 const int base0,
 const int base1,
 const int size0,
 const int size1,
 const int size2 ){


   int idx_z = get_global_id(2);
   int idx_y = get_global_id(1);
   int idx_x = get_global_id(0);

   if (idx_x < size0 && idx_y < size1 && idx_z < size2) {
     update_halo_kernel3_minus_4_b(&arg0[base0 + idx_x * 1 + idx_y * 1 * xdim0_update_halo_kernel3_minus_4_b+ idx_z * 1 * xdim0_update_halo_kernel3_minus_4_b * ydim0_update_halo_kernel3_minus_4_b],
                        &arg1[base1 + idx_x * 1 + idx_y * 1 * xdim1_update_halo_kernel3_minus_4_b+ idx_z * 1 * xdim1_update_halo_kernel3_minus_4_b * ydim1_update_halo_kernel3_minus_4_b],
                        arg2);
   }

 }

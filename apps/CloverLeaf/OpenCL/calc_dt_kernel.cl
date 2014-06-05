//
// auto-generated by ops.py on 2014-06-02 16:13
//

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

#pragma OPENCL EXTENSION cl_khr_fp64:enable

#define OPS_ACC0(x,y) (x+xdim0_calc_dt_kernel*(y))
#define OPS_ACC1(x,y) (x+xdim1_calc_dt_kernel*(y))
#define OPS_ACC2(x,y) (x+xdim2_calc_dt_kernel*(y))
#define OPS_ACC3(x,y) (x+xdim3_calc_dt_kernel*(y))
#define OPS_ACC4(x,y) (x+xdim4_calc_dt_kernel*(y))
#define OPS_ACC5(x,y) (x+xdim5_calc_dt_kernel*(y))
#define OPS_ACC6(x,y) (x+xdim6_calc_dt_kernel*(y))
#define OPS_ACC7(x,y) (x+xdim7_calc_dt_kernel*(y))
#define OPS_ACC8(x,y) (x+xdim8_calc_dt_kernel*(y))
#define OPS_ACC9(x,y) (x+xdim9_calc_dt_kernel*(y))
#define OPS_ACC10(x,y) (x+xdim10_calc_dt_kernel*(y))


//user function
void calc_dt_kernel( __global double *celldx, __global double *celldy, __global double *soundspeed, __global double *viscosity, __global double *density0, __global double *xvel0, __global double *xarea, __global double *volume, __global double *yvel0, __global double *yarea, __global double *dt_min, 
  double g_small,
  double g_big,
  double dtc_safe,
  double dtu_safe,
  double dtv_safe,
  double dtdiv_safe,
  int xdim0_calc_dt_kernel,
int xdim1_calc_dt_kernel,
int xdim2_calc_dt_kernel,
int xdim3_calc_dt_kernel,
int xdim4_calc_dt_kernel,
int xdim5_calc_dt_kernel,
int xdim6_calc_dt_kernel,
int xdim7_calc_dt_kernel,
int xdim8_calc_dt_kernel,
int xdim9_calc_dt_kernel,
int xdim10_calc_dt_kernel)

  {

  double div, dsx, dsy, dtut, dtvt, dtct, dtdivt, cc, dv1, dv2, jk_control;

  dsx = celldx[OPS_ACC0(0,0)];
  dsy = celldy[OPS_ACC2(0,0)];

  cc = soundspeed[OPS_ACC2(0,0)] * soundspeed[OPS_ACC2(0,0)];
  cc = cc + 2.0 * viscosity[OPS_ACC3(0,0)]/density0[OPS_ACC4(0,0)];
  cc = MAX(sqrt(cc),g_small);

  dtct = dtc_safe * MIN(dsx,dsy)/cc;

  div=0.0;


  dv1 = (xvel0[OPS_ACC5(0,0)] + xvel0[OPS_ACC5(0,1)]) * xarea[OPS_ACC6(0,0)];
  dv2 = (xvel0[OPS_ACC5(1,0)] + xvel0[OPS_ACC5(1,1)]) * xarea[OPS_ACC6(1,0)];

  div = div + dv2 - dv1;

  dtut = dtu_safe * 2.0 * volume[OPS_ACC7(0,0)]/MAX(MAX(fabs(dv1), fabs(dv2)), g_small * volume[OPS_ACC7(0,0)]);

  dv1 = (yvel0[OPS_ACC8(0,0)] + yvel0[OPS_ACC8(1,0)]) * yarea[OPS_ACC9(0,0)];
  dv2 = (yvel0[OPS_ACC8(0,1)] + yvel0[OPS_ACC8(1,1)]) * yarea[OPS_ACC9(0,1)];

  div = div + dv2 - dv1;

  dtvt = dtv_safe * 2.0 * volume[OPS_ACC7(0,0)]/MAX(MAX(fabs(dv1),fabs(dv2)), g_small * volume[OPS_ACC7(0,0)]);

  div = div/(2.0 * volume[OPS_ACC7(0,0)]);

  if(div < -g_small)
    dtdivt = dtdiv_safe * (-1.0/div);
  else
    dtdivt = g_big;

  dt_min[OPS_ACC10(0,0)] = MIN(MIN(dtct, dtut), MIN(dtvt, dtdivt));


}



 #undef OPS_ACC0
 #undef OPS_ACC1
 #undef OPS_ACC2
 #undef OPS_ACC3
 #undef OPS_ACC4
 #undef OPS_ACC5
 #undef OPS_ACC6
 #undef OPS_ACC7
 #undef OPS_ACC8
 #undef OPS_ACC9
 #undef OPS_ACC10


 __kernel void ops_calc_dt_kernel(
 __global double* arg0,
 __global double* arg1,
 __global double* arg2,
 __global double* arg3,
 __global double* arg4,
 __global double* arg5,
 __global double* arg6,
 __global double* arg7,
 __global double* arg8,
 __global double* arg9,
 __global double* arg10,
 __global double *g_small,
 __global double *g_big,
 __global double *dtc_safe,
 __global double *dtu_safe,
 __global double *dtv_safe,
 __global double *dtdiv_safe,
 int xdim0_calc_dt_kernel,
 int xdim1_calc_dt_kernel,
 int xdim2_calc_dt_kernel,
 int xdim3_calc_dt_kernel,
 int xdim4_calc_dt_kernel,
 int xdim5_calc_dt_kernel,
 int xdim6_calc_dt_kernel,
 int xdim7_calc_dt_kernel,
 int xdim8_calc_dt_kernel,
 int xdim9_calc_dt_kernel,
 int xdim10_calc_dt_kernel,
 const int base0,
 const int base1,
 const int base2,
 const int base3,
 const int base4,
 const int base5,
 const int base6,
 const int base7,
 const int base8,
 const int base9,
 const int base10,
 int size0,
 int size1 ){


   int idx_y = get_global_id(1);
   int idx_x = get_global_id(0);

   if (idx_x < size0 && idx_y < size1) {
     calc_dt_kernel(&arg0[base0 + idx_x * 1 + idx_y * 0 * xdim0_calc_dt_kernel],
                    &arg1[base1 + idx_x * 0 + idx_y * 1 * xdim1_calc_dt_kernel],
                    &arg2[base2 + idx_x * 1 + idx_y * 1 * xdim2_calc_dt_kernel],
                    &arg3[base3 + idx_x * 1 + idx_y * 1 * xdim3_calc_dt_kernel],
                    &arg4[base4 + idx_x * 1 + idx_y * 1 * xdim4_calc_dt_kernel],
                    &arg5[base5 + idx_x * 1 + idx_y * 1 * xdim5_calc_dt_kernel],
                    &arg6[base6 + idx_x * 1 + idx_y * 1 * xdim6_calc_dt_kernel],
                    &arg7[base7 + idx_x * 1 + idx_y * 1 * xdim7_calc_dt_kernel],
                    &arg8[base8 + idx_x * 1 + idx_y * 1 * xdim8_calc_dt_kernel],
                    &arg9[base9 + idx_x * 1 + idx_y * 1 * xdim9_calc_dt_kernel],
                    &arg10[base10 + idx_x * 1 + idx_y * 1 * xdim10_calc_dt_kernel],
                    *g_small,*g_big,*dtc_safe,*dtu_safe,*dtv_safe,*dtdiv_safe,
                    xdim0_calc_dt_kernel,
                    xdim1_calc_dt_kernel,
                    xdim2_calc_dt_kernel,
                    xdim3_calc_dt_kernel,
                    xdim4_calc_dt_kernel,
                    xdim5_calc_dt_kernel,
                    xdim6_calc_dt_kernel,
                    xdim7_calc_dt_kernel,
                    xdim8_calc_dt_kernel,
                    xdim9_calc_dt_kernel,
                    xdim10_calc_dt_kernel);
   }

 }

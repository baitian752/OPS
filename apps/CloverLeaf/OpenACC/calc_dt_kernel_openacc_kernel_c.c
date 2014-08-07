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

int xdim0_calc_dt_kernel;
int xdim1_calc_dt_kernel;
int xdim2_calc_dt_kernel;
int xdim3_calc_dt_kernel;
int xdim4_calc_dt_kernel;
int xdim5_calc_dt_kernel;
int xdim6_calc_dt_kernel;
int xdim7_calc_dt_kernel;
int xdim8_calc_dt_kernel;
int xdim9_calc_dt_kernel;
int xdim10_calc_dt_kernel;

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
inline 
void calc_dt_kernel(const double *celldx, const double *celldy, const double *soundspeed,
                    const double *viscosity, const double *density0, const double *xvel0,
                    const double *xarea, const double *volume, const double *yvel0,
                    const double *yarea, double *dt_min ) {

  double div, dsx, dsy, dtut, dtvt, dtct, dtdivt, cc, dv1, dv2, jk_control;

  dsx = celldx[OPS_ACC0(0,0)];
  dsy = celldy[OPS_ACC1(0,0)];

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


void calc_dt_kernel_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  double *p_a4,
  double *p_a5,
  double *p_a6,
  double *p_a7,
  double *p_a8,
  double *p_a9,
  double *p_a10,
  int x_size, int y_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2,p_a3,p_a4,p_a5,p_a6,p_a7,p_a8,p_a9,p_a10)
  #pragma acc loop
  #endif
  for ( int n_y=0; n_y<y_size; n_y++ ){
    #ifdef OPS_GPU
    #pragma acc loop
    #endif
    for ( int n_x=0; n_x<x_size; n_x++ ){
      calc_dt_kernel(  p_a0 + n_x*1 + n_y*xdim0_calc_dt_kernel*0,
           p_a1 + n_x*0 + n_y*xdim1_calc_dt_kernel*1, p_a2 + n_x*1 + n_y*xdim2_calc_dt_kernel*1,
           p_a3 + n_x*1 + n_y*xdim3_calc_dt_kernel*1, p_a4 + n_x*1 + n_y*xdim4_calc_dt_kernel*1,
           p_a5 + n_x*1 + n_y*xdim5_calc_dt_kernel*1, p_a6 + n_x*1 + n_y*xdim6_calc_dt_kernel*1,
           p_a7 + n_x*1 + n_y*xdim7_calc_dt_kernel*1, p_a8 + n_x*1 + n_y*xdim8_calc_dt_kernel*1,
           p_a9 + n_x*1 + n_y*xdim9_calc_dt_kernel*1, p_a10 + n_x*1 + n_y*xdim10_calc_dt_kernel*1 );

    }
  }
}

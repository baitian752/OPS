//
// auto-generated by ops.py on 2014-07-09 10:24
//

#ifdef _OPENMP
#include <omp.h>
#endif

//user function
inline 
void calc_dt_kernel_print(const double *xvel0, const double *yvel0,
                        const double *density0, const double *energy0,
                        const double *pressure, const double *soundspeed, double *output) {
  output[0] = xvel0[OPS_ACC0(1,0)];
  output[1] = yvel0[OPS_ACC1(1,0)];
  output[2] = xvel0[OPS_ACC0(-1,0)];
  output[3] = yvel0[OPS_ACC1(-1,0)];
  output[4] = xvel0[OPS_ACC0(0,1)];
  output[5] = yvel0[OPS_ACC1(0,1)];
  output[6] = xvel0[OPS_ACC0(0,-1)];
  output[7] = yvel0[OPS_ACC1(0,-1)];
  output[8] = density0[OPS_ACC2(0,0)];
  output[9] = energy0[OPS_ACC3(0,0)];
  output[10]= pressure[OPS_ACC4(0,0)];
  output[11]= soundspeed[OPS_ACC5(0,0)];

}



// host stub function
void ops_par_loop_calc_dt_kernel_print(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6) {

  //Timing
  double t1,t2,c1,c2;
  ops_timing_realloc(74,"calc_dt_kernel_print");
  ops_timers_core(&c1,&t1);


  int  offs[7][2];
  ops_arg args[7] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6};


  sub_block_list sb = OPS_sub_block_list[block->index];
  //compute localy allocated range for the sub-block

  int start[2];
  int end[2];

  for ( int n=0; n<2; n++ ){
    start[n] = sb->istart[n];end[n] = sb->iend[n]+1;
    if (start[n] >= range[2*n]) {
      start[n] = 0;
    }
    else {
      start[n] = range[2*n] - start[n];
    }
    if (end[n] >= range[2*n+1]) {
      end[n] = range[2*n+1] - sb->istart[n];
    }
    else {
      end[n] = sb->sizes[n];
    }
  }

  #ifdef OPS_DEBUG
  ops_register_args(args, "calc_dt_kernel_print");
  #endif

  offs[0][0] = args[0].stencil->stride[0]*1;  //unit step in x dimension
  offs[0][1] = off2D(1, &start[0],
      &end[0],args[0].dat->block_size, args[0].stencil->stride) - offs[0][0];

  offs[1][0] = args[1].stencil->stride[0]*1;  //unit step in x dimension
  offs[1][1] = off2D(1, &start[0],
      &end[0],args[1].dat->block_size, args[1].stencil->stride) - offs[1][0];

  offs[2][0] = args[2].stencil->stride[0]*1;  //unit step in x dimension
  offs[2][1] = off2D(1, &start[0],
      &end[0],args[2].dat->block_size, args[2].stencil->stride) - offs[2][0];

  offs[3][0] = args[3].stencil->stride[0]*1;  //unit step in x dimension
  offs[3][1] = off2D(1, &start[0],
      &end[0],args[3].dat->block_size, args[3].stencil->stride) - offs[3][0];

  offs[4][0] = args[4].stencil->stride[0]*1;  //unit step in x dimension
  offs[4][1] = off2D(1, &start[0],
      &end[0],args[4].dat->block_size, args[4].stencil->stride) - offs[4][0];

  offs[5][0] = args[5].stencil->stride[0]*1;  //unit step in x dimension
  offs[5][1] = off2D(1, &start[0],
      &end[0],args[5].dat->block_size, args[5].stencil->stride) - offs[5][0];



  int off0_0 = offs[0][0];
  int off0_1 = offs[0][1];
  int dat0 = args[0].dat->size;
  int off1_0 = offs[1][0];
  int off1_1 = offs[1][1];
  int dat1 = args[1].dat->size;
  int off2_0 = offs[2][0];
  int off2_1 = offs[2][1];
  int dat2 = args[2].dat->size;
  int off3_0 = offs[3][0];
  int off3_1 = offs[3][1];
  int dat3 = args[3].dat->size;
  int off4_0 = offs[4][0];
  int off4_1 = offs[4][1];
  int dat4 = args[4].dat->size;
  int off5_0 = offs[5][0];
  int off5_1 = offs[5][1];
  int dat5 = args[5].dat->size;

  double*arg6h = (double *)arg6.data;

  #ifdef _OPENMP
  int nthreads = omp_get_max_threads( );
  #else
  int nthreads = 1;
  #endif
  //allocate and initialise arrays for global reduction
  //assumes a max of MAX_REDUCT_THREADS threads with a cacche line size of 64 bytes
  double arg_gbl6[MAX(12 , 64) * MAX_REDUCT_THREADS];
  for ( int thr=0; thr<nthreads; thr++ ){
    for ( int d=0; d<12; d++ ){
      arg_gbl6[d+64*thr] = ZERO_double;
    }
  }
  xdim0 = args[0].dat->block_size[0]*args[0].dat->dim;
  xdim1 = args[1].dat->block_size[0]*args[1].dat->dim;
  xdim2 = args[2].dat->block_size[0]*args[2].dat->dim;
  xdim3 = args[3].dat->block_size[0]*args[3].dat->dim;
  xdim4 = args[4].dat->block_size[0]*args[4].dat->dim;
  xdim5 = args[5].dat->block_size[0]*args[5].dat->dim;

  //Halo Exchanges
  ops_halo_exchanges(args,7,range);

  ops_H_D_exchanges(args, 7);


  ops_timers_core(&c2,&t2);
  OPS_kernels[74].mpi_time += t2-t1;


  #pragma omp parallel for
  for ( int thr=0; thr<nthreads; thr++ ){

    int y_size = end[1]-start[1];
    char *p_a[7];

    int start_i = start[1] + ((y_size-1)/nthreads+1)*thr;
    int finish_i = start[1] + MIN(((y_size-1)/nthreads+1)*(thr+1),y_size);

    //get address per thread
    int start0 = start[0];
    int start1 = start_i;

    //set up initial pointers 
    int base0 = dat0 * 1 * 
    (start0 * args[0].stencil->stride[0] - args[0].dat->offset[0]);
    base0 = base0+ dat0 *
      args[0].dat->block_size[0] *
      (start1 * args[0].stencil->stride[1] - args[0].dat->offset[1]);
    p_a[0] = (char *)args[0].data + base0;

    int base1 = dat1 * 1 * 
    (start0 * args[1].stencil->stride[0] - args[1].dat->offset[0]);
    base1 = base1+ dat1 *
      args[1].dat->block_size[0] *
      (start1 * args[1].stencil->stride[1] - args[1].dat->offset[1]);
    p_a[1] = (char *)args[1].data + base1;

    int base2 = dat2 * 1 * 
    (start0 * args[2].stencil->stride[0] - args[2].dat->offset[0]);
    base2 = base2+ dat2 *
      args[2].dat->block_size[0] *
      (start1 * args[2].stencil->stride[1] - args[2].dat->offset[1]);
    p_a[2] = (char *)args[2].data + base2;

    int base3 = dat3 * 1 * 
    (start0 * args[3].stencil->stride[0] - args[3].dat->offset[0]);
    base3 = base3+ dat3 *
      args[3].dat->block_size[0] *
      (start1 * args[3].stencil->stride[1] - args[3].dat->offset[1]);
    p_a[3] = (char *)args[3].data + base3;

    int base4 = dat4 * 1 * 
    (start0 * args[4].stencil->stride[0] - args[4].dat->offset[0]);
    base4 = base4+ dat4 *
      args[4].dat->block_size[0] *
      (start1 * args[4].stencil->stride[1] - args[4].dat->offset[1]);
    p_a[4] = (char *)args[4].data + base4;

    int base5 = dat5 * 1 * 
    (start0 * args[5].stencil->stride[0] - args[5].dat->offset[0]);
    base5 = base5+ dat5 *
      args[5].dat->block_size[0] *
      (start1 * args[5].stencil->stride[1] - args[5].dat->offset[1]);
    p_a[5] = (char *)args[5].data + base5;

    p_a[6] = (char *)args[6].data;


    for ( int n_y=start_i; n_y<finish_i; n_y++ ){
      for ( int n_x=start[0]; n_x<start[0]+(end[0]-start[0])/SIMD_VEC; n_x++ ){
        //call kernel function, passing in pointers to data -vectorised
        for ( int i=0; i<SIMD_VEC; i++ ){
          calc_dt_kernel_print(  (const double * restrict)p_a[0]+ i*1, (const double * restrict)p_a[1]+ i*1, (const double * restrict)p_a[2]+ i*1,
           (const double * restrict)p_a[3]+ i*1, (const double * restrict)p_a[4]+ i*1, (const double * restrict)p_a[5]+ i*1, &arg_gbl6[64*thr] );

        }

        //shift pointers to data x direction
        p_a[0]= p_a[0] + (dat0 * off0_0)*SIMD_VEC;
        p_a[1]= p_a[1] + (dat1 * off1_0)*SIMD_VEC;
        p_a[2]= p_a[2] + (dat2 * off2_0)*SIMD_VEC;
        p_a[3]= p_a[3] + (dat3 * off3_0)*SIMD_VEC;
        p_a[4]= p_a[4] + (dat4 * off4_0)*SIMD_VEC;
        p_a[5]= p_a[5] + (dat5 * off5_0)*SIMD_VEC;
      }

      for ( int n_x=start[0]+((end[0]-start[0])/SIMD_VEC)*SIMD_VEC; n_x<end[0]; n_x++ ){
        //call kernel function, passing in pointers to data - remainder
        calc_dt_kernel_print(  (const double * restrict)p_a[0], (const double * restrict)p_a[1], (const double * restrict)p_a[2],
           (const double * restrict)p_a[3], (const double * restrict)p_a[4], (const double * restrict)p_a[5], &arg_gbl6[64*thr] );


        //shift pointers to data x direction
        p_a[0]= p_a[0] + (dat0 * off0_0);
        p_a[1]= p_a[1] + (dat1 * off1_0);
        p_a[2]= p_a[2] + (dat2 * off2_0);
        p_a[3]= p_a[3] + (dat3 * off3_0);
        p_a[4]= p_a[4] + (dat4 * off4_0);
        p_a[5]= p_a[5] + (dat5 * off5_0);
      }

      //shift pointers to data y direction
      p_a[0]= p_a[0] + (dat0 * off0_1);
      p_a[1]= p_a[1] + (dat1 * off1_1);
      p_a[2]= p_a[2] + (dat2 * off2_1);
      p_a[3]= p_a[3] + (dat3 * off3_1);
      p_a[4]= p_a[4] + (dat4 * off4_1);
      p_a[5]= p_a[5] + (dat5 * off5_1);
    }
  }

  ops_timers_core(&c1,&t1);
  OPS_kernels[74].time += t1-t2;


  // combine reduction data
  for ( int thr=0; thr<nthreads; thr++ ){
    for ( int d=0; d<12; d++ ){
      arg6h[d] += arg_gbl6[64*thr+d];
    }
  }
  ops_mpi_reduce(&arg6,(double *)arg6h);
  ops_set_dirtybit_host(args, 7);


  #ifdef OPS_DEBUG
  #endif

  //Update kernel record
  ops_timers_core(&c2,&t2);
  OPS_kernels[74].count++;
  OPS_kernels[74].mpi_time += t2-t1;
  OPS_kernels[74].transfer += ops_compute_transfer(dim, range, &arg0);
  OPS_kernels[74].transfer += ops_compute_transfer(dim, range, &arg1);
  OPS_kernels[74].transfer += ops_compute_transfer(dim, range, &arg2);
  OPS_kernels[74].transfer += ops_compute_transfer(dim, range, &arg3);
  OPS_kernels[74].transfer += ops_compute_transfer(dim, range, &arg4);
  OPS_kernels[74].transfer += ops_compute_transfer(dim, range, &arg5);
}

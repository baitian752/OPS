//
// auto-generated by ops.py on 2014-03-17 12:08
//

//user function
#include "reset_field_kernel.h"

// host stub function
void ops_par_loop_reset_field_kernel2(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3) {

  char *p_a[4];
  int  offs[4][2];
  ops_arg args[4] = { arg0, arg1, arg2, arg3};


  sub_block_list sb = OPS_sub_block_list[block->index];
  //compute localy allocated range for the sub-block
  int ndim = sb->ndim;
  int start[ndim];
  int end[ndim];
  for ( int n=0; n<ndim; n++ ){
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
  ops_register_args(args, "reset_field_kernel2");
  #endif

  offs[0][0] = args[0].stencil->stride[0]*1;  //unit step in x dimension
  for ( int n=1; n<ndim; n++ ){
    offs[0][n] = off2(ndim, n, &start[0],
    &end[0],args[0].dat->block_size, args[0].stencil->stride);
  }
  offs[1][0] = args[1].stencil->stride[0]*1;  //unit step in x dimension
  for ( int n=1; n<ndim; n++ ){
    offs[1][n] = off2(ndim, n, &start[0],
    &end[0],args[1].dat->block_size, args[1].stencil->stride);
  }
  offs[2][0] = args[2].stencil->stride[0]*1;  //unit step in x dimension
  for ( int n=1; n<ndim; n++ ){
    offs[2][n] = off2(ndim, n, &start[0],
    &end[0],args[2].dat->block_size, args[2].stencil->stride);
  }
  offs[3][0] = args[3].stencil->stride[0]*1;  //unit step in x dimension
  for ( int n=1; n<ndim; n++ ){
    offs[3][n] = off2(ndim, n, &start[0],
    &end[0],args[3].dat->block_size, args[3].stencil->stride);
  }


  //Timing
  double t1,t2,c1,c2;
  ops_timing_realloc(2,"reset_field_kernel2");
  ops_timers_core(&c2,&t2);

  int off0_1 = offs[0][0];
  int off0_2 = offs[0][1];
  int dat0 = args[0].dat->size;
  int off1_1 = offs[1][0];
  int off1_2 = offs[1][1];
  int dat1 = args[1].dat->size;
  int off2_1 = offs[2][0];
  int off2_2 = offs[2][1];
  int dat2 = args[2].dat->size;
  int off3_1 = offs[3][0];
  int off3_2 = offs[3][1];
  int dat3 = args[3].dat->size;

  //set up initial pointers and exchange halos if nessasary
  int base0 = dat0 * 1 * 
  (start[0] * args[0].stencil->stride[0] - args[0].dat->offset[0]);
  base0 = base0  + dat0 * args[0].dat->block_size[0] * 
  (start[1] * args[0].stencil->stride[1] - args[0].dat->offset[1]);
  p_a[0] = (char *)args[0].data + base0;

  //set up initial pointers and exchange halos if nessasary
  int base1 = dat1 * 1 * 
  (start[0] * args[1].stencil->stride[0] - args[1].dat->offset[0]);
  base1 = base1  + dat1 * args[1].dat->block_size[0] * 
  (start[1] * args[1].stencil->stride[1] - args[1].dat->offset[1]);
  p_a[1] = (char *)args[1].data + base1;
  ops_exchange_halo(&args[1],2);

  //set up initial pointers and exchange halos if nessasary
  int base2 = dat2 * 1 * 
  (start[0] * args[2].stencil->stride[0] - args[2].dat->offset[0]);
  base2 = base2  + dat2 * args[2].dat->block_size[0] * 
  (start[1] * args[2].stencil->stride[1] - args[2].dat->offset[1]);
  p_a[2] = (char *)args[2].data + base2;

  //set up initial pointers and exchange halos if nessasary
  int base3 = dat3 * 1 * 
  (start[0] * args[3].stencil->stride[0] - args[3].dat->offset[0]);
  base3 = base3  + dat3 * args[3].dat->block_size[0] * 
  (start[1] * args[3].stencil->stride[1] - args[3].dat->offset[1]);
  p_a[3] = (char *)args[3].data + base3;
  ops_exchange_halo(&args[3],2);



  ops_timers_core(&c1,&t1);
  OPS_kernels[2].mpi_time += t1-t2;

  xdim0 = args[0].dat->block_size[0];
  xdim1 = args[1].dat->block_size[0];
  xdim2 = args[2].dat->block_size[0];
  xdim3 = args[3].dat->block_size[0];

  int n_x;
  for ( int n_y=start[1]; n_y<end[1]; n_y++ ){
    for( n_x=start[0]; n_x<start[0]+((end[0]-start[0])/SIMD_VEC)*SIMD_VEC; n_x+=SIMD_VEC ) {
      //call kernel function, passing in pointers to data -vectorised
      #pragma simd
      for ( int i=0; i<SIMD_VEC; i++ ){
        reset_field_kernel2(  (double *)p_a[0]+ i*1, (double *)p_a[1]+ i*1, (double *)p_a[2]+ i*1,
           (double *)p_a[3]+ i*1 );

      }

      //shift pointers to data x direction
      p_a[0]= p_a[0] + (dat0 * off0_1)*SIMD_VEC;
      p_a[1]= p_a[1] + (dat1 * off1_1)*SIMD_VEC;
      p_a[2]= p_a[2] + (dat2 * off2_1)*SIMD_VEC;
      p_a[3]= p_a[3] + (dat3 * off3_1)*SIMD_VEC;
    }

    for ( int n_x=start[0]+((end[0]-start[0])/SIMD_VEC)*SIMD_VEC; n_x<end[0]; n_x++ ){
        //call kernel function, passing in pointers to data - remainder
        reset_field_kernel2(  (double *)p_a[0], (double *)p_a[1], (double *)p_a[2],
           (double *)p_a[3] );


        //shift pointers to data x direction
        p_a[0]= p_a[0] + (dat0 * off0_1);
        p_a[1]= p_a[1] + (dat1 * off1_1);
        p_a[2]= p_a[2] + (dat2 * off2_1);
        p_a[3]= p_a[3] + (dat3 * off3_1);
      }

      //shift pointers to data y direction
      p_a[0]= p_a[0] + (dat0 * off0_2);
      p_a[1]= p_a[1] + (dat1 * off1_2);
      p_a[2]= p_a[2] + (dat2 * off2_2);
      p_a[3]= p_a[3] + (dat3 * off3_2);
    }
    ops_timers_core(&c2,&t2);
    OPS_kernels[2].time += t2-t1;
    ops_set_halo_dirtybit(&args[0]);
    ops_set_halo_dirtybit(&args[2]);

    //Update kernel record
    OPS_kernels[2].count++;
    OPS_kernels[2].transfer += ops_compute_transfer(dim, range, &arg0);
    OPS_kernels[2].transfer += ops_compute_transfer(dim, range, &arg1);
    OPS_kernels[2].transfer += ops_compute_transfer(dim, range, &arg2);
    OPS_kernels[2].transfer += ops_compute_transfer(dim, range, &arg3);
  }

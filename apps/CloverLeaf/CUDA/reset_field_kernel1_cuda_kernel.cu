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

__constant__ int xdim0_reset_field_kernel1;
__constant__ int xdim1_reset_field_kernel1;
__constant__ int xdim2_reset_field_kernel1;
__constant__ int xdim3_reset_field_kernel1;

#define OPS_ACC0(x,y) (x+xdim0_reset_field_kernel1*(y))
#define OPS_ACC1(x,y) (x+xdim1_reset_field_kernel1*(y))
#define OPS_ACC2(x,y) (x+xdim2_reset_field_kernel1*(y))
#define OPS_ACC3(x,y) (x+xdim3_reset_field_kernel1*(y))

//user function
__device__

void reset_field_kernel1( double *density0, const double *density1,
                        double *energy0, const double *energy1) {

  density0[OPS_ACC0(0,0)]  = density1[OPS_ACC1(0,0)] ;
  energy0[OPS_ACC2(0,0)]  = energy1[OPS_ACC3(0,0)] ;

}



#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3


__global__ void ops_reset_field_kernel1(
double* __restrict arg0,
const double* __restrict arg1,
double* __restrict arg2,
const double* __restrict arg3,
int size0,
int size1 ){


  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 += idx_x * 1 + idx_y * 1 * xdim0_reset_field_kernel1;
  arg1 += idx_x * 1 + idx_y * 1 * xdim1_reset_field_kernel1;
  arg2 += idx_x * 1 + idx_y * 1 * xdim2_reset_field_kernel1;
  arg3 += idx_x * 1 + idx_y * 1 * xdim3_reset_field_kernel1;

  if (idx_x < size0 && idx_y < size1) {
    reset_field_kernel1(arg0, arg1, arg2, arg3);
  }

}

// host stub function
void ops_par_loop_reset_field_kernel1(char const *name, ops_block Block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3) {

  ops_arg args[4] = { arg0, arg1, arg2, arg3};

  //compute locally allocated range for the sub-block
  int start[2];
  int end[2];
  #ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  for ( int n=0; n<2; n++ ){
    start[n] = sb->decomp_disp[n];end[n] = sb->decomp_disp[n]+sb->decomp_size[n];
    if (start[n] >= range[2*n]) {
      start[n] = 0;
    }
    else {
      start[n] = range[2*n] - start[n];
    }
    if (end[n] >= range[2*n+1]) {
      end[n] = range[2*n+1] - sb->decomp_disp[n];
    }
    else {
      end[n] = sb->decomp_size[n];
    }
  }
  #else //OPS_MPI
  for ( int n=0; n<2; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #endif //OPS_MPI

  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);

  int xdim0 = args[0].dat->size[0]*args[0].dat->dim;
  int xdim1 = args[1].dat->size[0]*args[1].dat->dim;
  int xdim2 = args[2].dat->size[0]*args[2].dat->dim;
  int xdim3 = args[3].dat->size[0]*args[3].dat->dim;


  //Timing
  double t1,t2,c1,c2;
  ops_timing_realloc(1,"reset_field_kernel1");
  ops_timers_core(&c2,&t2);

  if (OPS_kernels[1].count == 0) {
    cudaMemcpyToSymbol( xdim0_reset_field_kernel1, &xdim0, sizeof(int) );
    cudaMemcpyToSymbol( xdim1_reset_field_kernel1, &xdim1, sizeof(int) );
    cudaMemcpyToSymbol( xdim2_reset_field_kernel1, &xdim2, sizeof(int) );
    cudaMemcpyToSymbol( xdim3_reset_field_kernel1, &xdim3, sizeof(int) );
  }



  dim3 grid( (x_size-1)/OPS_block_size_x+ 1, (y_size-1)/OPS_block_size_y + 1, 1);
  dim3 block(OPS_block_size_x,OPS_block_size_y,1);



  int dat0 = args[0].dat->elem_size;
  int dat1 = args[1].dat->elem_size;
  int dat2 = args[2].dat->elem_size;
  int dat3 = args[3].dat->elem_size;

  char *p_a[4];

  //set up initial pointers
  int base0 = dat0 * 1 * 
  (start[0] * args[0].stencil->stride[0] - args[0].dat->base[0] - args[0].dat->d_m[0]);
  base0 = base0+ dat0 *
    args[0].dat->size[0] *
    (start[1] * args[0].stencil->stride[1] - args[0].dat->base[1] - args[0].dat->d_m[1]);
  p_a[0] = (char *)args[0].data_d + base0;

  int base1 = dat1 * 1 * 
  (start[0] * args[1].stencil->stride[0] - args[1].dat->base[0] - args[1].dat->d_m[0]);
  base1 = base1+ dat1 *
    args[1].dat->size[0] *
    (start[1] * args[1].stencil->stride[1] - args[1].dat->base[1] - args[1].dat->d_m[1]);
  p_a[1] = (char *)args[1].data_d + base1;

  int base2 = dat2 * 1 * 
  (start[0] * args[2].stencil->stride[0] - args[2].dat->base[0] - args[2].dat->d_m[0]);
  base2 = base2+ dat2 *
    args[2].dat->size[0] *
    (start[1] * args[2].stencil->stride[1] - args[2].dat->base[1] - args[2].dat->d_m[1]);
  p_a[2] = (char *)args[2].data_d + base2;

  int base3 = dat3 * 1 * 
  (start[0] * args[3].stencil->stride[0] - args[3].dat->base[0] - args[3].dat->d_m[0]);
  base3 = base3+ dat3 *
    args[3].dat->size[0] *
    (start[1] * args[3].stencil->stride[1] - args[3].dat->base[1] - args[3].dat->d_m[1]);
  p_a[3] = (char *)args[3].data_d + base3;


  ops_H_D_exchanges_device(args, 4);
  ops_halo_exchanges(args,4,range);

  ops_timers_core(&c1,&t1);
  OPS_kernels[1].mpi_time += t1-t2;


  //call kernel wrapper function, passing in pointers to data
  ops_reset_field_kernel1<<<grid, block >>> (  (double *)p_a[0], (double *)p_a[1],
           (double *)p_a[2], (double *)p_a[3],x_size, y_size);

  if (OPS_diags>1) {
    cutilSafeCall(cudaDeviceSynchronize());
  }
  ops_timers_core(&c2,&t2);
  OPS_kernels[1].time += t2-t1;
  ops_set_dirtybit_device(args, 4);
  ops_set_halo_dirtybit3(&args[0],range);
  ops_set_halo_dirtybit3(&args[2],range);

  //Update kernel record
  OPS_kernels[1].count++;
  OPS_kernels[1].transfer += ops_compute_transfer(dim, range, &arg0);
  OPS_kernels[1].transfer += ops_compute_transfer(dim, range, &arg1);
  OPS_kernels[1].transfer += ops_compute_transfer(dim, range, &arg2);
  OPS_kernels[1].transfer += ops_compute_transfer(dim, range, &arg3);
}

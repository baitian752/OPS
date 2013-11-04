//
// auto-generated by ops.py on 2013-11-04 16:25
//

#include "lib.h"
//user function
#include "advec_mom_kernel.h"

// host stub function
void ops_par_loop_advec_mom_kernel_y1(char const *name, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4) {

  char *p_a[5];
  int  offs[5][2];
  int  count[dim];

  ops_arg args[5] = { arg0, arg1, arg2, arg3, arg4};


  for ( int i=0; i<5; i++ ){
    if (args[i].stencil!=NULL) {
      offs[i][0] = 1;  //unit step in x dimension
      offs[i][1] = ops_offs_set(range[0],range[2]+1, args[i]) - ops_offs_set(range[1],range[2], args[i]);
      //stride in y as x stride is 0
      if (args[i].stencil->stride[0] == 0) {
        offs[i][0] = 0;
        offs[i][1] = args[i].dat->block_size[0];
      }
      //stride in x as y stride is 0
      else if (args[i].stencil->stride[1] == 0) {
        offs[i][0] = 1;
        offs[i][1] = -( range[1] - range[0] );
      }
    }
  }
  //set up initial pointers
  for ( int i=0; i<5; i++ ){
    if (args[i].argtype == OPS_ARG_DAT) {
      p_a[i] = (char *)args[i].data //base of 2D array
      +
      //y dimension -- get to the correct y line
      args[i].dat->size * args[i].dat->block_size[0] * ( range[2] * args[i].stencil->stride[1] - args[i].dat->offset[1] )
      +
      //x dimension - get to the correct x point on the y line
      args[i].dat->size * ( range[0] * args[i].stencil->stride[0] - args[i].dat->offset[0] );
    }
    else if (args[i].argtype == OPS_ARG_GBL) {
      p_a[i] = (char *)args[i].data;
    }
  }

  xdim0 = args[0].dat->block_size[0];
  xdim1 = args[1].dat->block_size[0];
  xdim2 = args[2].dat->block_size[0];
  xdim3 = args[3].dat->block_size[0];
  xdim4 = args[4].dat->block_size[0];

  for ( int n_y=range[2]; n_y<range[3]; n_y++ ){
    for ( int n_x=range[0]; n_x<range[1]; n_x++ ){
      //call kernel function, passing in pointers to data

      advec_mom_kernel_y1(  (double *)p_a[0], (double *)p_a[1], (double *)p_a[2],
           (double *)p_a[3], (double *)p_a[4] );


      //shift pointers to data x direction
      p_a[0]= p_a[0] + (args[0].dat->size * offs[0][0]);
      p_a[1]= p_a[1] + (args[1].dat->size * offs[1][0]);
      p_a[2]= p_a[2] + (args[2].dat->size * offs[2][0]);
      p_a[3]= p_a[3] + (args[3].dat->size * offs[3][0]);
      p_a[4]= p_a[4] + (args[4].dat->size * offs[4][0]);
    }

    //shift pointers to data y direction
    p_a[0]= p_a[0] + (args[0].dat->size * offs[0][1]);
    p_a[1]= p_a[1] + (args[1].dat->size * offs[1][1]);
    p_a[2]= p_a[2] + (args[2].dat->size * offs[2][1]);
    p_a[3]= p_a[3] + (args[3].dat->size * offs[3][1]);
    p_a[4]= p_a[4] + (args[4].dat->size * offs[4][1]);
  }
}

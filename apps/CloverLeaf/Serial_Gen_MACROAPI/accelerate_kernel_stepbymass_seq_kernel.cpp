//
// auto-generated by ops.py on 2013-11-04 16:25
//

#include "lib.h"
//user function
#include "accelerate_kernel.h"

// host stub function
void ops_par_loop_accelerate_kernel_stepbymass(char const *name, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2) {

  char *p_a[3];
  int  offs[3][2];
  int  count[dim];

  ops_arg args[3] = { arg0, arg1, arg2};


  for ( int i=0; i<3; i++ ){
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
  for ( int i=0; i<3; i++ ){
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

  for ( int n_y=range[2]; n_y<range[3]; n_y++ ){
    for ( int n_x=range[0]; n_x<range[1]; n_x++ ){
      //call kernel function, passing in pointers to data

      accelerate_kernel_stepbymass(  (double *)p_a[0], (double *)p_a[1], (double *)p_a[2] );


      //shift pointers to data x direction
      p_a[0]= p_a[0] + (args[0].dat->size * offs[0][0]);
      p_a[1]= p_a[1] + (args[1].dat->size * offs[1][0]);
      p_a[2]= p_a[2] + (args[2].dat->size * offs[2][0]);
    }

    //shift pointers to data y direction
    p_a[0]= p_a[0] + (args[0].dat->size * offs[0][1]);
    p_a[1]= p_a[1] + (args[1].dat->size * offs[1][1]);
    p_a[2]= p_a[2] + (args[2].dat->size * offs[2][1]);
  }
}

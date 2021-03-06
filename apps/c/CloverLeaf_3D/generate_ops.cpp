//
// auto-generated by ops.py
//

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OPS_3D
#include "ops_lib_cpp.h"

//
// ops_par_loop declarations
//

void ops_par_loop_generate_chunk_kernel(char const *, ops_block, int, int *,
                                        ops_arg, ops_arg, ops_arg, ops_arg,
                                        ops_arg, ops_arg, ops_arg, ops_arg,
                                        ops_arg, ops_arg, ops_arg);

#include "data.h"
#include "definitions.h"

//#include "generate_chunk_kernel.h"

void generate() {

  int x_min = field.x_min;
  int x_max = field.x_max;
  int y_min = field.y_min;
  int y_max = field.y_max;
  int z_min = field.z_min;
  int z_max = field.z_max;

  int rangexyz[] = {x_min - 2, x_max + 2, y_min - 2,
                    y_max + 2, z_min - 2, z_max + 2};

  ops_par_loop_generate_chunk_kernel(
      "generate_chunk_kernel", clover_grid, 3, rangexyz,
      ops_arg_dat(vertexx, 1, S3D_000_P100_M100_STRID3D_X, "double", OPS_READ),
      ops_arg_dat(vertexy, 1, S3D_000_0P10_0M10_STRID3D_Y, "double", OPS_READ),
      ops_arg_dat(vertexz, 1, S3D_000_00P1_00M1_STRID3D_Z, "double", OPS_READ),
      ops_arg_dat(energy0, 1, S3D_000, "double", OPS_WRITE),
      ops_arg_dat(density0, 1, S3D_000, "double", OPS_WRITE),
      ops_arg_dat(xvel0, 1, S3D_000, "double", OPS_WRITE),
      ops_arg_dat(yvel0, 1, S3D_000, "double", OPS_WRITE),
      ops_arg_dat(zvel0, 1, S3D_000, "double", OPS_WRITE),
      ops_arg_dat(cellx, 1, S3D_000_P100_M100_STRID3D_X, "double", OPS_READ),
      ops_arg_dat(celly, 1, S3D_000_0P10_0M10_STRID3D_Y, "double", OPS_READ),
      ops_arg_dat(cellz, 1, S3D_000_00P1_00M1_STRID3D_Z, "double", OPS_READ));
}

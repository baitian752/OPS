//
// auto-generated by ops.py on 2014-03-17 12:08
//



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include  "ops_lib_cpp.h"

//
// ops_par_loop declarations
//

void ops_par_loop_advec_mom_kernel_x1(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_advec_mom_kernel_y1(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_advec_mom_kernel_x2(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_advec_mom_kernel_y2(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_advec_mom_kernel_mass_flux_x(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_advec_mom_kernel_post_pre_advec_x(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_advec_mom_kernel1_x_nonvector(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_advec_mom_kernel2_x(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_advec_mom_kernel_mass_flux_y(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_advec_mom_kernel_post_pre_advec_y(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_advec_mom_kernel1_y_nonvector(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_advec_mom_kernel2_y(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );



#include "data.h"
#include "definitions.h"
//#include "advec_mom_kernel.h"

void advec_mom(int which_vel, int sweep_number, int dir)
{

  int x_cells = grid->x_cells;
  int y_cells = grid->y_cells;
  int x_min = field->x_min;
  int x_max = field->x_max;
  int y_min = field->y_min;
  int y_max = field->y_max;

  int rangexy[] = {x_min-2,x_max+2,y_min-2,y_max+2};

  int mom_sweep;
  ops_dat vel1;

  if( which_vel == 1) {
    vel1 = xvel1;
  }
  else {
    vel1 = yvel1;
  }

  mom_sweep = dir + 2*(sweep_number-1);


  if(mom_sweep == 1) {
      ops_par_loop_advec_mom_kernel_x1("advec_mom_kernel_x1", clover_grid, 2, rangexy,
                   ops_arg_dat(work_array6, S2D_00, "double", OPS_WRITE),
                   ops_arg_dat(work_array7, S2D_00, "double", OPS_WRITE),
                   ops_arg_dat(volume, S2D_00, "double", OPS_READ),
                   ops_arg_dat(vol_flux_x, S2D_00_P10, "double", OPS_READ),
                   ops_arg_dat(vol_flux_y, S2D_00_0P1, "double", OPS_READ));
  }
  else if(mom_sweep == 2) {
    ops_par_loop_advec_mom_kernel_y1("advec_mom_kernel_y1", clover_grid, 2, rangexy,
                 ops_arg_dat(work_array6, S2D_00, "double", OPS_WRITE),
                 ops_arg_dat(work_array7, S2D_00, "double", OPS_WRITE),
                 ops_arg_dat(volume, S2D_00, "double", OPS_READ),
                 ops_arg_dat(vol_flux_x, S2D_00_P10, "double", OPS_READ),
                 ops_arg_dat(vol_flux_y, S2D_00_0P1, "double", OPS_READ));
  }
  else if (mom_sweep == 3) {
    ops_par_loop_advec_mom_kernel_x2("advec_mom_kernel_x2", clover_grid, 2, rangexy,
                 ops_arg_dat(work_array6, S2D_00, "double", OPS_WRITE),
                 ops_arg_dat(work_array7, S2D_00, "double", OPS_WRITE),
                 ops_arg_dat(volume, S2D_00, "double", OPS_READ),
                 ops_arg_dat(vol_flux_y, S2D_00_0P1, "double", OPS_READ));
  }
  else if (mom_sweep == 4) {
    ops_par_loop_advec_mom_kernel_y2("advec_mom_kernel_y2", clover_grid, 2, rangexy,
                 ops_arg_dat(work_array6, S2D_00, "double", OPS_WRITE),
                 ops_arg_dat(work_array7, S2D_00, "double", OPS_WRITE),
                 ops_arg_dat(volume, S2D_00, "double", OPS_READ),
                 ops_arg_dat(vol_flux_x, S2D_00_P10, "double", OPS_READ));
  }

  int range_fullx_party_1[] = {x_min-2,x_max+2,y_min,y_max+1};
  int range_partx_party_1[] = {x_min-1,x_max+2,y_min,y_max+1};

  int range_fully_party_1[] = {x_min,x_max+1,y_min-2,y_max+2};
  int range_partx_party_2[] = {x_min,x_max+1,y_min-1,y_max+2};

  if (dir == 1) {

    ops_par_loop_advec_mom_kernel_mass_flux_x("advec_mom_kernel_mass_flux_x", clover_grid, 2, range_fullx_party_1,
                 ops_arg_dat(work_array1, S2D_00, "double", OPS_WRITE),
                 ops_arg_dat(mass_flux_x, S2D_00_P10_0M1_P1M1, "double", OPS_READ));

    ops_par_loop_advec_mom_kernel_post_pre_advec_x("advec_mom_kernel_post_pre_advec_x", clover_grid, 2, range_partx_party_1,
                 ops_arg_dat(work_array2, S2D_00, "double", OPS_WRITE),
                 ops_arg_dat(work_array7, S2D_00_M10_0M1_M1M1, "double", OPS_READ),
                 ops_arg_dat(density1, S2D_00_M10_0M1_M1M1, "double", OPS_READ),
                 ops_arg_dat(work_array3, S2D_00, "double", OPS_WRITE),
                 ops_arg_dat(work_array1, S2D_00_M10, "double", OPS_READ));

    int range_plus1xy_minus1x[] = {x_min-1,x_max+1,y_min,y_max+1};
    ops_par_loop_advec_mom_kernel1_x_nonvector("advec_mom_kernel1_x", clover_grid, 2, range_plus1xy_minus1x,
                 ops_arg_dat(work_array1, S2D_00, "double", OPS_READ),
                 ops_arg_dat(work_array3, S2D_00_P10, "double", OPS_READ),
                 ops_arg_dat(work_array5, S2D_00, "double", OPS_WRITE),
                 ops_arg_dat(celldx, S2D_00_P10_M10_M20_STRID2D_X, "double", OPS_READ),
                 ops_arg_dat(vel1, S2D_00_P10_P20_M10, "double", OPS_READ));

    int range_partx_party_2[] = {x_min,x_max+1,y_min,y_max+1};
    ops_par_loop_advec_mom_kernel2_x("advec_mom_kernel2_x", clover_grid, 2, range_partx_party_2,
                 ops_arg_dat(vel1, S2D_00, "double", OPS_RW),
                 ops_arg_dat(work_array2, S2D_00, "double", OPS_READ),
                 ops_arg_dat(work_array3, S2D_00, "double", OPS_READ),
                 ops_arg_dat(work_array5, S2D_00_M10, "double", OPS_READ));
  }
  else if (dir == 2) {

    ops_par_loop_advec_mom_kernel_mass_flux_y("advec_mom_kernel_mass_flux_y", clover_grid, 2, range_fully_party_1,
                 ops_arg_dat(work_array1, S2D_00, "double", OPS_WRITE),
                 ops_arg_dat(mass_flux_y, S2D_00_0P1_M10_M1P1, "double", OPS_READ));

    ops_par_loop_advec_mom_kernel_post_pre_advec_y("advec_mom_kernel_post_pre_advec_y", clover_grid, 2, range_partx_party_2,
                 ops_arg_dat(work_array2, S2D_00, "double", OPS_WRITE),
                 ops_arg_dat(work_array7, S2D_00_M10_0M1_M1M1, "double", OPS_READ),
                 ops_arg_dat(density1, S2D_00_M10_0M1_M1M1, "double", OPS_READ),
                 ops_arg_dat(work_array3, S2D_00, "double", OPS_WRITE),
                 ops_arg_dat(work_array1, S2D_00_0M1, "double", OPS_READ));

    int range_plus1xy_minus1y[] = {x_min,x_max+1,y_min-1,y_max+1};
    ops_par_loop_advec_mom_kernel1_y_nonvector("advec_mom_kernel1_y", clover_grid, 2, range_plus1xy_minus1y,
                 ops_arg_dat(work_array1, S2D_00, "double", OPS_READ),
                 ops_arg_dat(work_array3, S2D_00_0P1, "double", OPS_READ),
                 ops_arg_dat(work_array5, S2D_00, "double", OPS_WRITE),
                 ops_arg_dat(celldy, S2D_00_0P1_0M1_0M2_STRID2D_Y, "double", OPS_READ),
                 ops_arg_dat(vel1, S2D_00_0P1_0P2_0M1, "double", OPS_READ));

    int range_partx_party_2[] = {x_min,x_max+1,y_min,y_max+1};
    ops_par_loop_advec_mom_kernel2_y("advec_mom_kernel2_y", clover_grid, 2, range_partx_party_2,
                 ops_arg_dat(vel1, S2D_00, "double", OPS_RW),
                 ops_arg_dat(work_array2, S2D_00, "double", OPS_READ),
                 ops_arg_dat(work_array3, S2D_00, "double", OPS_READ),
                 ops_arg_dat(work_array5, S2D_00_0M1, "double", OPS_READ));

  }

}

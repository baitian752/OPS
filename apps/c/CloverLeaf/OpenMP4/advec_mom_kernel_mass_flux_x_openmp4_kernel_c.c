//
// auto-generated by ops.py
//
#include "./OpenMP4/clover_leaf_common.h"

#define OPS_GPU

extern int xdim0_advec_mom_kernel_mass_flux_x;
extern int xdim1_advec_mom_kernel_mass_flux_x;

#undef OPS_ACC0
#undef OPS_ACC1

#define OPS_ACC0(x, y) (x + xdim0_advec_mom_kernel_mass_flux_x * (y))
#define OPS_ACC1(x, y) (x + xdim1_advec_mom_kernel_mass_flux_x * (y))

// user function

void advec_mom_kernel_mass_flux_x_c_wrapper(double *p_a0, int base0, int tot0,
                                            double *p_a1, int base1, int tot1,
                                            int x_size, int y_size) {
  int num_blocks = round(((double)x_size * (double)y_size) / 128);
#pragma omp target enter data map(to : p_a0[0 : tot0], p_a1[0 : tot1])
#ifdef OPS_GPU

#pragma omp target map(to : p_a0[0 : tot0], p_a1[0 : tot1])
#pragma omp teams num_teams(num_blocks) thread_limit(128)
#pragma omp distribute parallel for simd collapse(2) schedule(static, 1)
#endif
  for (int n_y = 0; n_y < y_size; n_y++) {
#ifdef OPS_GPU
#endif
    for (int n_x = 0; n_x < x_size; n_x++) {
      double *node_flux = p_a0 + base0 + n_x * 1 * 1 +
                          n_y * xdim0_advec_mom_kernel_mass_flux_x * 1 * 1;

      const double *mass_flux_x =
          p_a1 + base1 + n_x * 1 * 1 +
          n_y * xdim1_advec_mom_kernel_mass_flux_x * 1 * 1;

      node_flux[OPS_ACC0(0, 0)] =
          0.25 * (mass_flux_x[OPS_ACC1(0, -1)] + mass_flux_x[OPS_ACC1(0, 0)] +
                  mass_flux_x[OPS_ACC1(1, -1)] + mass_flux_x[OPS_ACC1(1, 0)]);
    }
  }
}
#undef OPS_ACC0
#undef OPS_ACC1

//
// auto-generated by ops.py
//
#include "./OpenMP4/clover_leaf_common.h"

#define OPS_GPU

extern int xdim0_PdV_kernel_nopredict;
extern int ydim0_PdV_kernel_nopredict;
extern int xdim1_PdV_kernel_nopredict;
extern int ydim1_PdV_kernel_nopredict;
extern int xdim2_PdV_kernel_nopredict;
extern int ydim2_PdV_kernel_nopredict;
extern int xdim3_PdV_kernel_nopredict;
extern int ydim3_PdV_kernel_nopredict;
extern int xdim4_PdV_kernel_nopredict;
extern int ydim4_PdV_kernel_nopredict;
extern int xdim5_PdV_kernel_nopredict;
extern int ydim5_PdV_kernel_nopredict;
extern int xdim6_PdV_kernel_nopredict;
extern int ydim6_PdV_kernel_nopredict;
extern int xdim7_PdV_kernel_nopredict;
extern int ydim7_PdV_kernel_nopredict;
extern int xdim8_PdV_kernel_nopredict;
extern int ydim8_PdV_kernel_nopredict;
extern int xdim9_PdV_kernel_nopredict;
extern int ydim9_PdV_kernel_nopredict;
extern int xdim10_PdV_kernel_nopredict;
extern int ydim10_PdV_kernel_nopredict;
extern int xdim11_PdV_kernel_nopredict;
extern int ydim11_PdV_kernel_nopredict;
extern int xdim12_PdV_kernel_nopredict;
extern int ydim12_PdV_kernel_nopredict;
extern int xdim13_PdV_kernel_nopredict;
extern int ydim13_PdV_kernel_nopredict;
extern int xdim14_PdV_kernel_nopredict;
extern int ydim14_PdV_kernel_nopredict;
extern int xdim15_PdV_kernel_nopredict;
extern int ydim15_PdV_kernel_nopredict;
extern int xdim16_PdV_kernel_nopredict;
extern int ydim16_PdV_kernel_nopredict;

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
#undef OPS_ACC11
#undef OPS_ACC12
#undef OPS_ACC13
#undef OPS_ACC14
#undef OPS_ACC15
#undef OPS_ACC16

#define OPS_ACC0(x, y, z)                                                      \
  (x + xdim0_PdV_kernel_nopredict * (y) +                                      \
   xdim0_PdV_kernel_nopredict * ydim0_PdV_kernel_nopredict * (z))
#define OPS_ACC1(x, y, z)                                                      \
  (x + xdim1_PdV_kernel_nopredict * (y) +                                      \
   xdim1_PdV_kernel_nopredict * ydim1_PdV_kernel_nopredict * (z))
#define OPS_ACC2(x, y, z)                                                      \
  (x + xdim2_PdV_kernel_nopredict * (y) +                                      \
   xdim2_PdV_kernel_nopredict * ydim2_PdV_kernel_nopredict * (z))
#define OPS_ACC3(x, y, z)                                                      \
  (x + xdim3_PdV_kernel_nopredict * (y) +                                      \
   xdim3_PdV_kernel_nopredict * ydim3_PdV_kernel_nopredict * (z))
#define OPS_ACC4(x, y, z)                                                      \
  (x + xdim4_PdV_kernel_nopredict * (y) +                                      \
   xdim4_PdV_kernel_nopredict * ydim4_PdV_kernel_nopredict * (z))
#define OPS_ACC5(x, y, z)                                                      \
  (x + xdim5_PdV_kernel_nopredict * (y) +                                      \
   xdim5_PdV_kernel_nopredict * ydim5_PdV_kernel_nopredict * (z))
#define OPS_ACC6(x, y, z)                                                      \
  (x + xdim6_PdV_kernel_nopredict * (y) +                                      \
   xdim6_PdV_kernel_nopredict * ydim6_PdV_kernel_nopredict * (z))
#define OPS_ACC7(x, y, z)                                                      \
  (x + xdim7_PdV_kernel_nopredict * (y) +                                      \
   xdim7_PdV_kernel_nopredict * ydim7_PdV_kernel_nopredict * (z))
#define OPS_ACC8(x, y, z)                                                      \
  (x + xdim8_PdV_kernel_nopredict * (y) +                                      \
   xdim8_PdV_kernel_nopredict * ydim8_PdV_kernel_nopredict * (z))
#define OPS_ACC9(x, y, z)                                                      \
  (x + xdim9_PdV_kernel_nopredict * (y) +                                      \
   xdim9_PdV_kernel_nopredict * ydim9_PdV_kernel_nopredict * (z))
#define OPS_ACC10(x, y, z)                                                     \
  (x + xdim10_PdV_kernel_nopredict * (y) +                                     \
   xdim10_PdV_kernel_nopredict * ydim10_PdV_kernel_nopredict * (z))
#define OPS_ACC11(x, y, z)                                                     \
  (x + xdim11_PdV_kernel_nopredict * (y) +                                     \
   xdim11_PdV_kernel_nopredict * ydim11_PdV_kernel_nopredict * (z))
#define OPS_ACC12(x, y, z)                                                     \
  (x + xdim12_PdV_kernel_nopredict * (y) +                                     \
   xdim12_PdV_kernel_nopredict * ydim12_PdV_kernel_nopredict * (z))
#define OPS_ACC13(x, y, z)                                                     \
  (x + xdim13_PdV_kernel_nopredict * (y) +                                     \
   xdim13_PdV_kernel_nopredict * ydim13_PdV_kernel_nopredict * (z))
#define OPS_ACC14(x, y, z)                                                     \
  (x + xdim14_PdV_kernel_nopredict * (y) +                                     \
   xdim14_PdV_kernel_nopredict * ydim14_PdV_kernel_nopredict * (z))
#define OPS_ACC15(x, y, z)                                                     \
  (x + xdim15_PdV_kernel_nopredict * (y) +                                     \
   xdim15_PdV_kernel_nopredict * ydim15_PdV_kernel_nopredict * (z))
#define OPS_ACC16(x, y, z)                                                     \
  (x + xdim16_PdV_kernel_nopredict * (y) +                                     \
   xdim16_PdV_kernel_nopredict * ydim16_PdV_kernel_nopredict * (z))

// user function

void PdV_kernel_nopredict_c_wrapper(
    double *p_a0, int base0, int tot0, double *p_a1, int base1, int tot1,
    double *p_a2, int base2, int tot2, double *p_a3, int base3, int tot3,
    double *p_a4, int base4, int tot4, double *p_a5, int base5, int tot5,
    double *p_a6, int base6, int tot6, double *p_a7, int base7, int tot7,
    double *p_a8, int base8, int tot8, double *p_a9, int base9, int tot9,
    double *p_a10, int base10, int tot10, double *p_a11, int base11, int tot11,
    double *p_a12, int base12, int tot12, double *p_a13, int base13, int tot13,
    double *p_a14, int base14, int tot14, double *p_a15, int base15, int tot15,
    double *p_a16, int base16, int tot16, int x_size, int y_size, int z_size) {
#ifdef OPS_GPU

#pragma omp target teams distribute parallel for num_teams(OPS_threads)        \
    thread_limit(OPS_threads_for_block) collapse(3) schedule(static, 1)
#endif
  for (int n_z = 0; n_z < z_size; n_z++) {
    for (int n_y = 0; n_y < y_size; n_y++) {
      for (int n_x = 0; n_x < x_size; n_x++) {
        const double *xarea =
            p_a0 + base0 + n_x * 1 * 1 +
            n_y * xdim0_PdV_kernel_nopredict * 1 * 1 +
            n_z * xdim0_PdV_kernel_nopredict * ydim0_PdV_kernel_nopredict * 1;

        const double *xvel0 =
            p_a1 + base1 + n_x * 1 * 1 +
            n_y * xdim1_PdV_kernel_nopredict * 1 * 1 +
            n_z * xdim1_PdV_kernel_nopredict * ydim1_PdV_kernel_nopredict * 1;

        const double *xvel1 =
            p_a2 + base2 + n_x * 1 * 1 +
            n_y * xdim2_PdV_kernel_nopredict * 1 * 1 +
            n_z * xdim2_PdV_kernel_nopredict * ydim2_PdV_kernel_nopredict * 1;

        const double *yarea =
            p_a3 + base3 + n_x * 1 * 1 +
            n_y * xdim3_PdV_kernel_nopredict * 1 * 1 +
            n_z * xdim3_PdV_kernel_nopredict * ydim3_PdV_kernel_nopredict * 1;

        const double *yvel0 =
            p_a4 + base4 + n_x * 1 * 1 +
            n_y * xdim4_PdV_kernel_nopredict * 1 * 1 +
            n_z * xdim4_PdV_kernel_nopredict * ydim4_PdV_kernel_nopredict * 1;

        const double *yvel1 =
            p_a5 + base5 + n_x * 1 * 1 +
            n_y * xdim5_PdV_kernel_nopredict * 1 * 1 +
            n_z * xdim5_PdV_kernel_nopredict * ydim5_PdV_kernel_nopredict * 1;

        double *volume_change =
            p_a6 + base6 + n_x * 1 * 1 +
            n_y * xdim6_PdV_kernel_nopredict * 1 * 1 +
            n_z * xdim6_PdV_kernel_nopredict * ydim6_PdV_kernel_nopredict * 1;

        const double *volume =
            p_a7 + base7 + n_x * 1 * 1 +
            n_y * xdim7_PdV_kernel_nopredict * 1 * 1 +
            n_z * xdim7_PdV_kernel_nopredict * ydim7_PdV_kernel_nopredict * 1;

        const double *pressure =
            p_a8 + base8 + n_x * 1 * 1 +
            n_y * xdim8_PdV_kernel_nopredict * 1 * 1 +
            n_z * xdim8_PdV_kernel_nopredict * ydim8_PdV_kernel_nopredict * 1;

        const double *density0 =
            p_a9 + base9 + n_x * 1 * 1 +
            n_y * xdim9_PdV_kernel_nopredict * 1 * 1 +
            n_z * xdim9_PdV_kernel_nopredict * ydim9_PdV_kernel_nopredict * 1;

        double *density1 =
            p_a10 + base10 + n_x * 1 * 1 +
            n_y * xdim10_PdV_kernel_nopredict * 1 * 1 +
            n_z * xdim10_PdV_kernel_nopredict * ydim10_PdV_kernel_nopredict * 1;

        const double *viscosity =
            p_a11 + base11 + n_x * 1 * 1 +
            n_y * xdim11_PdV_kernel_nopredict * 1 * 1 +
            n_z * xdim11_PdV_kernel_nopredict * ydim11_PdV_kernel_nopredict * 1;

        const double *energy0 =
            p_a12 + base12 + n_x * 1 * 1 +
            n_y * xdim12_PdV_kernel_nopredict * 1 * 1 +
            n_z * xdim12_PdV_kernel_nopredict * ydim12_PdV_kernel_nopredict * 1;

        double *energy1 =
            p_a13 + base13 + n_x * 1 * 1 +
            n_y * xdim13_PdV_kernel_nopredict * 1 * 1 +
            n_z * xdim13_PdV_kernel_nopredict * ydim13_PdV_kernel_nopredict * 1;

        const double *zarea =
            p_a14 + base14 + n_x * 1 * 1 +
            n_y * xdim14_PdV_kernel_nopredict * 1 * 1 +
            n_z * xdim14_PdV_kernel_nopredict * ydim14_PdV_kernel_nopredict * 1;

        const double *zvel0 =
            p_a15 + base15 + n_x * 1 * 1 +
            n_y * xdim15_PdV_kernel_nopredict * 1 * 1 +
            n_z * xdim15_PdV_kernel_nopredict * ydim15_PdV_kernel_nopredict * 1;

        const double *zvel1 =
            p_a16 + base16 + n_x * 1 * 1 +
            n_y * xdim16_PdV_kernel_nopredict * 1 * 1 +
            n_z * xdim16_PdV_kernel_nopredict * ydim16_PdV_kernel_nopredict * 1;

        double recip_volume, energy_change;
        double right_flux, left_flux, top_flux, bottom_flux, back_flux,
            front_flux, total_flux;

        left_flux = (xarea[OPS_ACC0(0, 0, 0)] *
                     (xvel0[OPS_ACC1(0, 0, 0)] + xvel0[OPS_ACC1(0, 1, 0)] +
                      xvel0[OPS_ACC1(0, 0, 1)] + xvel0[OPS_ACC1(0, 1, 1)] +
                      xvel1[OPS_ACC2(0, 0, 0)] + xvel1[OPS_ACC2(0, 1, 0)] +
                      xvel1[OPS_ACC2(0, 0, 1)] + xvel1[OPS_ACC2(0, 1, 1)])) *
                    0.125 * dt;
        right_flux = (xarea[OPS_ACC0(1, 0, 0)] *
                      (xvel0[OPS_ACC1(1, 0, 0)] + xvel0[OPS_ACC1(1, 1, 0)] +
                       xvel0[OPS_ACC1(1, 0, 1)] + xvel0[OPS_ACC1(1, 1, 1)] +
                       xvel1[OPS_ACC2(1, 0, 0)] + xvel1[OPS_ACC2(1, 1, 0)] +
                       xvel1[OPS_ACC2(1, 0, 1)] + xvel1[OPS_ACC2(1, 1, 1)])) *
                     0.125 * dt;

        bottom_flux = (yarea[OPS_ACC3(0, 0, 0)] *
                       (yvel0[OPS_ACC4(0, 0, 0)] + yvel0[OPS_ACC4(1, 0, 0)] +
                        yvel0[OPS_ACC4(0, 0, 1)] + yvel0[OPS_ACC4(1, 0, 1)] +
                        yvel1[OPS_ACC5(0, 0, 0)] + yvel1[OPS_ACC5(1, 0, 0)] +
                        yvel1[OPS_ACC5(0, 0, 1)] + yvel1[OPS_ACC5(1, 0, 1)])) *
                      0.125 * dt;
        top_flux = (yarea[OPS_ACC3(0, 1, 0)] *
                    (yvel0[OPS_ACC4(0, 1, 0)] + yvel0[OPS_ACC4(1, 1, 0)] +
                     yvel0[OPS_ACC4(0, 1, 1)] + yvel0[OPS_ACC4(1, 1, 1)] +
                     yvel1[OPS_ACC5(0, 1, 0)] + yvel1[OPS_ACC5(1, 1, 0)] +
                     yvel1[OPS_ACC5(0, 1, 1)] + yvel1[OPS_ACC5(1, 1, 1)])) *
                   0.125 * dt;

        back_flux = (zarea[OPS_ACC14(0, 0, 0)] *
                     (zvel0[OPS_ACC15(0, 0, 0)] + zvel0[OPS_ACC15(1, 0, 0)] +
                      zvel0[OPS_ACC15(0, 1, 0)] + zvel0[OPS_ACC15(1, 1, 0)] +
                      zvel1[OPS_ACC16(0, 0, 0)] + zvel1[OPS_ACC16(1, 0, 0)] +
                      zvel1[OPS_ACC16(0, 1, 0)] + zvel1[OPS_ACC16(1, 1, 0)])) *
                    0.125 * dt;
        front_flux = (zarea[OPS_ACC14(0, 0, 1)] *
                      (zvel0[OPS_ACC15(0, 0, 1)] + zvel0[OPS_ACC15(1, 0, 1)] +
                       zvel0[OPS_ACC15(0, 1, 1)] + zvel0[OPS_ACC15(1, 1, 1)] +
                       zvel1[OPS_ACC16(0, 0, 1)] + zvel1[OPS_ACC16(1, 0, 1)] +
                       zvel1[OPS_ACC16(0, 1, 1)] + zvel1[OPS_ACC16(1, 1, 1)])) *
                     0.125 * dt;

        total_flux = right_flux - left_flux + top_flux - bottom_flux +
                     front_flux - back_flux;

        volume_change[OPS_ACC6(0, 0, 0)] =
            (volume[OPS_ACC7(0, 0, 0)]) /
            (volume[OPS_ACC7(0, 0, 0)] + total_flux);
        recip_volume = 1.0 / volume[OPS_ACC7(0, 0, 0)];
        energy_change =
            (pressure[OPS_ACC8(0, 0, 0)] / density0[OPS_ACC9(0, 0, 0)] +
             viscosity[OPS_ACC11(0, 0, 0)] / density0[OPS_ACC9(0, 0, 0)]) *
            total_flux * recip_volume;
        energy1[OPS_ACC13(0, 0, 0)] =
            energy0[OPS_ACC12(0, 0, 0)] - energy_change;
        density1[OPS_ACC10(0, 0, 0)] =
            density0[OPS_ACC9(0, 0, 0)] * volume_change[OPS_ACC6(0, 0, 0)];
      }
    }
  }
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
#undef OPS_ACC11
#undef OPS_ACC12
#undef OPS_ACC13
#undef OPS_ACC14
#undef OPS_ACC15
#undef OPS_ACC16
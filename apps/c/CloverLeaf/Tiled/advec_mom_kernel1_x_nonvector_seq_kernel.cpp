//
// auto-generated by ops.py
//
#define OPS_ACC0(x, y)                                                         \
  (n_x * 1 + n_y * xdim0_advec_mom_kernel1_x_nonvector * 1 + x +               \
   xdim0_advec_mom_kernel1_x_nonvector * (y))
#define OPS_ACC1(x, y)                                                         \
  (n_x * 1 + n_y * xdim1_advec_mom_kernel1_x_nonvector * 1 + x +               \
   xdim1_advec_mom_kernel1_x_nonvector * (y))
#define OPS_ACC2(x, y)                                                         \
  (n_x * 1 + n_y * xdim2_advec_mom_kernel1_x_nonvector * 1 + x +               \
   xdim2_advec_mom_kernel1_x_nonvector * (y))
#define OPS_ACC3(x, y)                                                         \
  (n_x * 1 + n_y * xdim3_advec_mom_kernel1_x_nonvector * 0 + x +               \
   xdim3_advec_mom_kernel1_x_nonvector * (y))
#define OPS_ACC4(x, y)                                                         \
  (n_x * 1 + n_y * xdim4_advec_mom_kernel1_x_nonvector * 1 + x +               \
   xdim4_advec_mom_kernel1_x_nonvector * (y))

// user function

// host stub function
void ops_par_loop_advec_mom_kernel1_x_nonvector_execute(
    ops_kernel_descriptor *desc) {
  ops_block block = desc->block;
  int dim = desc->dim;
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  ops_arg arg3 = desc->args[3];
  ops_arg arg4 = desc->args[4];

  // Timing
  double t1, t2, c1, c2;

  ops_arg args[5] = {arg0, arg1, arg2, arg3, arg4};

#ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args, 5, range, 21))
    return;
#endif

  if (OPS_diags > 1) {
    OPS_kernels[21].count++;
    ops_timers_core(&c2, &t2);
  }

  // compute locally allocated range for the sub-block
  int start[2];
  int end[2];

  for (int n = 0; n < 2; n++) {
    start[n] = range[2 * n];
    end[n] = range[2 * n + 1];
  }

#ifdef OPS_DEBUG
  ops_register_args(args, "advec_mom_kernel1_x_nonvector");
#endif

  // set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  const double *__restrict__ node_flux = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset;
  const double *__restrict__ node_mass_pre = (double *)(args[1].data + base1);

  int base2 = args[2].dat->base_offset;
  double *__restrict__ mom_flux = (double *)(args[2].data + base2);

  int base3 = args[3].dat->base_offset;
  const double *__restrict__ celldx = (double *)(args[3].data + base3);

  int base4 = args[4].dat->base_offset;
  const double *__restrict__ vel1 = (double *)(args[4].data + base4);

  // initialize global variable with the dimension of dats
  int xdim0_advec_mom_kernel1_x_nonvector = args[0].dat->size[0];
  int xdim1_advec_mom_kernel1_x_nonvector = args[1].dat->size[0];
  int xdim2_advec_mom_kernel1_x_nonvector = args[2].dat->size[0];
  int xdim3_advec_mom_kernel1_x_nonvector = args[3].dat->size[0];
  int xdim4_advec_mom_kernel1_x_nonvector = args[4].dat->size[0];

  if (OPS_diags > 1) {
    ops_timers_core(&c1, &t1);
    OPS_kernels[21].mpi_time += t1 - t2;
  }

#pragma omp parallel for
  for (int n_y = start[1]; n_y < end[1]; n_y++) {
#ifdef intel
#pragma loop_count(10000)
#pragma omp simd aligned(node_flux, node_mass_pre, mom_flux, celldx, vel1)
#else
#pragma simd
#endif
    for (int n_x = start[0]; n_x < end[0]; n_x++) {

      double sigma, wind, width;
      double vdiffuw, vdiffdw, auw, adw, limiter;
      int upwind, donor, downwind, dif;

      double advec_vel_temp;

      if ((node_flux[OPS_ACC0(0, 0)]) < 0.0) {
        upwind = 2;
        donor = 1;
        downwind = 0;
        dif = donor;
      } else {
        upwind = -1;
        donor = 0;
        downwind = 1;
        dif = upwind;
      }

      sigma =
          fabs(node_flux[OPS_ACC0(0, 0)]) / node_mass_pre[OPS_ACC1(donor, 0)];

      width = celldx[OPS_ACC3(0, 0)];
      vdiffuw = vel1[OPS_ACC4(donor, 0)] - vel1[OPS_ACC4(upwind, 0)];
      vdiffdw = vel1[OPS_ACC4(downwind, 0)] - vel1[OPS_ACC4(donor, 0)];
      limiter = 0.0;

      if (vdiffuw * vdiffdw > 0.0) {
        auw = fabs(vdiffuw);
        adw = fabs(vdiffdw);
        wind = 1.0;
        if (vdiffdw <= 0.0)
          wind = -1.0;
        limiter = wind *
                  MIN(width * ((2.0 - sigma) * adw / width +
                               (1.0 + sigma) * auw / celldx[OPS_ACC3(dif, 0)]) /
                          6.0,
                      MIN(auw, adw));
      }

      advec_vel_temp = vel1[OPS_ACC4(donor, 0)] + (1.0 - sigma) * limiter;
      mom_flux[OPS_ACC2(0, 0)] = advec_vel_temp * node_flux[OPS_ACC0(0, 0)];
    }
  }
  if (OPS_diags > 1) {
    ops_timers_core(&c2, &t2);
    OPS_kernels[21].time += t2 - t1;
  }

  if (OPS_diags > 1) {
    // Update kernel record
    ops_timers_core(&c1, &t1);
    OPS_kernels[21].mpi_time += t1 - t2;
    OPS_kernels[21].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[21].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[21].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_kernels[21].transfer += ops_compute_transfer(dim, start, end, &arg3);
    OPS_kernels[21].transfer += ops_compute_transfer(dim, start, end, &arg4);
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4

void ops_par_loop_advec_mom_kernel1_x_nonvector(char const *name,
                                                ops_block block, int dim,
                                                int *range, ops_arg arg0,
                                                ops_arg arg1, ops_arg arg2,
                                                ops_arg arg3, ops_arg arg4) {
  ops_kernel_descriptor *desc =
      (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 21;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 21;
  for (int i = 0; i < 4; i++) {
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 5;
  desc->args = (ops_arg *)malloc(5 * sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg1.dat->index;
  desc->args[2] = arg2;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg2.dat->index;
  desc->args[3] = arg3;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg3.dat->index;
  desc->args[4] = arg4;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg4.dat->index;
  desc->function = ops_par_loop_advec_mom_kernel1_x_nonvector_execute;
  if (OPS_diags > 1) {
    ops_timing_realloc(21, "advec_mom_kernel1_x_nonvector");
  }
  ops_enqueue_kernel(desc);
}

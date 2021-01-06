# pp4fpga_FIR

# baseline and pipeline
open_project FIR
set_top fir
add_files fir.c
add_files -tb fir_test.c
open_solution "baseline"
set_part {xc7z020clg484-1}
create_clock -period 10 -name default
csim_design -clean
csynth_design

open_solution "baseline_pipeline"
set_part {xc7z020clg484-1}
create_clock -period 10 -name default
set_directive_pipeline -II 1 "fir/Shift_Accum_Loop"
csynth_design

close_project


# hoisted and pipeline
open_project FIR_hoist
set_top fir
add_files fir_hoist.c
add_files -tb fir_test.c
open_solution "hoisted"
set_part {xc7z020clg484-1}
create_clock -period 10 -name default
csim_design -clean
csynth_design

open_solution "hoisted_pipeline"
set_part {xc7z020clg484-1}
create_clock -period 10 -name default
set_directive_pipeline -II 1 "fir/Shift_Accum_Loop"
csynth_design

close_project
cmake_minimum_required (VERSION 3.8)

project (sgslave CXX)
my_find_src_files (src_files sgslave)
add_executable (sgslave ${src_files})
my_add_compile_options (sgslave)
my_add_pch (sgslave)

my_inc_import_RisLib(sgslave)
my_inc_import_CommonLib(sgslave)

my_lib_import_CommonLib(sgslave)
my_lib_import_RisLib(sgslave)

my_post_build_bin(sgslave)

cmake_minimum_required (VERSION 3.8)

project (usbslave CXX)
my_find_src_files (src_files usbslave)
add_executable (usbslave ${src_files})
my_add_compile_options (usbslave)
my_add_pch (usbslave)

my_inc_import_RisLib(usbslave)
my_inc_import_CommonLib(usbslave)

my_lib_import_CommonLib(usbslave)
my_lib_import_RisLib(usbslave)

my_post_build_bin(usbslave)

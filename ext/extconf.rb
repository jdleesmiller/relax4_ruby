require 'mkmf'

have_header('f2c.h') or raise 'You must install f2c (FORTRAN to C).'

# This is slightly nonstandard, because f2c always inserts a function MAIN__
# into the translated source, and it won't link unless this function is present.
have_library('f2c','e_rsle') {|src|
  src += "\nint MAIN__(void){ }\n"
} or raise 'You must install f2c (FORTRAN to C converter).'

create_makefile("relax4")

%module relax4

%{
#include "f2c.h"
#include "relax4.h"
%}

/* Basic wrapper for the C array parameters.*/
%include carrays.i

/* Swig needs some things from the f2c header, but Swig can't parse it
   (swig 2.0.0 with f2c version 20090411). So, I've just included the relevant
   bits here. */
#if defined(__alpha__) || defined(__sparc64__) || defined(__x86_64__) || defined(__ia64__)
typedef int integer;
typedef unsigned int uinteger;

/* It seems that array_class(integer, IntegerArray) doesn't work, so we do this
 * inside the conditional. */
%array_class(int, IntegerArray)

#else
typedef long int integer;
typedef unsigned long int uinteger;

/* It seems that array_class(integer, IntegerArray) doesn't work, so we do this
 * inside the conditional. */
%array_class(long int, IntegerArray)

#endif

%include "relax4.h"


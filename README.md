# Malloc Intercepter
malloc intercepter is a library to intercept all malloc calls in an application and output the number of bytes allocated so far after each malloc call.

## Setup
The project can be compiled into a shared library file using:
```
gcc malloc.c -shared -o malloc.so -fPIC -ldl
```
The generated library file `malloc.so` can be used by either running
```
LD_PRELOAD=/path/to/malloc.so program_name args
```
where `program_name args` is the aplliaction and its arguments for which you want the malloc calls to be intercepted. The alternative is to copy the file malloc.so to /usr/lib and run
```
ldconfig -n /usr/lib
```
to install the new library enabling the library to be used by calling:
```
LD_PRELOAD=malloc.so seq 1 5
```

## Example
Using the library to intercept malloc calls for the program `seq 1 5` will produce an output similar to this:

```
$ LD_PRELOAD=malloc.so seq 1 5
Total bytes allocated so far: 5
Total bytes allocated so far: 125
Total bytes allocated so far: 137
Total bytes allocated so far: 913
Total bytes allocated so far: 1025
Total bytes allocated so far: 2361
Total bytes allocated so far: 2577
Total bytes allocated so far: 3009
Total bytes allocated so far: 3113
Total bytes allocated so far: 3201
Total bytes allocated so far: 3321
Total bytes allocated so far: 3489
Total bytes allocated so far: 3593
Total bytes allocated so far: 3673
Total bytes allocated so far: 3865
Total bytes allocated so far: 3877
Total bytes allocated so far: 3889
Total bytes allocated so far: 3901
Total bytes allocated so far: 3913
Total bytes allocated so far: 3925
Total bytes allocated so far: 3937
Total bytes allocated so far: 3949
Total bytes allocated so far: 3961
Total bytes allocated so far: 3973
Total bytes allocated so far: 3985
Total bytes allocated so far: 3997
Total bytes allocated so far: 4009
Total bytes allocated so far: 4021
Total bytes allocated so far: 4055
Total bytes allocated so far: 4065
Total bytes allocated so far: 4097
Total bytes allocated so far: 4129
Total bytes allocated so far: 12321
Total bytes allocated so far: 13345
1
2
3
4
5
```


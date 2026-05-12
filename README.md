# FuncArg_Benchmarker
## Summary

C++ Benchmarking Application: Is it more efficient to pass a vector by-value or const-ref to a function?
This is obviously machine dependent.

## My Machine

* Architecture:                         x86_64
* CPU op-mode(s):                       32-bit, 64-bit
* Byte Order:                           Little Endian
* Address sizes:                        39 bits physical, 48 bits virtual
* CPU(s):                               8
* On-line CPU(s) list:                  0-7
* Thread(s) per core:                   2
* Core(s) per socket:                   4
* Socket(s):                            1
* NUMA node(s):                         1
* Vendor ID:                            GenuineIntel
* CPU family:                           6
* Model:                                140
* Model name:                           11th Gen Intel(R) Core(TM) i5-1135G7 @ 2.40GHz
* Stepping:                             1
* CPU MHz:                              3095.608
* CPU max MHz:                          4200.0000
* CPU min MHz:                          400.0000
* BogoMIPS:                             4838.40
* Virtualisation:                       VT-x
* L1d cache:                            192 KiB
* L1i cache:                            128 KiB
* L2 cache:                             5 MiB
* L3 cache:                             8 MiB
* NUMA node0 CPU(s):                    0-7

## Results

### Optimisation Level: -O2
- Vector size: 10000000
- Number of iterations: 20
- Pass-By-Value Pattern Time: 1.01961s
- Pass-By-Const-Reference Pattern Time: 0.247104s
- Passing a Vector by const-ref is 4.12624 times faster than by-value
- Final Result: 1e+07

## TODO
* Run at different optimisation levels: `-O0`, `-O1` & `-O3`.


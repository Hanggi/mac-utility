# Memory Detector

This is my Memory Detector to check out memory leak and free freed memory.

To see a better typesetting, can use markdown.


### How to use

I have made the Makefile for generating .so file and compiling the test files.

To generate the .so file:

```
$ make so
```

There are same files contain main function and some malloc/free calls that can test 3 normal cases.

They are test_leak.c(for test memory leak case), test_free.c(for test memory double freed or illegal free.) and test_pass.c(for every thing goes well), respectively.

To generate the executable files:

```
$ make test
```

At last, to run the test program, we can make test run, like:

```
$ make leak

$ make free

$ make pass
```

You can check the sorce file of test_free.c, test_leak.c, test_pass.c file.


The library may detect the malloc and free function, and report the results of detecting.

If there is a double free, you can see like:

> [ILLEGAL]This is a DOUBLE free! @: 0x90a060

And if there is a memory leak:

> [LEAK] No.2 Memory @ 0x12c306 didn't freed for size of 100!

Every thing passed:

> [PASS] Every memory managed well.

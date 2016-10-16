lib:
	gcc -fPIC -g -c mc.c -o memdetector.o
	gcc -fPIC -g -c memlist.c -o memlist.o
so:
	gcc -fPIC -g -c mc.c -o memdetector.o
	gcc -fPIC -g -c memlist.c -o memlist.o
	gcc -g -shared -Wl,-soname,libs.so -o libs.so memlist.o memdetector.o -lc

test:
	gcc -g main.c -o test -L. -ls -ldl
	gcc -g test_pass.c -o test_pass -L. -ls -ldl
	gcc -g test_leak.c -o test_leak -L. -ls -ldl
	gcc -g test_free.c -o test_free -L. -ls -ldl

go:
	LD_PRELOAD=./libs.so ./test
run:
	LD_PRELOAD=./libs.so ./test

leak:
	LD_PRELOAD=./libs.so ./test_leak
free:
	LD_PRELOAD=./libs.so ./test_free
pass:
	LD_PRELOAD=./libs.so ./test_pass

clean:
	rm libs.so memlist.o test test_pass test_leak test_free memdetector.o

cleanexe:
	rm test test_pass test_leak test_free

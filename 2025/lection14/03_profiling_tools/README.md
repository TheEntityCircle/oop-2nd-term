gprof basics:
=============
http://www.thegeekstuff.com/2012/08/gprof-tutorial/
```
make
./simple-demo
gprof simple-demo gmon.out
```

How profilers lie:
==================
http://yosefk.com/blog/how-profilers-lie-the-cases-of-gprof-and-kcachegrind.html
```
make
./not-so-simple-demo
gprof not-so-simple-demo gmon.out
```

```
valgrind --tool=callgrind ./not-so-simple-demo
kcachegrind callgrind.out.*
```

```
perf record -F 100 -g ./not-so-simple-demo
perf report --stdio
perf script | ./stackcollapse-perf.pl | ./flamegraph.pl > perf.svg
```

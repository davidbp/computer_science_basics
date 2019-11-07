## Terminal advanced commands on Linux


#### `perf`

https://developers.redhat.com/blog/2014/03/10/determining-whether-an-application-has-poor-cache-performance-2/

The command `perf` can be used to retrieve hardware metrics in linux based systems. 

We can do `perf stat -e list_of_metrics executable` to gather the metrics specified in `list_of_metrics` from a
program `executable`.

For example, if we want to gather metrics from a pyton script, we can do the following: 

```
perf stat -e task-clock,cycles,instructions,cache-references,cache-misses  python myscript.py
```

returns

```
 Performance counter stats for 'python myscript.py':

        229.872935 task-clock                #    0.996 CPUs utilized
       626,676,991 cycles                    #    2.726 GHz
       525,543,766 instructions              #    0.84  insns per cycle
        18,587,219 cache-references          #   80.859 M/sec
         6,605,955 cache-misses              #   35.540 % of all cache refs

       0.230761764 seconds time elapsed
```

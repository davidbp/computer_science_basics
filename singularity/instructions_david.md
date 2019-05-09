# How to use a Singularity file

### Create a container (similar to  creating an abstract class)

In order to build the singularity container described  in a `mydescriptor.singularity` file  we must do:

```
sudo singularity build name_of_image.simg mydescriptor.singularity
```

for example, if we want to build `bscdc_spark.singularity`:

```
sudo singularity build $HOME/singularity_images/spark_bscdc_david.simg bscdc_spark.singularity
```



### Create an instance of a container (similar to instantiating an object of a class)

```
singularity instance.start spark_bscdc_david.simg spark_instance
```



```
singularity instance.start $HOME/singularity_images/spark_bscdc_david.simg spark_instance
```



### Look the currently working instances

```
singularity instance.list
```

should print a list of the currently opened singularity isntances

```
DAEMON NAME      PID      CONTAINER IMAGE
spark_instance   13875    /home/david/Documents/bsc/nord3-spark/spark_bscdc_david.simg
```



### Going inside a singularity instance object

In order to open a terminal (shell) inside a singularity container you can use `singularity shell instance://name_of_your_instance`

For example:

```david@bsc-laptop:~/Documents/bsc/nord3-spark$ singularity shell instance://spark_instance
 singularity shell instance://spark_instance 
 Singularity: Invoking an interactive shell within container...
```

Once you are inside a container you will see `Singularity` on the left hand side of the terminal

```
Singularity spark_bscdc_david.simg:~/Documents/bsc/nord3-spark>
```



### Closing an opened instance

After finishing your work and exiting from a singularity container instance you can do `singularity instance.stop` 

```
singularity instance.stop spark_instance
```

should print a message similar to:

```
Stopping spark_instance instance of /home/david/Documents/bsc/nord3-spark/spark_bscdc_david.simg (PID=13875)
```



# Execute Spark  in Singularity



## Pyspark single node standalone

```
myfolder> singularity instance.start $HOME/singularity_images/spark_bscdc_david.simg spark_instance

myfolder>singularity shell instance://spark_instance 

# fails due to java heap space
Singularity myfolder>spark-submit 02_ml_LogisticRegression.py

Singularity myfolder>spark-submit --conf spark.executor.memory=120g --conf spark.driver.memory=4g 02_ml_LogisticRegression.py

Singularity myfolder>spark-submit --conf spark.executor.memory=120g --conf spark.driver.memory=4g 02_ml_LogisticRegression.py
```





## Pyspark cluster mode 

Now we will see how to manually start a spark master, how to start spark slave/s and how to submit a python script to the spark slave.

The core idea follows the following schema:

#### (1) Create spark master.

- The user has to specify  a port and the memory for the spark master.

Example

```
/opt/spark/sbin/start-master.sh -p 8765 
```

#### (2) Create a spark slave with the URL of the spark master. 

-  The user has to specify the memory for the spark slave and a folder to write temporary 

Example

```
/opt/spark/sbin/start-slave.sh spark://10.0.26.3:8765 -d /tmp/spark_tmp/ -m 100G  -c 40
/opt/spark/sbin/start-slave.sh spark://10.0.26.3:8765 -d /tmp/spark_tmp/ -m 100G  -c 40
```

Another way to start a slave:

```
/opt/spark/bin/spark-class org.apache.spark.deploy.worker.Worker spark://10.0.26.3:8765  -d /tmp/spark_tmp/ -m 100G  -c 40
```

#### (3) Create more slaves (go to (2)) or simply execute your application (go to (4))

```
/opt/spark/sbin/start-slave.sh spark://10.0.26.2:8765 -d /tmp/spark_tmp/ -m 100G  
```

#### (4) Execute your application with `spark-submit`  

- The user has to specify a configuration for the job 

General case

```
spark-submit --master spark://host:port  my_python_program.py
```



### Interesting example

Example 1

```
spark-submit --master spark://10.0.26.3:8765 --conf spark.executor.memory=100g --conf spark.driver.memory=4g --conf spark.executor.cores=40 02_ml_LogisticRegression.py

	- Total time tanken 164.68428468704224 sec. 
```

Example 2

```
spark-submit --conf spark.executor.memory=100g --conf spark.driver.memory=4g 02_ml_LogisticRegression.py

	- Total time tanken 90.23491238912837 sec. 
```

- If we use nmon we can see (clicking n to monitor network usage) that:
  - Example 1 is moving the data through net connection (and there is a lot of overhead)
  - Example 2 is moving the data without using the network.



#### Example with 2 slaves

```
spark-submit --master spark://10.0.26.3:8765 --conf spark.executor.memory=100g --conf spark.driver.memory=4g --conf spark.executor.cores=40 --conf spark.default.parallelism=80 /home/dbuchaca/git_stuff/spark_ibm_bsc/dataset_executions/02_ml_LogisticRegression.py
```









### How to start a spark master

We can start a master spark session with

```
/opt/spark/sbin/start-master.sh -p 8765  -m  64G
```

We can see that spark is running with `ps aux`: The third line showing a java process is the spark master

```
> ps aux                                 
USER       PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
dbuchaca     1  0.0  0.0  14004  1820 ?        Ss   16:27   0:00 singularity-instance: dbuchaca [spark_instance]
dbuchaca   190  0.0  0.0  19964  3476 pts/2    S    16:30   0:00 /bin/bash --norc
dbuchaca   411  3.8  0.3 9495308 403468 pts/2  Sl   16:36   0:06 /usr/lib/jvm/java-1.8.0-openjdk-amd64/bin/java -cp /opt/spark/conf/:/opt/spark/jars/* -Xmx1g org.apache.spark.deploy.mast
dbuchaca   577  0.0  0.0  36060  2876 pts/2    R+   16:39   0:00 ps aux

```

we can close it with

```
/opt/spark/sbin/stop-master.sh 
```





### How to start a spark slave

Start a spark slave

```
/opt/spark/sbin/start-slave.sh spark://10.0.26.3:8765 -d /tmp/spark_tmp/ -m 64G  
```

Kill spark slave

```
/opt/spark/sbin/stop-slave.sh 
```





### How to connect a pyspark script with a spark master and its slaves

```
spark-submit --master spark://host:port --conf spark.executor.memory=32g my_python_program.py
```

```
spark-submit --master spark://10.0.26.3:8765  --conf spark.executor.memory=32g 02_ml_LogisticRegression.py 
```





## Pyspark  (multiple node) 




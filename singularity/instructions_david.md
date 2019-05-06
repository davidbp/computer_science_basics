# How to use a Singularity file



### Create a container (similar to  creating an abstract class)

In order to build the singularity container described  in a `mydescriptor.singularity` file  we must do:

```
sudo singularity build name_of_image.simg mydescriptor.singularity
```

for example, if we want to build `bscdc_spark.singularity`:

```
sudo singularity build spark_bscdc_david.simg bscdc_spark.singularity
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

### Executing  a Pyspark file inside a singularity node (single node) 

```
myfolder>singularity instance.start $HOME/singularity_images/spark_bscdc_david.simg spark_instance

myfolder>singularity shell instance://spark_instance 

Singularity myfolder>spark-submit 02_ml_LogisticRegression.py
```



## start a spark master

We can start a master spark session with

```
/opt/spark/sbin/start-master.sh -p 8765   
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



### Executing  a Pyspark file inside a singularity node (multiple node) 



```
(Pdb) out
b'Traceback (most recent call last):\n  File "/home/dbuchaca/git_stuff/spark_ibm_bsc/dataset_executions/02_ml_LogisticRegression.py", line 38, in <module>\n    model = LogisticRegressionWithSGD.train(rdd_data, n_iterations)\n  File "/opt/spark/python/lib/pyspark.zip/pyspark/mllib/classification.py", line 325, in train\n  File "/opt/spark/python/lib/pyspark.zip/pyspark/mllib/regression.py", line 217, in _regression_train_wrapper\n  File "/opt/spark/python/lib/pyspark.zip/pyspark/mllib/classification.py", line 323, in train\n  File "/opt/spark/python/lib/pyspark.zip/pyspark/mllib/common.py", line 130, in callMLlibFunc\n  File "/opt/spark/python/lib/pyspark.zip/pyspark/mllib/common.py", line 123, in callJavaFunc\n  File "/opt/spark/python/lib/py4j-0.10.7-src.zip/py4j/java_gateway.py", line 1257, in __call__\n  File "/opt/spark/python/lib/py4j-0.10.7-src.zip/py4j/protocol.py", line 328, in get_return_value\npy4j.protocol.Py4JJavaError: An error occurred while calling o46.trainLogisticRegressionModelWithSGD.\n: org.apache.spark.SparkException: Job aborted due to stage failure: Task 20 in stage 3.0 failed 1 times, most recent failure: Lost task 20.0 in stage 3.0 (TID 23, localhost, executor driver): ExecutorLostFailure (executor driver exited caused by one of the running tasks) Reason: Executor heartbeat timed out after 122509 ms\nDriver stacktrace:\n\tat org.apache.spark.scheduler.DAGScheduler.org$apache$spark$scheduler$DAGScheduler$$failJobAndIndependentStages(DAGScheduler.scala:1889)\n\tat org.apache.spark.scheduler.DAGScheduler$$anonfun$abortStage$1.apply(DAGScheduler.scala:1877)\n\tat org.apache.spark.scheduler.DAGScheduler$$anonfun$abortStage$1.apply(DAGScheduler.scala:1876)\n\tat scala.collection.mutable.ResizableArray$class.foreach(ResizableArray.scala:59)\n\tat scala.collection.mutable.ArrayBuffer.foreach(ArrayBuffer.scala:48)\n\tat org.apache.spark.scheduler.DAGScheduler.abortStage(DAGScheduler.scala:1876)\n\tat org.apache.spark.scheduler.DAGScheduler$$anonfun$handleTaskSetFailed$1.apply(DAGScheduler.scala:926)\n\tat org.apache.spark.scheduler.DAGScheduler$$anonfun$handleTaskSetFailed$1.apply(DAGScheduler.scala:926)\n\tat scala.Option.foreach(Option.scala:257)\n\tat org.apache.spark.scheduler.DAGScheduler.handleTaskSetFailed(DAGScheduler.scala:926)\n\tat org.apache.spark.scheduler.DAGSchedulerEventProcessLoop.doOnReceive(DAGScheduler.scala:2110)\n\tat org.apache.spark.scheduler.DAGSchedulerEventProcessLoop.onReceive(DAGScheduler.scala:2059)\n\tat org.apache.spark.scheduler.DAGSchedulerEventProcessLoop.onReceive(DAGScheduler.scala:2048)\n\tat org.apache.spark.util.EventLoop$$anon$1.run(EventLoop.scala:49)\n\tat org.apache.spark.scheduler.DAGScheduler.runJob(DAGScheduler.scala:737)\n\tat org.apache.spark.SparkContext.runJob(SparkContext.scala:2061)\n\tat org.apache.spark.SparkContext.runJob(SparkContext.scala:2082)\n\tat org.apache.spark.SparkContext.runJob(SparkContext.scala:2101)\n\tat org.apache.spark.SparkContext.runJob(SparkContext.scala:2126)\n\tat org.apache.spark.rdd.RDD.count(RDD.scala:1168)\n\tat org.apache.spark.mllib.util.DataValidators$$anonfun$1.apply(DataValidators.scala:40)\n\tat org.apache.spark.mllib.util.DataValidators$$anonfun$1.apply(DataValidators.scala:39)\n\tat org.apache.spark.mllib.regression.GeneralizedLinearAlgorithm$$anonfun$run$3.apply(GeneralizedLinearAlgorithm.scala:255)\n\tat org.apache.spark.mllib.regression.GeneralizedLinearAlgorithm$$anonfun$run$3.apply(GeneralizedLinearAlgorithm.scala:255)\n\tat scala.collection.LinearSeqOptimized$class.forall(LinearSeqOptimized.scala:83)\n\tat scala.collection.immutable.List.forall(List.scala:84)\n\tat org.apache.spark.mllib.regression.GeneralizedLinearAlgorithm.run(GeneralizedLinearAlgorithm.scala:255)\n\tat org.apache.spark.mllib.api.python.PythonMLLibAPI.trainRegressionModel(PythonMLLibAPI.scala:92)\n\tat org.apache.spark.mllib.api.python.PythonMLLibAPI.trainLogisticRegressionModelWithSGD(PythonMLLibAPI.scala:278)\n\tat sun.reflect.NativeMethodAccessorImpl.invoke0(Native Method)\n\tat sun.reflect.NativeMethodAccessorImpl.invoke(NativeMethodAccessorImpl.java:62)\n\tat sun.reflect.DelegatingMethodAccessorImpl.invoke(DelegatingMethodAccessorImpl.java:43)\n\tat java.lang.reflect.Method.invoke(Method.java:498)\n\tat py4j.reflection.MethodInvoker.invoke(MethodInvoker.java:244)\n\tat py4j.reflection.ReflectionEngine.invoke(ReflectionEngine.java:357)\n\tat py4j.Gateway.invoke(Gateway.java:282)\n\tat py4j.commands.AbstractCommand.invokeMethod(AbstractCommand.java:132)\n\tat py4j.commands.CallCommand.execute(CallCommand.java:79)\n\tat py4j.GatewayConnection.run(GatewayConnection.java:238)\n\tat java.lang.Thread.run(Thread.java:748)\n\n'
(Pdb) q

```


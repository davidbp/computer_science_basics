## 6_spark_submit

### Container goal

Execute a python script inside a container that uses  `spark-submit`  to launch a spark job.

### Steps

- build the image `docker build -t  6_spark_submit .`

- then you should see with `docker images`

```
REPOSITORY       TAG      IMAGE ID        CREATED             SIZE
6_spark_submit   latest   23c28ae829dd    4 seconds ago       1.05GB

```

To execute the spark job inside the docker

- Run a bash inside the docker `docker run -it 23c28ae829dd /bin/bash`
- Inside the docker you can run a script with the command `spark-submit 01_ml_n_gram.py `

You should  see `bash-4.1#` when you enter inside the docker bash

```
bash-4.1# spark-submit 01_ml_n_gram.py 
```




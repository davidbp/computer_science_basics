
### Container goal

Execute a script file inside a container. 
In order to make this as simple as possible the script will simply print "\n\nHello world from a script file!!\n\n" 
to the terminal.


### Container description

In `1_hello_world_container` we have seen how to print hello world inside a container.
Notice that the `hello world!` was printed using the command `CMD ["echo", "hello world!"]`.

Now you can imagine a situation where you want to run a script that is more complicated.

We will build a script `script.sh` that will be called in our `Dockerfile`. 


### Dockerfile description

This `Dockerfile` will contain `COPY script.sh /script.sh` 

Notice that the file `script.sh` contains the following

```
#! /bin/sh

echo -e "\n\nHello world from a script file!!\n\n"
```

Where `#! /bin/sh` is telling docker that the script is a bash script


### Build and run the container

First, you need to make the `script.sh` executable.  This can be done writting

```
chmod +x script.sh
```

In order to build the container you can simply run
```
docker build .
```

You should get something similar to 
```
Sending build context to Docker daemon  5.632kB
Step 1/3 : FROM alpine
 ---> 196d12cf6ab1
Step 2/3 : COPY script.sh /script.sh
 ---> Using cache
 ---> 56f7262267e3
Step 3/3 : CMD ["/script.sh"]
 ---> Running in c37ef73e4307
Removing intermediate container c37ef73e4307
 ---> ceaa3481228e
Successfully built adba70f93c2a
```

This will build a Docker Container with identifier  `adba70f93c2a`.

We can now run our container and see what happens:

```
docker run --name 2_hello_world_script_inside_container adba70f93c2a


Hello world from a script file!!

Mem: 1591608K used, 455036K free, 824K shrd, 12548K buff, 1277096K cached
CPU:   0% usr   0% sys   0% nic 100% idle   0% io   0% irq   0% sirq
Load average: 0.17 0.04 0.01 1/422 8
  PID  PPID USER     STAT   VSZ %VSZ CPU %CPU COMMAND
    1     0 root     S     1580   0%   0   0% {script.sh} /bin/sh /script.sh
    8     1 root     R     1520   0%   0   0% top

```

Notice that this will not stop since the `top` command never finishes. If you open a new terminal an run 

```
docker ps
```

You will see that the docker container is running

```
CONTAINER ID        IMAGE               COMMAND             CREATED             STATUS              PORTS               NAMES
e64a8229c759        adba70f93c2a        "/script.sh"        7 seconds ago       Up 5 seconds                            2_hello_world_script_inside_container
```


## The importance of PID 1

Docker executes the container until the process in `PID 1` terminates. It uses this signal to stop the container from running.

Notice that the `PID 1` is executing `script.sh` which contains the `top` command and will never finish.
In Linux the proccess with `PID 1` cannot be exited with `control + c`. 

To force stop the container run 
```
docker stop 2_hello_world_script_inside_container
```


```
docker rm docker stop 2_hello_world_script_inside_container
```
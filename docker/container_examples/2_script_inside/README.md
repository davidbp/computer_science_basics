
### Goals of `2_script_inside`

This tutorial shows how to build a container image that will run a script from `.script.sh` inside the running container.

In order to make this as simple as possible the script will simply print "\n\nHello world from a script file!!\n\n" 
to the terminal and will start a `top` program that shows the processes running in the container.

In `2_script_inside` we will see:

- How to copy a script inside an image when it is build (using `COPY` in the `Dockerfile`)

- How to make a container that runs as an executable (using `ENTRYPOINT` in the `Dockerfile`)

- How to make a container execute a script (using `ENTRYPOINT` in the `Dockerfile`)

  

### Dockerfile description

This `Dockerfile` for this tutorial has the following from 

```
FROM alpine
COPY script.sh /script.sh
ENTRYPOINT ["/script.sh"]
```

Here 

-  `COPY script.sh /script.sh`  copies the script `sript.sh` inside the docker container
- `ENTRYPOINT ["/script.sh"]`  executes the script. 



### Tutorial

In `1_hello_world` we have seen how to print hello world inside a container.
Notice that the `hello world!` was printed using the command `CMD ["echo", "hello world!"]`. 

Now you can imagine a situation where you want to run a script that is more complicated. For example, imagine that you have a script  `script.sh` that you want to run inside the container when it is run. We will see now how this can be done.

First, you need to make the `script.sh` executable.  This can be done writting

```
chmod +x script.sh
```

Notice that the file `script.sh` contains the following

```
#! /bin/sh
echo -e "\n\nHello world from a script file!!\n\n"
top
```

Where `#! /bin/sh` is telling docker that the script is a bash script. In order to build the container you can simply run

```
docker build -t 2_script_inside .
```

This will build a Docker Container that should appear when running `docker images`:  

```
docker images
REPOSITORY                              TAG                 IMAGE ID            CREATED             SIZE
2_script_inside                         latest              6a648927c2da        3 minutes ago       5.57MB
```

We can now run our container and see what happens:

```
docker run --name 2_script_inside adba70f93c2a


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
e64a8229c759        adba70f93c2a        "/script.sh"        7 seconds ago       Up 5 seconds                            script_inside
```



### The importance of PID 1

Docker executes the container until the process in `PID 1` terminates. It uses this signal to stop the container from running.

Notice that the `PID 1` is executing `script.sh` which contains the `top` command and will never finish.
In Linux the proccess with `PID 1` cannot be exited with `control + c`. 

To force stop the container run 
```
docker stop script_inside
```


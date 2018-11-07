
In order to build the container you can simply run
```
docker build -t 1_hello_world_container .
```

You should get 
```
Sending build context to Docker daemon  2.048kB
Step 1/2 : FROM alpine
latest: Pulling from library/alpine
4fe2ade4980c: Pull complete 
Digest: sha256:621c2f39f8133acb8e64023a94dbdf0d5ca81896102b9e57c0dc184cadaf5528
Status: Downloaded newer image for alpine:latest
 ---> 196d12cf6ab1
Step 2/2 : CMD ["\n\necho hello world!\\n\n"]
 ---> Running in 92bcae65118b
Removing intermediate container 92bcae65118b
 ---> 6f098ae10bc3
```

This will build a Docker Container with identifier  `6f098ae10bc3`.

We can now run our container and see it executes "echo hello world!"

```
>docker run --name hello_world 1_hello_world_container
hello world!
```

Notice that if we try to run `docker run --name hello_world 1_hello_world_container` again we get an Error

```
docker run docker run --name hello_world 1_hello_world_container
docker: Error response from daemon: Conflict. The container name "/hello_world" is already in use by container "be489f1c5f2f2075cbe01d95a928293e4e54d59aa971e97ecad557a0a767a8f1". You have to remove (or rename) that container to be able to reuse that name.
See 'docker run --help'.
```


#### `docker start` vs `docker run`

Notice that we might have currently no docker running
```
docker ps 
CONTAINER ID        IMAGE               COMMAND             CREATED             STATUS              PORTS               NAMES
```

Nevertheless there can be several instances of a docker images with different names
```
docker ps -a
CONTAINER ID        IMAGE                     COMMAND                 CREATED             STATUS                          PORTS               NAMES
be489f1c5f2f        1_hello_world_container   "echo 'hello world!'"   3 minutes ago       Exited (0) 50 seconds ago                           hello_world
152a3a2f5889        1_hello_world_container   "echo 'hello world!'"   3 minutes ago       Exited (0) 3 minutes ago                            whatever
d23540258f9d        1_hello_world_container   "echo 'hello world!'"   3 minutes ago       Exited (0) About a minute ago                       1_hello_world_container
b0de1da254d6        1_hello_world_container   "echo 'hello world!'"   4 minutes ago       Exited (0) 4 minutes ago                            thirsty_bohr
c4a90c13653c        1_hello_world_container   "echo 'hello world!'"   6 minutes ago       Exited (0) 6 minutes ago                            vigilant_liskov
44185b4f5beb        ubuntu                    "/bin/bash"             2 hours ago         Exited (0) 2 hours ago                              eloquent_heisenberg
e0d8100b049e        alpine                    "/bin/sh"               2 hours ago         Exited (127) 2 hours ago                            confident_goldberg
86c84cf79b45        ubuntu                    "/bin/bash"             3 hours ago         Exited (0) 3 hours ago                              clever_haibt
``` 




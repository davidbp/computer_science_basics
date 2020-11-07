
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
docker run --name hello_world 1_hello_world_container
hello world!
```

Notice that if we try to run `docker run --name hello_world 1_hello_world_container` again we get an Error

```
>docker run docker run --name hello_world 1_hello_world_container
docker: Error response from daemon: Conflict. The container name "/hello_world" is already in use by container "be489f1c5f2f2075cbe01d95a928293e4e54d59aa971e97ecad557a0a767a8f1". You have to remove (or rename) that container to be able to reuse that name.
See 'docker run --help'.
```

Nevertheless, we do not see anny running container when we do `docker ps`

```
CONTAINER ID    IMAGE    COMMAND    CREATED   STATUS     PORTS     NAMES
```

But.... there is an  instance of a docker image already with the name  `hello_world` 
```
docker ps -a
CONTAINER ID      IMAGE    COMMAND    CREATED    STATUS   PORTS      NAMES
be489f1c5f2f     1_hello_world_container   "echo 'hello world!'"   3 minutes ago       Exited (0) 50 seconds ago     hello_world
```

**NOTE: We cannot start a new container with the same name  if there is a docker in `docker ps -a` with the same name**

If we do not put an specific name (or we change the name to `hello_world_2` we can run the container without any issues:

```
docker run --name hello_world_2 1_hello_world_container
hello world!
```

now we can see that we executed 2 instances of the container with names `hello_word` and `hello_word_2`

```
dcoker ps -a
CONTAINER ID      IMAGE    COMMAND    CREATED    STATUS   PORTS      NAMES
9ada6d042f9d        1_hello_world_container  "echo 'hello world!'"    15 seconds ago      Exited (0) 14 seconds ago  hello_world_2
be489f1c5f2f     1_hello_world_container   "echo 'hello world!'"   3 minutes ago       Exited (0) 50 seconds ago         hello_world
```



### Removing all  containers shown in  `docker ps -a`

One way to remove all the previous container from `docker ps -a` is to execute `docker rm <id>` for each `CONTAINER ID` shown in `docker ps -a` . Neverhteles if this list is big copy-pasting can be a hassle. To simplify this we can use

`docker ps -aq` which prints only the ids of the running and stopped containers:

```
docker ps -aq
9ada6d042f9d
be489f1c5f2f 
```

Then we can use the `$`  operator in bash to do an  inplace  string interpolation of the list of ids to the command `rm`. Note that ` $(docker ps -aq)`  returns 

```
9ada6d042f9d be489f1c5f2f
```

Therefore executing 

```
docker rm $(docker ps -aq)
```

is the same as executing

```
docker rm 9ada6d042f9d be489f1c5f2f
```

Therefore, with the instruction `docker rm $(docker ps -aq)` we remove all containers from the list `docker ps -a`.

Note that if there are running containers they will not be removed, they have to be stopped before. A message such as 

```
Error response from daemon: You cannot remove a running container 64420fce3c781224318b7eff465c0bd840a6aa72ca68360a35ea4b73ce2f86ad. Stop the container before attempting removal or force remove
```

will appear. 

There is the option to do `docker rm -f $(docker ps -aq)`  to force killing all containers.



### What is the difference between `docker stop <id>` and `docker rm <id>` ?

- **`docker stop <id>`** : https://docs.docker.com/engine/reference/commandline/stop/
  - Stops a container running. Therefore, it will not appear in <u>`docker ps`</u>
  - Preserves the container in the <u>`docker ps -a`</u> list 
    - This allows  you to commit it if you want to save its state in a new image.
- **`docker rm <id>`** :https://docs.docker.com/engine/reference/commandline/rm/
  - Removes the container from **`docker ps -a`**  list, losing its "state" (the layered filesystems written on top of the image filesystem).
  - Restriction: `docker rm <id>`  cannot remove a *running* container 
    - If called with `-f`,  then it can remove any container from   **`docker ps -a`** because  it sends a  `SIGKILL` signal which cannot be handled or ignored. The docker is forced to terminate.



#### Why Docker

The main benefits of docker are

- If a program works in your computer (inside a docker) it works everywhere (inside the same docker).

- You can build multiple projects you can keep them separate (in different docker containers). 
  This can eliminate possible incompatibilities between projects

### Basic Docker commands summary

- `docker run <image>`     : Get a Docker Image creates a container and starts the container.
- `docker start <name|id>` : Start docker `<name|id>`
- `docker stop <name|id>`  : Stop docker  `<name|id>`
- `docker ps`              : Currently running dockers
- `docker ps -a`           : Currently running dockers AND currently stopped dockers
- `docker rm <name|id>`    : Remove container `<name|id>`

### Basic Docker commands

- `docker images`: Shows a list of the available docker images

```
REPOSITORY          TAG                 IMAGE ID            CREATED             SIZE
<none>              <none>              adba70f93c2a        About an hour ago   4.41MB
<none>              <none>              b2db85580aad        3 hours ago         4.41MB
alpine              latest              196d12cf6ab1        8 weeks ago         4.41MB
```


- `docker run`: Starts running a Docker Image.

    - Ex: `docker run -it ubuntu` will start the Image `ubuntu` in interactive mode. Therefore you will have access

```
    docker run -it ubuntu
	root@44185b4f5beb:/# ls
	bin   dev  home  lib64  mnt  proc  run   srv  tmp  var
	boot  etc  lib   media  opt  root  sbin  sys  usr
```

    - If you want to space from a running interactive container without killing the
      container you can use `control + p + q`


- `docker stop`: Stops a running container 

    - Ex: `docker stop cfbde869879a` will stop container `196d12cf6ab1`


- `docker build`: Builds  Docker Image from a Dockerfile

    - Ex: `docker build -t name_of_the_image where_to_save` creates an image from
          the Dockerfile found in the same directory where the command is executed. The image is named `name_of_the_image` and it saved in path `where_to_save`

    - Ex: `docker build -t image_python .` creates an image from the Dockerfile found
          in the same directory where the command is executed. The image is named 
          `image_python` and it saved in the same current directory (that is the dot '.').



### Describing docker containers

- A Docker Container (or container) is running instance of a Docker Image (or just Image).
   - An Image is a snapshot of the software at a particular time.
   - This inclutes the operating system, software and application code.

- Images are defined using a Dockerfile.
    - A Docker file is a simple text file containing a list of steps to create an image.

In practise this means that a Dockerfile will be a very tiny file (less than a Mb), while a DockerImage 
can be several GB (it bundles what is described in the Dockerfile).

Examples of Dockerfile descriptions can be cound in hub.docker.com


### Buiding a docker container: `docker build .`


The command `docker build .` will build a docker container 

## Examples

There are a bunch of folders each of wich contains the description of a Docker Container


#### Example 1: `hello_world_container`

Shows how to build and run a container with a hardcoded command inside the container.
The command is "echo hello world!"


#### Example 2: `hello_world_script_inside_container`



#### Example 2: `python_container`


- Create a folder `src`

- Inside src create a python application hello.py
   - The code for `hello.py` can be  ``` print("\n\nYour application is running!\n\n")```

- Next to your `src` folder (not inside) create a text file `Dockerfile` to define our environment
   - For example we need python installed


### Why Docker

The main benefits of docker are

- If a program works in your computer (inside a docker) it works everywhere (inside the same docker).

- You can build multiple projects you can keep them separate (in different docker containers). 
  This can eliminate possible incompatibilities between projects
  
  

### Basic Docker commands summary

- **`docker build -t <name_image> <path_folder_containing_Dockerfile>`**

  - build an image from a  `Dockerfile` found in `path_folder_containing_Dockerfile`
  - After an image is build it should appear in `docker images`

- **`docker images`**: displays the images available in the local machine

  - After building an image it should appear in `docker images`
  - Example: `docker images`

  ```
  REPOSITORY       AG            IMAGE ID            CREATED             SIZE
  1_hello_world    latest        8608919710b9        2 weeks ago         5.57MB
  ```

- **`docker run <image>`   **

  -  Puts to run a Docker Image, in orther words, it creates a runing instace of the image which is a container.
    - Example: `docker run 1_hello_world`

  ```
  hello world!	
  ```

- **`docker stop <name|id>`  **

  - Stops a docker container with name  `<name|id>`
  - Example: ```docker stop 251df5dae0ed```

- **`docker start <name|id>` **: 

  - Starts a docker container with name `<name|id>`

- **`docker ps` **

  - Displays current running docker containers

- **`docker ps -a` **
- Displays current running containers and current stopped containers
- **`docker rm <name|id>`**    
- Remove container `<name|id>`
- **`docker rmi <name|id>`**
  - Remove Docker image `<name|id>`


- **`docker logs <name|id>`**
  - View the messages printed in the terminal of a container

- **`control + p, control + q`** 
  - Detach from a running container in interactive mode
- **`docker attach <name|id>`**
  - Attach (go inside) of a container that is still running



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

    - Ex: `docker stop cfbde869879a` will stop container  `196d12cf6ab1`


- `docker build`: Builds  Docker Image from a Dockerfile
- Ex: `docker build -t name_of_the_image where_to_save` creates an image from
          the Dockerfile found in the same directory where the command is executed. The image is named `name_of_the_image` and it saved in path `where_to_save`
    
- Ex: `docker build -t image_python .` creates an image from the Dockerfile found
          in the same directory where the command is executed. The image is named 
          `image_python` and it saved in the same current directory (that is the dot '.').

- `docker ps`: Shows all containers


- Ex: `docker rm $(docker ps -a -q)` removes all containers (running and not running) using the id find in `CONTAINER ID`.


### Examples

The folder `container_examples` contains several folders each of which explains some basic concepts from Docker. Each folder contains a docker image (described in a `Dockerfile` file) as well as a `README.md` file that introduces and explains several docker concepts. This tutorial is meant to learn docker from scratch and does not asume any previous knowledge.


#### Example 1: `1_hello_world`

This example shows how to build and run a container with a hardcoded command inside the container.
The command is `"echo hello world!"`


#### Example 2: `2_script_inside`

This example shows how to build a Dockerimage that contains  a script that is executed inside a container.

In order to make this as simple as possible the script will simply print  ```Hello world from a script file!!```  to the terminal and opens a `top` process.

#### Example 3: `3_python`


- Create a folder `src`

- Inside src create a python application hello.py
   - The code for `hello.py` can be  ``` print("\n\nYour application is running!\n\n")```

- Next to your `src` folder (not inside) create a text file `Dockerfile` to define our environment
   - For example we need python installed


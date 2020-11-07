## What is Docker

Docker is the most popular container management software



## What is a container (or docker container)

A Docker Container (or container) is running instance of a Docker Image (or just Image).

- An Image is a snapshot of the software at a particular time.
- This inclutes the operating system, software and application code.

Containers are used as isolated environments in which applications can be executed.  A  container can be though as a  virtual machine that is much more efficient than a virtual machine (because it does not need to virtualize all the hardware  layers in an operating system).



## What is a container image (or docker image)

A docker image is a blueprint of a docker container. When the docker image is run it becomes a container.

Images are defined using a Dockerfile.

- A Docker file is a simple text file containing a list of steps to create an image.

**In practise this means that a Dockerfile will be a very tiny file (les than a Mb), while a DockerImage 
can be several GB (it bundles what is described in the Dockerfile**). Examples of Dockerfile descriptions can be cound in hub.docker.com

In order words, a Dockerfile it a list of instructions (stored in a text file) to build a container. This image can be send to other people that can use it to build the container. Since images are made of layers, they can be composed.

When running a container, docker  uses an isolated filesystem. This custom filesystem is provided by a container image. Since the image contains the container's filesystem, it must contain everything needed to run an application 

- This includes all dependencies, configuration, scripts, binaries, etc. 
The image also contains other configuration for the container, such as environment variables, a default command to run, and other metadata.

##### Buiding a docker container: `docker build .`

-  **`docker build <name_container> <path_to_folder_containg_Dockerfile>`** 
  - build  ill build a docker container that is named `name_container`.

## 
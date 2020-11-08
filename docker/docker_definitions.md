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



##What are layers in an container image (Image Layers)

A docker image is made of layers, which allow efficient use of resources. If we have many different Dockerfile files that are composed of N different layers, we need to store the N layers, not all the possible combinations of the N layers.

Each line in the Dockerfile creates a layer.

##### Example 

The following example of `Dockerfile` 

```
FROM Ubuntu
RUN apt-get update && apt-get -y install python
```

creates 2 layers

- Layer 1 is a base Ubuntu Layer
- Layer 2 updates the package manager  `apt` and installs python

Each layer only stores the changes made to the previous layer, which makes efficient use of the memory because if another continer is build using any of the previous layers, the layers will not be downloaded and stored again, they will be reused.

Once a Docker container is build the layers in the image are created as **Read Only**, the layers will only be modified if something that depends in the layers is changed and the container is build again. For example, if a file is copied in the container at build time (because it contains a `COPY` command in the `Dockerfile`) then the container will only change if it is build again after a change in the copied file. This means that, once build, every time the container is executed will contain exactly the same layers. 



## Container layer after `docker run` (Container Layer)

When a docker container is run, it creates a new layer that allows the process executed in the containter to read and write to that new layer. The read-write-layer is used to store data that is created by the container at run time.

- This read-write layer is often called the Container Layer (oposed to the Image Layers that are created at build time)
- The read-write-layer exist only while the container is executed. When the container is destroied, any changes in this  read-write-layer are destroied.
- The same read-write-layer is shared across all containers that use the same image

**This is ilustrated in tutorial `4_python_save` ** which shows a container that executes a script that stores a result to memory, but this result is stored in the container layer and cannot be seen outside the container by the user. Once the container is terminated the stored file is destroyed.



## COPY-ON WRITE mechanism

When a docker container is run, it creates a new layer that allows the process executed in the containter to read and write to that new layer. Any changes to the applications run in the container during the container run time are done in the Container Layer. This process is called **copy-on write mechanism** .



## Persistent Volumes 

If we want a container to modify some data from the os of the machine in which it is executed we need to create a volume.

- `docker volume create data_volume`
  - Creates a folder `data_volume` inside `/var/lib/docker/volumes` folder.
- `docker run -v data_volume:/path_inside_container_layer`
  - Mounts the folder `data_volume` in the container and conects it to `path_container_layer`.
  - This allows the container to read and write to `data_volume` at runtime.
  - Since the `data_volume` folder lives as a folder in the OS outside the continer we say it is persistent. Once the container is terminated the changes amde to `data_volume` will persist.



## Bind Mounting folders

We can also mount other folders that are not in `var/lib/docker/volumes` using the `run -v` command when running a container.  If we have the path to a specific folder `path_persistent_folder` that we want to provide read-write acces at the container at run time we can use the following command:

- `docker run -v path_persistent_folder:path_inside_container_layer  container_name` 
  - Runs the container `container_name` and provides acces to the `path_persistent_folder`










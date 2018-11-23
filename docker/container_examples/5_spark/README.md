
### Container goal 4_python_save_results

Execute a python script inside a container that executes a python process and saves the result.

This is allows us to submit jobs to a system that can recieve and execute docker containers.
This is specially useful for managing "complex dependencies" such as libraries that our script might need.

- Can we acess the result after the docker has been executed and terminated ?


### Steps 

- `docker pull python:3.5` Download a basic image that contains python 3.5

- `docker build -t 4_test .` 
	- This builds the image. This is similar as compiling a class.

- `docker run --name 4_train_model_save_results 4_test`
    - This instanciates an object named `4_run_and_save` form the image (class) `4_python_save_results`. All instanciated objects have a `start` method.

- `docker start -ia 4_run_and_save` to start the container.
	- This executes the commands inside the object `4_run_and_save`. 

#### IMPORTANT!

- `docker run -d -P --name 4_run_and_save -v /app mydir/app`


    docker run -it --mount src="$(pwd)",target=/app ,type=bind 4_test


#### Additional notes

Since we have downloaded an image with python 3.5 when we did `docker pull python:3.5` , we can use it also

- `docker run -it python:3.5 bash` will connect us to a bash

- `docker run -it python:3.5` will connect us to a python interpreter


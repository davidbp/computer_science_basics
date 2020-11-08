### Goals of `3_python_example`

Execute a python script inside a container.

In `3_python_example` we will see:

- How to build a container with python 3.6 pre installed (using `FROM python:3.6-alpine` in the `Dockerfile`)
- How to copy a python script inside an image when it is build (using `COPY` in the `Dockerfile`)

- How to execute a python script inside the docker container (using  `CMD` in the `Dockerfile`)



### Dockerfile description

The Docker file in this tutorial  is defined as follows:

```
FROM python:3.6-alpine

# Set working directory to /app and copy the current dir
COPY python_code.py ./python_code.py

# run the python code
CMD ["python", "python_code.py"]
```



### Tutorial

Execute a python script inside a container and exit the container.

The steps to build an run the container described in the `Dockerfile` are as follows:

- `docker build -t 3_python_example .` 
  - This builds the image. This is similar as compiling a class.

- `docker run --name 3_script 3_python_example`
    - This instanciates an object named `3_script` form the image (class) `3_python_example`. All instanciated objects have a `start` method.

- `docker start -ia 3_script` to start the container again  and again
	- This executes the commands inside the object `3_script`. 




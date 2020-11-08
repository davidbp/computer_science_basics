### Goals of `4_python_save`

Execute a python script inside a container  that runs a python process and saves the results. This is allows us to submit jobs to a system that can recieve and execute docker containers. This is specially useful for managing "complex dependencies" such as libraries that our script might need.

The goal of this tutorial is to solve the following question:

- Can we acess the result after the docker has been executed and terminated ?

The answer is: it depends on how we execute the container. 

- If we do not provide a mount point that connects a local OS folder to a folder inside the container the results will not be accessible after the container  is terminated.



### Dockerfile 

The dockerfile in this tutorial is the following:

```
FROM python:3.5

# Install numpy
RUN pip install numpy && pip install pandas && pip install sklearn

# Set working directory to /app and copy the current dir
WORKDIR /app
COPY . /app

# run the python code
CMD ["python", "model_training.py"]
```

Note that this docker image installs some packages in the docker container (numpy, pandas and sklearn)  and runs a python application.

The code inside `model_training.py` trains a model and stores the result into `result.csv`

```
result.to_csv("./result.csv", index=False)
```

Note that if you execute the following steps, in your local machine you will not see the `result.csv` file.


### Steps 

- `docker pull python:3.5` Download a basic image that contains python 3.5

- `docker build -t 4_python_save .` This builds the image.

- `docker run --name 4_python_save_1 4_python_save`
    - This instanciates a container named `4_run_and_save_1` form the docker  image  `4_python_save`. All instanciated containers can be run using  `start`.

- `docker start -ia 4_python_save_1`  to start the container.
	- This executes the container  `4_run_and_save`. 



#### View the logs

We can view anything that is printed in the terminal of the container using `docker logs 4_python_save_1`

```
		modified after image

Training model...

Model trained

Results saved
```

To see that the python code was executed and the results were saved. Nevertheless, notice that we cannot see the `results.csv` file anywhere (from ouside of the container).  This is why we need to understand the concept of `persistent results`.



### Persistent results

We can allow the docker container to write to the local directory `4_python_save` if we run the docker container and we mount a volume inside the container that maps to `4_python_save`. 

We can do this as follows:

- `docker run -v "$PWD":/app 4_python_save`
  - This command runs the script that writes to the Container Layer in the folder  `/app` 
  - Now we mount a volume that connects the Container Layer folder `/app` with `PWD`
  - Because of the mounted volume the changes made at runtime in the container persist on the local filesystem of the OS that executes the container


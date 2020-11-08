### Goals of `6_python_save_interactive`

Execute manually a python script inside a container that saves some results that we can acess once we leave the container.

The goal of this tutorial is to solve the following question:

- Can we acess a bash terminal with a set of libraries that we care about to solve a task and then view the result outside the container ?

In particular we will see how to access a bash terminal inside a docker container and how to execute a file inside the container.



### Dockerfile 

The dockerfile in this tutorial is the following:

```
FROM python:3.5

# Install numpy
RUN pip install numpy && pip install pandas && pip install sklearn

# Set working directory to /app 
WORKDIR /app
```

Note that this docker image installs some packages in the docker container (numpy, pandas and sklearn)  but now it does not run the python code (like we did in `4_python_save`). 

We aim to run the container in interactive mode, mounting a volume that allows us to acesss the data from within the container and it also alows to write outside the container the resutls that we get in the code executed inside the container.




### Steps 

- `docker build -t 6_python_save_interactive .` This builds the image.

- `docker run -it  6_python_save_interactive bash`
  - This instanciates a container  form the docker  image `6_python_save_interactive`.
  - The `-it` allows us to run the container in interactive form
  - The `bash` command allows to run  a bash inside the container


After running `docker run -it  6_python_save_interactive bash` we are presented with a bash terminal inside the container. Note that we cannot see `model_training.py` or any of the files that we might expect

```
docker run -it  6_python_save_interactive bash
root@4f85613b7b42:/app# ls
root@53ad827b6484:/app# 
```

To avoid not seeing anything we will mount the container with `-v $PWD:/app ` which allows us to mount the folder `6_python_save_interactive` from our local directory inside the docker container.

We run now `docker run -v $PWD:/app -it  6_python_save_interactive bash` and we should see that we have acess to the local folder

```
docker run -v $PWD:/app -it  6_python_save_interactive bash
root@750300b28b07:/app# ls
Dockerfile  README.md  data  model_training.py
```

Now we can execute the python script and exit the container

```
python model_training.py 

		modified after image

Training model...

Model trained

Results saved

root@750300b28b07:/app# exit
```

Outside the container we should see `result.csv`

```
ls
Dockerfile        README.md         data              model_training.py result.csv
```

We have finished!


### Goals of `5_interactive_bash`

This tutorial aims to show how we can execute a container interactively, go inside the container, leave the container and go inside again.

In `5_interactive_bash` we will learn:

- How to detach from a container (using `control +p, control +q`)
- How to attach to a container (using `docker attach <name|id>`)
- How to keep the executed commands (and their outputs) using a screen inside the container



### Dockerfile 

The dockerfile in this tutorial is the following:

```
FROM ubuntu:latest
RUN apt-get update && apt-get install -y screen

# Set working directory to /app 
WORKDIR /app
```

Note that this docker image installs only screen. We will use screen to show how to exit and attach to a container and still preserve the history of executed commands and outputs of the commands.



### Tutorial

- `docker build -t 5_interactive_bash .` This builds the image.

- `docker run -it  5_interactive_bash bash`


After running `docker run -it  5_interactive_bash bash` we are presented with a bash terminal inside the container. Note that we cannot see `model_training.py` or any of the files that we might expect

```
docker run -it  5_interactive_bash bash
root@4f85613b7b42:/app# ls
root@53ad827b6484:/app# 
```

To avoid not seeing anything we will mount the container with `-v $PWD:/app ` which allows us to mount the folder `5_interactive_bash` from our local directory inside the docker container.

We run now `docker run -v $PWD:/app -it  5_interactive_bash bash` and we should see that we have acess to the local folder

```
docker run -v $PWD:/app -it  5_interactive_bash bash
root@750300b28b07:/app# ls
Dockerfile  README.md  
```

Note that anything that we do in the bash of the container will get lost once we detach from it.

For example, now we have only executed `ls` and we can see the output of `ls`.

Let us detach from the container using  `control +p, control +q`

If we attach again to the container we will simply see the bash 

```
root@c3838282a2cd:/app# 
```

but we cannot see we executed `ls` and we also cannot see the output of `ls`.

Since the container is the same, and it was still running when we detached from it, the history is intact.

If we run `history` in the bash we get:

```
root@c3838282a2cd:/app# history
    1  ls
    2  history
```

which shows that we previously executed `ls` even though we cannot see the previous output to the terminal.

To avoid this scenarios, and to keep track of the different commands and outputs of our program we can use a screen.

If we type:

```
screen -S docker_screen
# 
```

we are prompted with a new terminal that does not contain anything:

```
# 
```

here we can type now

```
# ls
Dockerfile  README.md
```

Typing `control + a +d` we can detach from the screen and we will see

```
[detached from 10.docker_screen]
root@c3838282a2cd:/app# 
```

Now we are back to our docker container. If we want we can detach the container as we did before with `control +p, control +q` . Then we can attach again and we see an empty terminal. Nevertheless we can attach again to the screen we created.

To see the currently running screens we can type `screen -list`

```
screen -list
There is a screen on:
	10.docker_screen	(11/08/20 18:39:30)	(Detached)
1 Socket in /run/screen/S-root.
```

Now we can see that `docker_screen` is running, we can attach to it with `screen -r docker_screen` and voilà, we can see the commands we executed inside the screen.

```
screen -r docker_screen
# ls
Dockerfile  README.md
```

We have finished!



### Container goal

Execute a python script inside a container and exit the container.

### Steps 

- `docker build -t 3_python_example .` 
	- This builds the image. This is similar as compiling a class.

- `docker run --name 3_script 3_python_example`
    - This instanciates an object named `3_script` form the image (class) `3_python_example`. All instanciated objects have a `start` method.

- `docker start -ia 3_script` to start the container again  it again
	- This executes the commands inside the object `3_script`. 




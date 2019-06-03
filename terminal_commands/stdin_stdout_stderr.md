
# Basics of stdin, stdout, stderr

In Unix we have different channels to connect the input and outputs of an script.

- The standard input (stdin)

- The standard output (stdout)

- The standard error (stderr)



## Standard input: stdin

stdin takes the data that is passed to a program.

For example, we use stdin in the following python script that we can save as `your_name.py`

```
name = input("Enter your name: ")
print("User has introduced as name {}".format(name))
```

If we execute `python your_name.py` the runtime of the script will pause until we introduce something and hit enter.
The example below shows what happens if "David" is introduced.

``` 
python your_name.py 
Enter your name: David
User has introduced as name David
```



## Standard output: stdout

The channel `stdout` is used to recieve all the data that a program runs. It is what we see when we execute a program by default. For example when we execute `ls` we see what the program `ls` prints in `stdout`.

### Redirect stdout: `>`

We can use`the symbol `>` (or `1>`) to tell Unix where to connect the stdout of a program.
For example

```
ls > what_is_here_.txt 
```

will not print anything in the terminal. But all that `ls` prints using `stdout` will be written in ``what_is_here_1.txt`

Notice that we get the exact same result if we use `1>` instead of `>`. 
```
ls 1> what_is_here_1.txt
```

If we can do `1>` is because... there is a `2>` option which is the `stderr` that we will see below.



## Standard Error:  stderr

The channel `stdout` is used to recieve only the errors  a program might encounter when running. Usually when we run a program we only see what is printed in stdout but not in stderr. For example when we execute `ls 2>what_is_here_2.txt` we see what the program `ls` prints in `stdout`. Nevertheless, `what_is_here_2.txt ` it  empty. 

### Redirect stderr: `2>`

We can use the symbol '2>' to redirect stderr.

Let us try the following:

```
 ls something_unexpected 2> what_is_here_2.txt
```

then we get

```
$ ls something_unexpected 2> what_is_here_2.txt

$ cat what_is_here_2.txt 
ls: something_unexpected: No such file or directory
```

Notice that the first command did not print anything because `ls` crashed, therefore, there was no stdout. Nevertheless the error that `ls` produced was sent to `what_is_here_2.txt `.

If we do the same with `>` now we see the error printed even though nothing is saved to `what_is_here_3.txt `. This happens precisely because `>` only connects stdout to the file and there was nothing printed in stdout.

```
$ ls something_unexpected > what_is_here_3.txt
ls: something_unexpected: No such file or directory

$ cat what_is_here_3.txt 
```

### Redirect both stderr and stdout: `myprogram 1> f1.txt 2>f2.txt` 

```
ls somehting_unexpected 1> f1.txt 2>f2.txt
```

Then we get nothing inide `f1.txt` and `ls: somehting_unexpected: No such file or directory ` inside `f2.txt`. This make sense because the stdout (saved to `f1.txt`) did not printed anything because the program crashed whereas stdout (saved to `f2.txt`) saved the error of the program. 
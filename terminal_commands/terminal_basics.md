

# Terminal basics

This file summarizes a set of basics terminal commands:

- cd :                  : move from one folder to anohter
- ls : list information : see files and folders of a particular folder
- du : disk usage       : summarize disk usage of a set of files, recursively directories 



### Disk usage `du`

We can see the filesize of a folder with **`du -h folder_path`** which will print at the bottom
the total size of the folder and each line above the last one the size of each of the subfodlers 
of the queried folder. The `-h` makes the output "--human-readable".

#### Example

```
> du -h spark_python/
```
```
159M	spark_python/apache_spark_tutorials_learning_journal
357M	spark_python/pyspark_bigdata
4,0K	spark_python/spark_interview_questions
3,7G	spark_python/
```

### Touch comamnd `touch`

The touch command is the easiest way to create new, empty files. It is also used to change the timestamps (i.e., dates and times of the most recent access and modification) on existing files and directories.

touch's syntax is

```
touch [option] file_name(s)
```
When used without any options, touch creates new files for any file names that are provided as arguments (i.e., input data) if files with such names do not already exist. Touch can create any number of files simultaneously.

Thus, for example, the following command would create three new, empty files named `file1`, `file2` and `file3`:
```
touch file1 file2 file3
```
A nice feature of touch is that, in contrast to some commands such as cp (which is used to copy files and directories) and mv (which is used to move or rename files and directories), it does not automatically overwrite (i.e., erase the contents of) existing files with the same name. Rather, it merely changes the last access times for such files to the current time.

Several of touch's options are specifically designed to allow the user to change the timestamps for files. For example, the -a option changes only the access time, while the -m option changes only the modification time. The use of both of these options together changes both the access and modification times to the current time, for example:
```
touch -am file3
```


# Terminal basics

This file summarizes a set of basics terminal commands:

- `cd` :    
  
  - move from one folder to anohter
- `ls` : list information 
  
  - see files and folders of a particular folder
- `du` : disk usage       
  
  -  summarize disk usage of a set of files, recursively directories 
- `grep`: get regular expression and print 
  
- Print lines of files that contain a particular match of a regular expression
  
- `cut`: Command to remove (or cut out) sections of each line of a file (or files)

  



###  `du`: Disk usage

We can see the filesize of a folder with **`du -h folder_path`** which will print at the bottom
the total size of the folder and each line above the last one the size of each of the subfodlers 
of the queried folder. The `-h` makes the output "--human-readable".

```
> du -h spark_python/
```
```
159M	spark_python/apache_spark_tutorials_learning_journal
357M	spark_python/pyspark_bigdata
4,0K	spark_python/spark_interview_questions
3,7G	spark_python/
```





###  `touch`: Creating empty files

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





### `grep`: Get Regular Expression and Print



#### Looking for key words in a document

We can use the `grep` command to find the lines in a file that contain a particular word.

For example `grep Charles people_data.txt` will print the lines where the string `Charles` appears in the document `people_data.txt`:

```
grep Charles people_data.txt 
```

```
Charles Harris
Charles Patterson
Charles Martin
Charles Jones
Charles Davis
Charles Miller
```

If we want we can look for `Charles J` inside the document. To do so we need to write the string between `  " "` because there is an space inside the string.

```
grep "Charles J" people_data.txt 
```

```
Charles Jones
```



#### `-i`:  Ignoring Upper/Lower case

The option `-i` can be used to ignore the upper/lower case on a word

``` 
grep dave -i people_data.txt
```

```Dave Martin
grep dave -i people_data.txt 
Dave Martin
davemartin@bogusemail.com
Dave Arnold
davearnold@bogusemail.com
Dave Moore
davemoore@bogusemail.com
```



#### `-w`: Looking for whole words not substrings

The option `-w` can be used to search for whole words instead of substrings.

The following command will be case insensitive and will look for the whole world `dave`. Notice that now we don not get the emails like `davearnold@bogusemail.com` because we are not looking for a substring but a word.

```
grep dave  -i -w  people_data.txt 
```

```
Dave Martin
Dave Arnold
Dave Moore
```



#### `-v: `Looking at all lines that do not contain a word

We can use `grep -v`  to retrieves all lines that do not contain a string

```
grep -v dave people_data_2.txt -10
```

```
615-555-7164
173 Main St., Springfield RI 55924
Davemartin@gmail.com
```

Notice that the file contains `dave martin` inside:

```
head -10 people_data_2.txt 
```

```
dave martin
615-555-7164
173 Main St., Springfield RI 55924
Davemartin@gmail.com
```



#### `*`: Looking at multiple files

We can look for a string in all the files in the current folder  with the star operator`*` as follows:

```
grep dave *
```

```
people_data.txt:davemartin@bogusemail.com
people_data.txt:davearnold@bogusemail.com
people_data.txt:davemoore@bogusemail.com
people_data_2.txt:dave martin
```

Notice that the results are then printed with the filename at the beggining followed by the line matching the string in the `grep` command. Results will be returned as follows:

```
file1: whatever_contained_dave_0
file1: whatever_contained_dave_1
file2: whatever_contained_dave_3
```



#### `-l`: Retrieving the files that contain a substring

We can use `grep -l` to print all  the filenames of the files which contain a particular string. 

```grep -l dave *
 grep -l dave *
```

```
people_data.txt
people_data_2.txt
terminal_basics.md
```



#### `-c`: Retrieving string counts in files

We can use `grep -c dave people_data.txt people_data_2.txt` to find the counts of all the lines that contain a particular string.

```
grep -c dave people_data.txt people_data_2.txt
```

```
people_data.txt:3
people_data_2.txt:1
```



#### `-r`: Search recursively in all directories and subdirectories

The option  `-r` can be use to recursively search in all directories and subdirectories.



#### `-A`: Retrieve  lines After match

The option `-A` can be used to print an specified number of lines **after** a match.

For example `grep -A 3 dave people_data.txt` will print the 3 lines after a match with `dave`.

```
 grep -A 1 dave people_data.txt 
```

```
davemartin@bogusemail.com

--
davearnold@bogusemail.com

--
davemoore@bogusemail.com

```



#### `-B`: Retrieve  lines Before match

The option `-B` can be used to print an specified number of lines **before** a match.

For example `grep -A 3 dave people_data.txt` will print the 3 lines after a match with `dave`.

```
 grep -B 1 dave people_data.txt 
```

```
173 Main St., Springfield RI 55924
davemartin@bogusemail.com
--
732 High St., Valyria KY 97152
davearnold@bogusemail.com
--
251 Pine St., Old-town OK 29087
davemoore@bogusemail.com
```



#### `-C`: Retrieve  lines in a given  Context match

The option `-C` can be used to print an specified number of lines in the  **context** a match. This means before and after a match.

For example `grep -C 2 dave people_data.txt` will print the 2 lines  before and after a match with `dave`.

```
grep -C 1 dave people_data.txt 
```

```
173 Main St., Springfield RI 55924
davemartin@bogusemail.com

--
--
732 High St., Valyria KY 97152
davearnold@bogusemail.com

--
--
251 Pine St., Old-town OK 29087
davemoore@bogusemail.com

```



#### `"regex"`: Using general regular expressions

We can use general regular expressions inside commas `" "`. 

For example retrieve all lines from a file that start with a number would be the following regular expression:

```
 grep "^[0-9]" people_data_2.txt 
```

```
615-555-7164
173 Main St., Springfield RI 55924
800-555-5669
969 High St., Atlantis VA 34075
560-555-5153
806 1st St., Faketown AK 86847
```

Another example: `"^8"` would retrieve only lines that start with number 8

```
grep "^8" people_data_2.txt 
```

```
800-555-5669
806 1st St., Faketown AK 86847
```





#### `"regex"`: Using Extender regular expressions

Let us imagine we want to retrieve rows of a file that match a union of two regular expression.

We have a regular expression "4$" that matches lines that end with a 4

```
grep "4$" people_data_2.txt 
```

```
615-555-7164
173 Main St., Springfield RI 55924
```

We have a regular expression "5$" that matches lines that end with a 5

```
grep "5$" people_data_2.txt 
```

```
969 High St., Atlantis VA 34075
```

Then we can do ` grep -E "r1|r2"` to match either r1 or r2.

```
grep -E "4$|5$"  people_data_2.txt 
```

```
615-555-7164
173 Main St., Springfield RI 55924
969 High St., Atlantis VA 34075
```

Note that we get as ouptut the union of both of the previous regular expressions.



**Exercise:  Retrieve all lines from `people_data.txt` that start with n or N **

Note that:

- we want to use `-i` to allow capital and non capital letters

- we want to use `^n` to verify that the line starts with `n` 

```
grep "^n" -i people_data.txt
```

```
Neil Patterson
neilpatterson@bogusemail.com
Neil Wilson
neilwilson@bogusemail.com
neildavis@bogusemail.com
Nicole Taylor
nicoletaylor@bogusemail.com
Neil Stuart
neilstuart@bogusemail.com
Neil Arnold
neilarnold@bogusemail.com
Nicole White
nicolewhite@bogusemail.com
```



#### `|` Piping results

This is not a particular option from `grep` but a general operation. Nevertheless it is so important that we write it here.

We can use `|` to piple the output of a `grep`into another `grep`.

For example we can first look for all lines that start with `80` in a file and then filter the ones that contain the substring `AK` inside. This is done with  `grep "^80" people_data_2.txt | grep AK`.

```
grep "^80" people_data_2.txt | grep AK
```

```
806 1st St., Faketown AK 86847
```



**Example: Seach all appearances of  `dave` in any document  within a given folder**:

Note that we can write the exercise in two steps:

- First get all the files that contain the query
- Then for each of the files look at any apperance of the query 

```
grep -l  dave * | grep -w dave *
```

```
people_data_2.txt:dave martin
terminal_basics.md:grep dave -i people_data.txt
terminal_basics.md:grep dave -i people_data.txt 
terminal_basics.md:The following command will be case insensitive and will look for the whole world `dave`. Notice that now we don not get the emails like `davearnold@bogusemail.com` because we are not looking for a substring but a word.
terminal_basics.md:grep dave  -i -w  people_data.txt 
terminal_basics.md:grep -v dave people_data_2.txt -10
terminal_basics.md:Notice that the file contains `dave martin` inside:
terminal_basics.md:dave martin
terminal_basics.md:grep dave *
terminal_basics.md:people_data_2.txt:dave martin
terminal_basics.md:```grep -l dave *
terminal_basics.md: grep -l dave *
terminal_basics.md:We can use `grep -c dave people_data.txt people_data_2.txt` to find the counts of all the lines that contain a particular string.
terminal_basics.md:grep -c dave people_data.txt people_data_2.txt
terminal_basics.md:For example `grep -A 3 dave people_data.txt` will print the 3 lines after a match with `dave`.
terminal_basics.md: grep -A 1 dave people_data.txt 
terminal_basics.md:For example `grep -A 3 dave people_data.txt` will print the 3 lines after a match with `dave`.
terminal_basics.md: grep -B 1 dave people_data.txt 
terminal_basics.md:For example `grep -C 2 dave people_data.txt` will print the 2 lines  before and after a match with `dave`.
terminal_basics.md:grep -C 1 dave people_data.txt 
terminal_basics.md:Example: Seach all files within a folder that contain `dave` as substring and then find all the occurances of `dave` within each of this files:
terminal_basics.md:grep -l  dave * | grep -w dave *
```

Note that in particular this file `terminal_basics.md` contains the queried word. And even the example itself is retrieved because it also contains the queried word.



#### `| xargs` Piping content of results





###  `cut`: Cut out files

#### `-f`: Retrieve  fields on each line

The option `-f` can be used to retrieve a given column of a file.

For example, `iris.csv` has the following format:

```
head iris.csv 
SepalLength,SepalWidth,PetalLength,PetalWidth,Name
5.1,3.5,1.4,0.2,Iris-setosa
4.9,3.0,1.4,0.2,Iris-setosa
4.7,3.2,1.3,0.2,Iris-setosa
```

Here we can see that each column is separated by a comma. We can tell `cut` to partition each line with a comma delimiter  stating "-d ,":

```
cut -d , -f1 iris.csv
```

If we want to get the first and the fifth columns we can do

```
cut -d , -f1 -f5 iris.csv
```

Note that we can filter the results using the pipe operator.

We could pass the output of the previous command to select only rows that endwith either "virginica" or "setosa"

```
cut -d , -f1 -f5 iris.csv | grep -E "virginica$|setosa$"
```



**Exercise: Retrieve the first column and the last one of the first 6 lines of `iris.csv` ** 

```
head -6 iris.csv | cut -d , -f1 -f5
```

```
SepalLength,Name
5.1,Iris-setosa
4.9,Iris-setosa
4.7,Iris-setosa
4.6,Iris-setosa
5.0,Iris-setosa
```


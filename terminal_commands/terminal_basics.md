

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

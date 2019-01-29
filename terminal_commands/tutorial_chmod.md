# Tutorial chmod

### Change mode chmod

Command used to give or denny the read/write/execute abilities to files and folders to different users.

- syntax: chmod [optons] mode filename
- options:  -R (recursive), -f (force), -v (verbose)
  - If -R then all files folders and subfolders from filename will have the same privileges.
- mode:     read(r)   write(w)    execute(x)
  - Octal way of coding mode
       owner    group    others
       rwx      rwx      rwx
       421      421      421 
   If we want to give to the owner
       - rwx we write 7 (4+2+1)
       - r-- we write 4 (4+0+0)
       - rw- we write 6 (4+2+0) 
       - --x we write 1 (0+0+1)
       etc

Example

    chmod -R 774 filename

will give rwx permissions to the owner, rwx permissions to the group and r-- permissions to others.

Example

    ls -l 
    
    drwxrwxr-x 2 david david      4096 may 24 17:28 spark_interview_questions

- The first d (from drwxrwxr-x) means the file is a directory.
- The first 3 letters rwx mean that the owner has the rwx privileges
- The following 3 letters rwx mean that the other users members of the same files group can rwx.
- Any other user can r-x (read, not write, execute).




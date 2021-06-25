
#### How to retrieve a file that has been removed from git (and a commit has been pushed with the removed file)

- List all commits affecting a given folder

```
git log -- path_to_folder
```

- Go back to the commit before the file was removed

```
git checkout second_to_last_commit -- path_to_folder
```

- Copy the file somewhere else and go back to your current branch state



#### Checkout to a specific branch

Clone the repository

```
git clone <repository_url>
```

List all branches

```
git branch -a 
```

Checkout the branch that you want

```
git checkout <name_of_branch>
```


#### Show changes in a branch with respect to master

If we want to see the changed files of a branch with respect to another branch (for example master) 
we can use:
```
git diff --stat --color current_branch..master
```

#### Delete branches

Delete local branch:
```
git branch -d local-branch
```

If there are unmerged commits the previous command might not work. Then you can  use

```
git branch -D local-branch
```

Delete a remote branch

```
git push origin --delete remote-branch
```




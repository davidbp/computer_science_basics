# Basics for regular expressions



A very goof way to practise regular expressions is to use 

- https://regexone.com



## Starts with and ends with symbols



### `^X`: Matches any string that starts with `X`





### `X` : Matches any string that ends with `X`





### `^X` : Starts and ends with `X` 







## Quantifiers in regular expressions



### `XYZ?` Matches any string that has `XY` followed by zero or one `Z`





### `XYZ*` Matches any string that has `XY` followed by zero or more `Z`





### `XY+` Matches any string that has `XY` followed by one or more `Z`





### `XYZ{n}` Matches any string that has `XY` followed by `n`or more `Z` 





### `XYZ{n,m}` Matches any string that has `XY` followed by `n` up to `m`  `Z`





## Operators applied on sequences of characters



###`X(YZ)*` Matches any string that has `X` followed by zero or more copies of the sequence `YZ`





### `X(YZ){2,5}` Matches any string that has `X` followed by one or more copies of the sequence`YZ`









## Or operation





## Character classes 



### `\d` Matches any single character that is a digit

`\d`  matches any symbol in   $\{0,1,2,3,4,5,6,7,8,9\}$

 

| Text             | ` \d+`                                                       |
| ---------------- | ------------------------------------------------------------ |
| abc**123**xyz    | ![Success](./images/task_complete.png)   |
| define "**123**" | ![Success](./images/task_complete.png)   |
| var g = **123**; | ![Success](./images/task_complete.png)   |



| Text             | ` \d{1,2}`                                                   |
| ---------------- | ------------------------------------------------------------ |
| abc**12**3xyz    | ![Success](./images/task_complete.png)   |
| define "**12**3" | ![Success](./images/task_complete.png)   |
| var g = **12**3; | ![Success](./images/task_complete.png)   |








### `\w` Matches any single word character that is a alphanumeric or underscore

`\w`  matches any symbol in   $\{a,b,c,d,e,f,\dots,z,\_\}$



##### Example: `[\d|\w]\.` or `(\d|\w)\.` 

| Text     | `[\d|\w]\.`                              |
| -------- | ---------------------------------------- |
| ca**t.** | ![Success](./images/task_complete.png)   |
| 89**6.** | ![Success](./images/task_complete.png)   |
| ?=+.     | ![Success](./images/task_incomplete.png) |

##### Example: ` .*\.`

| Text     | ` .*\.`                                |
| -------- | -------------------------------------- |
| **cat.** | ![Success](./images/task_complete.png) |
| **896.** | ![Success](./images/task_complete.png) |
| **?=+.** | ![Success](./images/task_complete.png) |





### `\s` Matches any whitespace  character 

`\s`  matches any symbol in   $\{ \, , \,\,\,\,  \}$ (space, tab etc..)


# JSmin
This repository contains a sample main.c for your use. This can be compiled with lib-jsmin.c to create jsmin(jsmin.exe), which can then be used as a console application.

### Compilation example
```
gcc jsmin.c lib-jsmin.c -o jsmin
```
### Sample jsmin usage
```
jsmin example.c
```
When a file name is specified in the command line argument of jsmin, a file such as example.min.js is created in the same directory, and the output is output to this file.
```
jsmin example.js -o result.js
```
You can also specify the destination file with the '-o' ('--output') option.

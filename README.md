# JSMin
This repository contains a sample main.c for your use. This can be compiled with lib-jsmin.c to create 'jsmin' ('jsmin.exe'), which can then be used as a console application.
### Compilation example (GCC)
```
gcc jsmin.c lib-jsmin.c -o jsmin
```
### examples showing the use
```js
var sample = 100

if (sample > 50) {
  console.log("examples showing the use (of a word)")
} else sample += 20

// sample function
function 
```
# Sample jsmin usage
```
jsmin example.js
```
When a file name is specified in the command line argument of jsmin, a file such as `example.min.js` is created in the same directory, and the compression result is output to this file.
```
jsmin example.js -o result.js
```
You can also specify the destination file with the '-o' ('--output') option. You can also write `jsmin -o result.js example.js`.

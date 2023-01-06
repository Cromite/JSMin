# JSMin
This repository contains a sample main.c for your use. This can be compiled with lib-jsmin.c to create 'jsmin' ('jsmin.exe'), which can then be used as a console application.

**Compilation Example**
```
gcc jsmin.c lib-jsmin.c -o jsmin
```

# Examples of Use
**Before**
```js
var sample = 100
log(sample)

// sample function
function log(num) {
  if (num > 50) {
    console.log("examples of use")
  } else num += 20
}
```
**After**
```js
var sample=100;log(sample);function log(num){if(num>50){console.log("examples of use")}else num+=20}
```

# Usage
```
jsmin example.js
```
When a file name is specified in the command line argument of jsmin, a file such as `example.min.js` is created in the same directory, and the compression result is output to this file.
```
jsmin example.js -o result.js
```
You can also specify the destination file with the '-o' ('--output') option. You can also write `jsmin -o result.js example.js`.
```
jsmin example.js -w
```
In addition, the '-w' ('--overwerite') option will overwrite the original file without creating a new file.You can also write `jsmin -w example.js`
**Use the -h (--help) option to see how to use it**
```

```

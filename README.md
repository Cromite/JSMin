# JSMin
This repository contains the Windows application **jsmin.exe** and the **jsmin** library. If you just want to use the jsmin command, simply download jsmin.exe.

# jsmin
This command erases extra whitespace and comments in the javascript code, making it one line and reducing the file size.

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

## Usage
```
jsmin example.js
```
When a file name is specified in the command line argument of jsmin, a file such as **example.min.js** is created in the same directory, and the compression result is output to this file.

```
jsmin input.js -o output.js
```
You can also specify the destination file with the **-o** (**--output**) option. You can also write `jsmin -o output.js input.js`.

```
jsmin example.js -w
```
In addition, the **-w** (**--overwerite**) option will overwrite the original file without creating a new file.You can also write `jsmin -w example.js`.

Use the -h (--help) option to see how to use jsmin
```
Usage: jsmin <file> [options...]

Options:
  -o, --output <file>  write to <file> instead of writing in '...min.js'
  -w, --overwrite      overwrite the file
  -h, --help           get help for commands
  -v, --version        show jsmin version
```

# jsmin library
```c
#include "jsmin/jsmin.h"

char *jsmin(char *code)
```
**Parameters:**

`code` - Original javascript code

**Returns:**

Minified javascript code
### Example
```
Directory
 ├ example.c
 └ jsmin
    ├ jsmin.h
    └ jsmin.c
```
```c
// example.c

#include <stdio.h>
#include "jsmin/jsmin.h"

int main() {

    FILE *fp = fopen("example.js", "r+");
    
    // Get the contents of example.js
    int i = 0;
    char code[100000];
    while((code[i] = fgetc(fp)) != EOF) i++;
    code[i] = '\0';

    char *result = jsmin(code); // <-- Minify the code here

    // Overwrite the file
    fputs(result, fp);
    fclose(fp);

    return 0;
}
```
### Compile
```
gcc example.c jsmin/jsmin.c -o jsmin
```
This console application minifies **example.js** by overwriting it.

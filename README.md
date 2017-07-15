<<<<<<< HEAD
# PPMDraw
#### A brief .ppm picture generator
Also a frame/platform (sort of)

This program will use a "blackboard" (indeed black after init.) to record the drawing operation and "push" it into ppm file at last.
The drawing operation works by
```
void pixdrw(int x,int y,int r,int g,int b)
```
x,y means the West-East distance and North-South distance between this point and the ** NW ** corner
r g b as it means usually

You need to insert the code including pixdrw() to the maindraw() function or somewhere you like ;-)

And this source code should be compiled by
```
g++ main.cpp -std=c++11
```
You can use
```
[exec.file] filename.ppm
```
to customize the output filename,or it will be Default.ppm

More features will maybe (maybe not) add.
Such as
* cmdline switch
* filetype runtime
* dynamic board size (instead of #define)
* blah blah
=======
# ppmdraw
A brief .ppm picture generator
>>>>>>> c5a723b5cadb637a03eae1aee3c4efd34a72d9c1

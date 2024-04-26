# GPUComputing-Homework1

## Compile the code
To compile to code simply type `make` in the home directory. A debug version is also available by using `make debug`.

## Run the code
The compiled program is stored in the `/bin` folder. It takes as a required argument the size of the matrix, expressed as a power of two (e.g. ./bin/GPU_CompH1 4 will create a matrix of size 16X16). An additional argument can be passed to declare a custom grid size, used in the tiled approach, if no argument is passed the default grid size is 8X8.

# Description
Repository of my CMPS 270 (Software Construction) assignments.

## Assignment 1
See [Assignment_1.pdf](/Assignment_1/Assignment_1.pdf)  
Due date: `Monday, 10 October 2022, 11:59 PM` (Deadline extended)

## Assignment 2

See [Assignment_2.pdf](/Assignment_2/Assignment_2.pdf)  
Due date: `Sunday, 6 November 2022, 11:59 PM` (Deadline extended)

## Running
Each assignment contains its own Makefile. To run the exercises, follow these steps:

1) Go to the assigment folder, `X` being the assignment number:
```sh
cd Assignment_<X>
```
2) Compile and run a unique exercise, `Y` being the exercise number:
```sh
make Exercise<Y>
```
3) Compile and run all the exercises at once:
```sh
make all
```
4) Delete all of the compiled files:
```sh
make clean
```

## Platforms
Tested on Linux (Manjaro), should work on MacOS. Probably works on Windows, except for Assignment 3 because of the time feature.

## License
Licensed under the [MIT](LICENSE) license.
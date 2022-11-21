# HIQ Programming Test for C++ Developer

## Task description

- [Programming-exercise.pdf](programming-exercise.pdf)

## How to run this



### Requirements
The project is built using the cross-platform build tool, cmake. The requirements for successful compilation and run are
- CMake
- Git 
- g++

### Setup 
1. Clone the reposition

```shell
git clone https://github.com/blongho/hiq-programming-test.git 
 ```

The file structure should be like this

```txt
hiq-programming-test.git /
├── CMakeLists.txt
├── Main.cpp
├── README.md
├── inc
├── programming-exercise.pdf
├── src
├── test
├── test.txt // add your test cases here
└── test_cases.txt // program's test cases if nothing is defined (see below)
```

Structure of the test file
[test_cases.txt](test_cases.txt)

2. Move to the newly downloaded project root directory

```shell
cd hiq-programming-tests 
```

3. Create the build directory and move to it

```shell
mkdir build && cd build 
```

4. Configure the project with cmake

```shell 
cmake .. -DTEST_SAMPLES_FILE="test.txt" -DCMAKE_BUILD_TYPE=Release
```

5. Build the project executables

```shell 
make -j6
```

6. Run the tests

```shell 
./tests/test_robot
```




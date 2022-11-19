# HIQ Programming Test for C++ Developer

## Task description 
- [Programming-exercise.pdf](programming-exercise.pdf)

## How to run this
1. Clone the reposition 
```shell
git clone https://github.com/blongho/hiq-programming-test.git 
 ```

2. Build and test the program
```shell
# 2.1 Move 
cd hiq-programming-test 

# 2.2 Create the build directory and move to it
mkdir build && cd build 

# compile with cmake 
cmake .. -DTEST_SAMPLES_FILE="test.txt" -DCMAKE_BUILD_TYPE=Release
# where test is the file containing the tests
 ```

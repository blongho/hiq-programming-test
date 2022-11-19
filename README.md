# HIQ Programming Test for C++ Developer

## Task description 
- [Programming-exercise.pdf](programming-exercise.pdf)

## How to run this
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

2. Build and test the program
```shell
# 2.1 Move 
cd hiq-programming-test 

# 2.2 Create the build directory and move to it
mkdir build && cd build 

# 2.3 compile with cmake 
cmake .. -DTEST_SAMPLES_FILE="test.txt" -DCMAKE_BUILD_TYPE=Release

# 2.4 Make the project
make -j6

# 2.6 Run the tests
./test/test
# where test is the file containing the tests
 ```



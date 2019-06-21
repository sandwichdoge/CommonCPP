# Unit test
g++ unit_test/test_main.cpp  ../gtestlib/libgtest.a  -o run_tests.out -I../gtestlib/ -pthread  -fsanitize=thread
time ./run_tests.out && rm run_tests.out

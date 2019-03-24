g++ unit_test/test_main.cpp ini.cpp  ../gtestlib/libgtest.a  -o run_tests.out -I../gtestlib/ -pthread
./run_tests.out && rm run_tests.out

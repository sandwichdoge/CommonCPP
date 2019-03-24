g++ -c ini.cpp -O3 -fPIC -march=native -o libini.so

# Unit test
g++ unit_test/test_main.cpp libini.so  ../gtestlib/libgtest.a  -o run_tests.out -I../gtestlib/ -pthread
./run_tests.out && rm run_tests.out

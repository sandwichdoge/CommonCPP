g++ -c StringUtils.cpp -O3 -fPIC -march=native -static -o libStringUtils.a

# Unit test
g++ unit_test/test_main.cpp libStringUtils.a ../gtestlib/libgtest.a  -o run_tests.out -I../gtestlib/ -pthread
./run_tests.out && rm run_tests.out

g++ -c StringUtils.cpp -O3 -fPIC -march=native -o libstrutils.so

# Unit test
g++ libstrutils.so unit_test/test_main.cpp  ../gtestlib/libgtest.a  -o run_tests.out -I../gtestlib/ -pthread
./run_tests.out && rm run_tests.out

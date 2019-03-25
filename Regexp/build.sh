g++ -c Regexp.cpp -O3 -fPIC -march=native -o libregexp.so

# Unit test
g++ unit_test/test_main.cpp libregexp.so  ../gtestlib/libgtest.a  -o run_tests.out -I../gtestlib/ -pthread
./run_tests.out && rm run_tests.out

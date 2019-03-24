g++ unit_test/test_ini_main.cpp ini.cpp  ~/samba/linux/usr/lib/generic/x64/libgtest.a  -o run_ini_tests.out -I /home/neon/samba/linux/usr/include/ -pthread
./run_ini_tests.out && rm run_ini_tests.out

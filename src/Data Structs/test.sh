g++ test.cc *.hpp -O0 -g;
./a.out
/usr/bin/valgrind --leak-check=full ./a.out

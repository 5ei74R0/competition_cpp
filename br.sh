set -e
g++ -Wall -Wextra ./src/run$1.cpp -o ./src/bin/run$1.out
time ./src/bin/run$1.out

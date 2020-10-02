# Concurrent Correctness in Vector Space
## Build:
Install dependencies:

`sudo apt-get install libtbb-dev` <br />
`cd src/tervel/tests` <br />
`make` <br />

## Options:
TEST_SIZE: Test Size <br />
DATA_STRUCTURE: { 0="TBB\_QUEUE" , 1="KFIFO\_QUEUE", 2="BOOST\_STACK", 3="TERVEL\_STACK", 4="TBB\_MAP", 5="TERVEL\_MAP" } <br />
CORRECTNESS_CONDITION: { 0="LINEARIZABILITY" , 1="SEQUENTIAL\_CONSISTENCY", 2="QUIESCENT\_CONSISTENCY", 3="QUASI\_LINEARIZABILITY" } <br />
NUM_THRDS: Number of Threads, set on line 31 in `cd src/tervel/tests/bench/main.cc` <br />
K: Quasi-linearization factor, set on line 46 in `cd src/tervel/tests/bench/main.cc` <br />

## Run:
`cd src/tervel/tests` <br />
`./executables/benchmark.x <TEST_SIZE> <DATA_STRUCTURE> <CORRECTNESS_CONDITION>` 

For example, to test TERVEL\_STACK with test size 100 for "QUIESCENT\_CONSISTENCY": <br />
`./executables/benchmark.x 100 3 2`


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
NUM_THRDS: Number of Threads, set on line 31 in `src/tervel/tests/bench/main.cc` <br />
K: Quasi-linearization factor, set on line 46 in `src/tervel/tests/bench/main.cc` <br />

## Run:
`cd src/tervel/tests` <br />
`./executables/benchmark.x <TEST_SIZE> <DATA_STRUCTURE> <CORRECTNESS_CONDITION>` 

For example, to test TERVEL\_STACK with test size 100 for "QUIESCENT\_CONSISTENCY": <br />
`./executables/benchmark.x 100 3 2`

## Interpretation:
If the execution is correct, the tool will print "Program Correct Up To This Point". If a correctness violation is detected, the tool will print "Program Not Correct", and a warning will print that indicates the detected error. <br />
WARNINGS: <br />
Incorrect CONSUME: An item was consumed that doesn't exist in the data structure. <br />
Incorrect READ: An item was read that doesn't exist in the data structure. <br />
Incorrect FAIL: A method call failed to consume an item that exists in the data structure. <br />

## Run Script:
To reproduce results in experiments: <br />
`cd src/tervel/tests/script` <br />
`make` <br />
`./script` <br />

# P-Compositionality:
## Build:
`cd RelatedWork/P-Compositionality/linearizability-checker` <br />
`make stack-test` <br />

## Options:
TEST_SIZE: Test Size, set on line 4891 in `RelatedWork/P-Compositionality/linearizability-checker/lt.cc` <br />
NUM_THRDS: Number of Threads, set on line 4888 in `RelatedWork/P-Compositionality/linearizability-checker/lt.cc` <br />

## Run:
`cd RelatedWork/P-Compositionality/linearizability-checker` <br />
`./lt-stack-test` <br />


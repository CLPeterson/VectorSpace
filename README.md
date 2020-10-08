# Concurrent Correctness in Vector Space
## Build:
Install dependencies: <br />
`sudo apt-get update` <br />
`sudo apt-get install libtbb-dev libboost-all-dev libgflags-dev` <br />
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

## Replicate the Results of the Paper:
The runtime of the dynamic analysis tool can be replicated for all experiments except for the k-FIFO queue. The memory requirements for the k-FIFO queue are too large to run in a virtual machine.

Run Script: <br />
`cd src/tervel/tests/script` <br />
`make clean` <br />
`make` <br />
`./script` <br />
Running the entire script takes approximately 18 hours (RAM = 16 GB, CORES = 4, PROCESSOR = Intel(R) Core(TM) i7-8550U CPU @ 1.80 GHz  1.99 GHz. To replicate a subset of the results, update the for-loop on line 23 of in `src/tervel/tests/script/script.cc` to set k to the value representing the correctness conditions of interest: <br />
CORRECTNESS_CONDITION: { 0="LINEARIZABILITY" , 1="SEQUENTIAL\_CONSISTENCY", 2="QUIESCENT\_CONSISTENCY", 3="QUASI\_LINEARIZABILITY" } <br />
Each correctness condition takes approximately 4.5 hours to test. The results are printed to `src/tervel/tests/script/output.txt` <br />

Format of output (for each correctness condition): <br />
`<program time> <verification time>` (TBB\_QUEUE, NUM\_THRDS = 32, TEST\_SIZE = 10) <br />
`<program time> <verification time>` (BOOST\_STACK, NUM\_THRDS = 32, TEST\_SIZE = 10) <br />
`<program time> <verification time>` (TERVEL\_STACK, NUM\_THRDS = 32, TEST\_SIZE = 10) <br />
`<program time> <verification time>` (TBB\_MAP, NUM\_THRDS = 32, TEST\_SIZE = 10) <br />
`<program time> <verification time>` (TERVEL\_MAP, NUM\_THRDS = 32, TEST\_SIZE = 10) <br />

`<program time> <verification time>` (TBB\_QUEUE, NUM\_THRDS = 32, TEST\_SIZE = 100) <br />
`<program time> <verification time>` (BOOST\_STACK, NUM\_THRDS = 32, TEST\_SIZE = 100) <br />
`<program time> <verification time>` (TERVEL\_STACK, NUM\_THRDS = 32, TEST\_SIZE = 100) <br />
`<program time> <verification time>` (TBB\_MAP, NUM\_THRDS = 32, TEST\_SIZE = 100) <br />
`<program time> <verification time>` (TERVEL\_MAP, NUM\_THRDS = 32, TEST\_SIZE = 100) <br />

`<program time> <verification time>` (TBB\_QUEUE, NUM\_THRDS = 32, TEST\_SIZE = 1000) <br />
`<program time> <verification time>` (BOOST\_STACK, NUM\_THRDS = 32, TEST\_SIZE = 1000) <br />
`<program time> <verification time>` (TERVEL\_STACK, NUM\_THRDS = 32, TEST\_SIZE = 1000) <br />
`<program time> <verification time>` (TBB\_MAP, NUM\_THRDS = 32, TEST\_SIZE = 1000) <br />
`<program time> <verification time>` (TERVEL\_MAP, NUM\_THRDS = 32, TEST\_SIZE = 1000) <br />

`<program time> <verification time>` (TBB\_QUEUE, NUM\_THRDS = 32, TEST\_SIZE = 10000) <br />
`<program time> <verification time>` (BOOST\_STACK, NUM\_THRDS = 32, TEST\_SIZE = 10000) <br />
`<program time> <verification time>` (TERVEL\_STACK, NUM\_THRDS = 32, TEST\_SIZE = 10000) <br />
`<program time> <verification time>` (TBB\_MAP, NUM\_THRDS = 32, TEST\_SIZE = 10000) <br />
`<program time> <verification time>` (TERVEL\_MAP, NUM\_THRDS = 32, TEST\_SIZE = 10000) <br />

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

## Replicate the Results of the Paper:
`cd RelatedWork/P-Compositionality/linearizability-checker` <br />
Update line 4891 in `RelatedWork/P-Compositionality/linearizability-checker/lt.cc` as follows: <br />
`constexpr WorkerConfiguration worker_configuration = {'\24', 10U};` <br />
`make stack-test` <br />
`./lt-stack-test` <br />
Results are printed in `RelatedWork/P-Compositionality/linearizability-checker/results.txt` <br />
Repeat Steps and update line 4891 in `RelatedWork/P-Compositionality/linearizability-checker/lt.cc` for following cases: <br />
* `constexpr WorkerConfiguration worker_configuration = {'\24', 100U};` <br />
* `constexpr WorkerConfiguration worker_configuration = {'\24', 1000U};` <br />
* `constexpr WorkerConfiguration worker_configuration = {'\24', 5000U};` (may time out after 25 seconds) <br />


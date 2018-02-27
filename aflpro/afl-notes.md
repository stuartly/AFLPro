AFL Mutation Strategies:
Strategy 1: Bit flip, flip every bit of the current entry, could flip 1, 2, 4, 8 consecutive bits from left to right.
Strategy 2: Arithmetic, plus and minus 1 to 35 for every byte, 2bytes, to double word, filter out those covered by bit flip.
Strategy 3: Interesting integers for 1 byte, 2 bytes 4 bytes basically selected from a fixed dictionary by filtering out covered by strategy 1 or strategy 2.
Strategy 4: Dictionary, overwrite and insert from user provided and auto-discovered dictionary entries.
Strategy 5: Havoc, randomly change part of the seed based on above four strategies, main differences is that the modified bits may not be consecutive.   
Strategy 6: Calibrate trace, calculate a test case whether it is non-deterministic and coverage vs execution time so as to assign scores for a test case.
Strategy 7: Trim trace, reduce the size of a test case such that the shortest test case has the same effect as the original trace.
All these strategies are applied in sequences for the current seed and each will be applied several times to generate multiple mutants for each strategy.
 
 Tasks:
 T1: Support client input syntax for better mutation by AFL, without filtering or direct fix invalid mutants. (Situ Linyun)
 T2: The start sequence shall be AFL starts Server first and next starts Client. Possible solution: AFL receives user input to start server and then start the client as usual. (Xiao Hao)
 T3: Server and client are both nonterminating, so we do not need forkserver in AFL. Thus, instrumentation of server (for coverage calculation), client does not require instrumentation. (Zou Liang)
 T4: calculation of server coverage, when (use timeout in AFL), how (use existing mechanism of AFL).
 Use FTP as the target protocol.

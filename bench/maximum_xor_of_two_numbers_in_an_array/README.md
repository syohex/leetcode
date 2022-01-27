# Benchmark of LeetCode problem 0421

https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

## Environment

- Windows 10 19043
- clang++ 13.0.0 
- Intel Corei7-8750H
- Memory 16GB

## How to compile

```
clang++ -O2 main.cpp
```

## Result

```
% ./a.exe
Size=        10         Brute Force: 0us        Trie: 52us      BruteForce is better
Size=       100         Brute Force: 2us        Trie: 174us     BruteForce is better
Size=      1000         Brute Force: 85us       Trie: 1291us    BruteForce is better
Size=     10000         Brute Force: 7304us     Trie: 12493us   BruteForce is better
Size=    100000         Brute Force: 850063us   Trie: 181811us  Trie is better
```

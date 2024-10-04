<h1>C++ Implementation of the Whirlpool Hashing Function</h1>

This is a single header implementation of a branchless version of the Whirlpool hashing function written in modern idiomatic C++. All the required code is in `src/whirlpool.hpp`. For sample usage, see `tests/`.
This was written due to an almost complete lack of good whirlpool implementations in C++.


To verify for correctness, run `ninja build_verify && verify.py` (might take a while!).

Based on P.S.L.M. Barreto \& V. Rijmen's NESSIE submission.

## Usage
```
#include <string>
#include "whirlpool.hpp"
std::string str = "my_string_to_hash";
auto digest = whirlpool(str); // digest is of type std::array<uint64_t, 8>
```

## Install
copy the whirlpool.hpp header file into your project


## Misc


C++20 required (for concepts).

glibc and libstdc++ required.

Tested with g++/clang++

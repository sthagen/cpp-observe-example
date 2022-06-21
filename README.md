# cpp-observe-example

Experimental example of the C++17 observer implementation from Lars.

## Usage

Generate build files:

```console
❯ cmake -S . -B build
# ...
```

Build:

```console
❯ cmake --build build
[ 50%] Building CXX object CMakeFiles/observe_example.dir/main.cpp.o
[100%] Linking CXX executable observe_example
[100%] Built target observe_example
```

Execute example:

```console
❯ build/observe_example
A triggered
B triggered with meaning of life and 42
I witness C with 123
I witness C with 234
I witness C with 1
I witness C with 2
I witness C with 42
```

## Status

Experimental

**Note**: The default branch is `default`.

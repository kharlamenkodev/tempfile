# RAII file wrapper


[![Hits-of-Code](https://hitsofcode.com/github/kharlamenkodev/tempfile)](https://hitsofcode.com/view/github/kharlamenkodev/tempfile)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/kharlamenkodev/tempfile/blob/master/LICENSE)


Sometimes there are situations when it is necessary to create a temporary file that should be deleted at the moment of leaving the scope of the function. **Tempfile** solve this;

### Build and install

```bash
mkdir build && cd build
cmake ..
cmake --install .
```

### How to use:

In your CMakeLists.txt, write:

```
find_package(tempfile)
```
Then in your source files you can use 'tempfile' lib headers:

```cpp

#include <tempfile.hpp>

void foo()
{
    tempfile::TempFile file(std::string("test_file.json"));

    file << "test text and value (" << 23.0F << ')' << std::endl;
}

```
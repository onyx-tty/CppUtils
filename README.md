# CppUtils

A collection of personal C++ utilities for logging, string manipulation, and time math.

## Description

Available libraries:

* Log

* String

* Time

### Log

Configuration helper `setupLogging()` that pre-configures Qt logging patterns. It adds:

* Colored indicators for the type of logging message, namely:
`[FATAL]`, `[CRITICAL]`, `[WARNING]`, `[DEBUG]`, `[INFO]`.

* Class or namespace followed by the function name.

``` C++
class Printer {
private:
        template<typename T>
        static void printVar(T var) {
                QDEBUG() << "Variable:" << var;
        }
};

void anotherFunc() {
        Printer::printVar(5);
}
```

```
Output:

[DEBUG]    Printer::printVar : Variable: 5
```

Currently, only Qt logging backend is supported.

### String

#### StdString.h

Two variants for lower-casing and upper-casing std::string, one modifies in place, the other returns a new string.

Available functions: `toLower()`, `makeLower()`, `toUpper()`, `makeUpper()`

``` C++
using namespace string;

std::string str = "AbCdE";
toLower(str);        // str -> "abcde"

makeLower("STRING"); // return value -> "string"

toUpper(str);        // str -> "ABCDE"

makeUpper("string"); // return value -> "STRING"
```

#### QtString.h

Has function toQString(), which converts common types to QString:

``` C++
using namespace qt::string;

toQString(55);                 // -> QString("55")

toQString(std::string("abc")); // -> QString("abc")
```


### Time

Duration constants and time utilities.

Available constants: `minute`, `hour`, `day`, `week`

Available functions: `roundToMidnight()`, `todayMidnight()`, `closerToNow()`

``` C++
using namespace timing::posix;

roundToMidnight(timestamp); // returns midnight of given day

todayMidnight();            // shorthand for roundToMidnight(now)

closerToNow(t1, t2);        // returns timestamp closer to current time
```


### Building & Installation

#### Prerequisites

* `cmake`
* `ninja`
* `clang`
* `qt6-base` (CPPUTILS_ENABLE_QT=ON)

##### Arch Linux

``` sh
sudo pacman -Sy qt6-base cmake ninja clang
```

##### Ubuntu

``` sh
sudo apt install qt6-base-dev cmake ninja-build clang
```

#### Build from source

``` sh
# Configure (static linking recommended)
cmake --preset Release

# Build
cmake --build --preset Release
```

**For dynamic linking**, pass `-DBUILD_SHARED_LIBS=ON` during configuration.
Make sure `/your/installation/path/lib` is in `$LD_LIBRARY_PATH`, so that shared libraries are found by the executable.

#### Install

CPack is not supported at present; installation is manual.

``` sh
cmake --install build/Release --prefix /your/installation/path
```

#### Test

``` sh
ctest --preset Debug --output-on-failure
```

## Authors

* [onyx-tty](https://github.com/onyx-tty)

## License

This project is licensed under the MIT License — see the [LICENSE](./LICENSE) file for details

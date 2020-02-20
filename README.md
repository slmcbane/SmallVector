This single file repository is a utility that I have used across other C++
projects. It is a container with similar semantics to `std::vector`, but
without any dynamic memory allocation. Instead, as a template parameter
you specify the maximum number of elements the vector may hold.

In more detail, `smv::SmallVector<T, N, bool SizeCheck = true>` is a container 
holding at most `N` elements of type `T`. There is no dynamic memory
allocation. Many functions from the interface of `std::vector` are
available, but not all are implemented since I have added features only
as I use them. If the optional parameter `SizeCheck` is `false`, no checking
is performed to make sure that the vector's
size does not exceed `N`. If it is `true` (the default), an exception of type
`smv::MaxSizeExceeded` is thrown if an operation would exceed the maximum size.

## Author
Sean McBane (<sean.mcbane@protonmail.com>)

## Version
v1.0.3
### Update log
* 1.0.2 -> 1.0.3 Move from overwritten elements in erase.
* 1.0.1 -> 1.0.2 Update exception spec on emplace_back; was not compatible
with gcc
* 1.0.0 -> 1.0.1 Added smart exception specifications

## Copyright
Copyright 2020 The University of Texas at Austin.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to
deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
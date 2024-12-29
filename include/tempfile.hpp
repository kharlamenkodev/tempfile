/*
MIT License

Copyright (c) 2024 Igor Kharlamenko

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

#include <string>
#include <fstream>
#include <filesystem>

namespace tempfile {

class TempFile final : public std::ofstream
{
public:
    TempFile(const std::filesystem::path path)
        : TempFile(path.string())
    {}

    TempFile(const std::string path)
        : _path{path},
          std::ofstream(path)
    {}

    ~TempFile()
    {
        if (is_open()) {
            close();
        }

        if (std::filesystem::exists(_path)) {
            std::filesystem::remove(_path);
        }
    }

    TempFile(const TempFile& other) = delete;

    TempFile& operator=(const TempFile& other) = delete;

    TempFile(TempFile&& other)
        : std::ofstream(std::move(other)),
          _path{std::move(other._path)}
    {}

    TempFile& operator=(TempFile&& other)
    {
        std::ofstream::operator=(std::move(other));
        _path = std::move(other._path);

        return *this;
    }

private:
    std::string _path;
};

}  // namespace tempfile
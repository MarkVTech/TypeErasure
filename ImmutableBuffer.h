#pragma once

#include <cstddef>

class ImmutableBuffer
{
public:
    ImmutableBuffer() = delete;

    ImmutableBuffer(const char* buffer, std::size_t size);

    const char *data() const;

    std::size_t size() const;

private:
    const char* mBuffer;
    std::size_t mSize;
};

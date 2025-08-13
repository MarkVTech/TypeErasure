#include "MutableBuffer.h"

MutableBuffer::MutableBuffer(char* buffer, std::size_t size) :
    mBuffer(buffer),
    mSize(size)
{}

char* MutableBuffer::data() const { return mBuffer; }

std::size_t MutableBuffer::size()  { return mSize; }

MutableBuffer buffer(char* buffer, std::size_t size)
{
    return MutableBuffer(buffer, size);
}

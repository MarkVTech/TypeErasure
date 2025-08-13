#include "ImmutableBuffer.h"

ImmutableBuffer::ImmutableBuffer(const char * buffer, std::size_t size) :
    mBuffer(buffer),
    mSize(size)
{

}

const char *ImmutableBuffer::data() const
{
    return mBuffer;
}

std::size_t ImmutableBuffer::size() const
{
    return mSize;
}

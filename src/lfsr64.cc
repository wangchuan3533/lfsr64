#include <nan.h>
#include <stdint.h>
using namespace Nan;
using namespace v8;

const uint64_t mask = 0x1234567890123456;

inline uint64_t lfsr_next(uint64_t current)
{
	uint64_t bit = ((current >> 0) ^ (current >> 1) ^ (current >> 3) ^ (current >> 4)) & 1;
	return (current >> 1) | (bit << 63);
}


inline uint64_t bytes2uint64(const char *str)
{
    return *reinterpret_cast<const uint64_t *>(str);
}


NAN_METHOD(next)
{
	char *buffer = (char *)node::Buffer::Data(info[0]->ToObject());
    uint64_t *p_current = reinterpret_cast<uint64_t *>(buffer);
    uint64_t current = *p_current;
	current ^= mask;
	uint64_t next = lfsr_next(current);
	next ^= mask;
    *p_current = next;
}

NAN_MODULE_INIT(Init)
{
   Nan::Set(target, New<String>("next").ToLocalChecked(),
        GetFunction(New<FunctionTemplate>(next)).ToLocalChecked());
}

NODE_MODULE(lfsr64, Init)

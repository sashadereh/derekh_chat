#ifndef MESSAGE_FORMATS_H
#define MESSAGE_FORMATS_H

#include "utils.h"

enum MessageType
{
    MT_ENTER,
    MT_QUIT,
    MT_PING,
    MT_PONG,
    MT_TEXT,
    MT_FIRST = MT_ENTER,
    MT_LAST = MT_TEXT
};

/*
For example:
    struct MyStruct
    {
        unsigned char code; // 1 byte
        uint length; // 4 bytes
    };
    Compiler can "insert" 3-nil bytes between code and length in order the size of length will be the multiple of a pow(2).
*/
#pragma pack(push, 1)

// System message
struct MessageSys
{
    unsigned char code;
};

#define SZ_MESSAGE_SYS (sizeof(unsigned char))

// Text message
struct MessageText
{
    unsigned char code;
    uint length;
    // "open array", we don't know about size of data. This field will just have address in struct.
    wchar_t text[1];
};

#define SZ_MESSAGE_TEXT (SZ_MESSAGE_SYS + sizeof(uint))

#pragma pack(pop)

#endif // MESSAGE_FORMATS_H

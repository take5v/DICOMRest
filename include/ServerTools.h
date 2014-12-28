#ifndef SERVERTOOLS_H_INCLUDED
#define SERVERTOOLS_H_INCLUDED

#include <uuid/uuid.h>
#include <string>

static std::string GenerateUUID()
{
    uuid_t uuid;
    uuid_generate_random (uuid);
    char s[37];
    uuid_unparse (uuid, s);
    return s;
}

#endif // SERVERTOOLS_H_INCLUDED

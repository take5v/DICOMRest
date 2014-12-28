#ifndef SERVERCONTEXT_H
#define SERVERCONTEXT_H

#include <boost/noncopyable.hpp>

#include "FileStorage.h"
#include "Enumerations.h"
#include "ServerIndex.h"

class ServerContext: public boost::noncopyable
{
private:
    FileStorage& fileStorage_;
    ServerIndex& serverIndex_;

public:
    ServerContext(FileStorage& fileStorage, ServerIndex& serverIndex);
    virtual ~ServerContext();

    FileStorage& GetFileStorage();
    ServerIndex& GetIndex() { return serverIndex_; }
    StoreStatus Store(std::string& publicId, const std::string& data);
protected:
private:
};

#endif // SERVERCONTEXT_H

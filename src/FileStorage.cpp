#include "FileStorage.h"

#include <boost/thread/mutex.hpp>

#include "ServerTools.h"

FileStorage::FileStorage()
{
    //ctor
}

FileStorage::~FileStorage()
{
    for (NodeStorageType::iterator it = NodeStorage.begin(); it != NodeStorage.end(); ++it)
    {
        delete it->second;
    }
}

std::string FileStorage::AddFile(const char* buf, size_t size)
{
    boost::mutex::scoped_lock lock(mutex_);

    std::string uuid = GenerateUUID();
    FileNode* fileNode= new FileNode(buf, size);
    NodeStorage[uuid] = fileNode;
    return uuid;
}

const char* FileStorage::GetFile(std::string& uuid)
{
    boost::mutex::scoped_lock lock(mutex_);

    NodeStorageType::iterator it = NodeStorage.find(uuid);
    if (it != NodeStorage.end())
    {
        return it->second->GetData();
    }
    return 0;
}

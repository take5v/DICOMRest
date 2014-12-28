#ifndef FILESTORAGE_H
#define FILESTORAGE_H

#include <map>
#include <string>

#include <boost/thread.hpp>

#include "FileNode.h"

class FileStorage
{
private:
    typedef std::map<std::string, FileNode*> NodeStorageType;
    NodeStorageType NodeStorage;

    boost::mutex mutex_;
public:
    FileStorage();
    virtual ~FileStorage();

    std::string AddFile(const char* buf, size_t size);
    const char* GetFile(std::string& uuid);
protected:
private:
};

#endif // FILESTORAGE_H

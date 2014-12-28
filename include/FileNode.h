#ifndef FILENODE_H
#define FILENODE_H

#include <string>

class FileNode
{
private:
    const char* data;
    size_t size;
public:
    FileNode(const char* data_, size_t size_);
    virtual ~FileNode();

    const char* GetData();
protected:
private:
};

#endif // FILENODE_H

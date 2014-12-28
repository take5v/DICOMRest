#include "FileNode.h"

FileNode::FileNode(const char* data_, size_t size_):
    data(data_),
    size(size_)
{
    //ctor
}

FileNode::~FileNode()
{
    //dtor
}

const char* FileNode::GetData()
{
    return data;
}

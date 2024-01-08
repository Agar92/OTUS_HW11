#pragma once

#include <block_reader.h>

#include <fstream>
#include <string>
#include <vector>

class FileSplitter
{
public:
    FileSplitter(size_t blocks) : m_blocks_count(blocks) {}

    std::vector<FileBlockReader> split(const std::string& path);
private:
    size_t m_blocks_count;
};

#ifndef SIMDB_FILETYPE_HPP
#define SIMDB_FILETYPE_HPP

/**
 * 
 * Define the .simdb file type and how to create or read one
 * 
 */

#include <string>
#include <memory>
#include <stdexcept>
#include "database_stack.hpp"
#include "simdb_header.hpp"
#include "../Utils/utils.hpp"

namespace SimDB {
  /**
   * @brief Custom .simdb Database file
   * 
   * File Outline: 
   *  
   * Header: 
   *   Always starts with 0b0000'0000.
   *   Always ends with 0b1111'1111.
   *   1-byte tag blocks that determine which data type is stored at that location of the file.
   *   Strings are a 4-byte tag block.
   *
   * Structure: 
   * 
   * Header:
   * [0b0000'0000] [1-byte] [1-byte] [1-bytes][3-byte string size] [1-byte] [...] [0b1111'1111]
   * 
   * Data Segment:
   * [row_tag] [column_tag] [data] [data] [column_tag] [data] [data] [row_tag] [...]
   */
  class SimDBFile {
   private:
    /** Name of the .simdb file object */
    std::string _filename;
    std::unique_ptr<DatabaseStack> _database_stack;
  
    bool _isValidFilename(const std::string& filename);

   public:
    /** File extenstion of a .simdb file */
    static const std::string FILE_EXTENSION;
  
    SimDBFile(const std::string& filename);
  
    const bool saveFile();
    static const bool saveFile(const std::string& filename);
    const bool readFile();
    static const bool readFile(const std::string& filename, std::unique_ptr<DatabaseStack> database_stack);
  };
}

#endif // SIMDB_FILETYPE_HPP
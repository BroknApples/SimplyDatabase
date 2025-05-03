#include "simdb_filetype.hpp"

namespace SimDB {
  
/*************************************************************************/
/******************************** Private ********************************/
/*************************************************************************/

  /**
   * @brief Check if a filename is a valid .simdb filename
   * @param filename: Filename to check
   * @returns bool: True/False of valid filename
   */
  bool _isValidFilename(const std::string& filename) {
    // Check if it contains an invalid char
    if (stringContains(filename, "/")) {
      return false; 
    }

    return true;
  }

/*************************************************************************/
/******************************** Public *********************************/
/*************************************************************************/

  /** File extenstion of a .simdb file */
  const std::string SimDBFile::FILE_EXTENSION = ".simdb";

  /**
   * @brief Create new .simdb file object
   * @param filename: Name of the new file
   * @throws std::invalid_argument(Error:SimDB::INVALID_FILENAME)
   */
  SimDBFile::SimDBFile(const std::string& filename, const SimDBData& file_data) : _filename(""), _file_data(file_data) {
    // Check if the filename is valid : throw if invalid
    if (!_isValidFilename(filename)) {
      throw std::invalid_argument(Error::SimDBFile::INVALID_FILENAME);
    }

    _filename = filename;
  }

  /**
   * @brief Copy Constructor
   */
  SimDBFile::SimDBFile(const SimDBFile& other)
  : _filename(other._filename)
  , _file_data(other._file_data) {}

  /**
   * @brief Save a .simdb file
   * @returns bool: True/False of success
   */
  const bool saveFile() {


    return true;
  }

  /**
   * @brief Save a .simdb file, STATIC verison -- does NOT need a SimDBFile object to work
   * @param filename: Filename to save
   * @param database_stack: Database stack to save from
   * @returns bool: True/False of success
   */
  const bool saveFile(const std::string& filename, const SimDBData& file_data) {
    if (!_isValidFilename(filename)) return false;


    return true;
  }

  /**
   * @brief Read a .simdb file into a DatabaseStack
   * @returns bool: True/False of success
   */
  const bool readFile() {



    return true;
  }

  /**
   * @brief Read a .simdb file into a DatabaseStack, STATIC verison -- does NOT need a SimDBFile object to work
   * @param filename: Filename to save
   * @param database_stack: DatabaseStack data type to store information in
   * @returns bool: True/False of success
   */
  const bool readFile(const std::string& filename, const SimDBData& file_data) {
    if (!_isValidFilename(filename)) return false;


    return true;
  }
}

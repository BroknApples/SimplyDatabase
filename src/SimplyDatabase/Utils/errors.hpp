#ifndef ERRORS_HPP
#define ERRORS_HPP

/**
 * This file defines all error codes for different occurences in this Framework
 */

#include <string>

namespace SimDB {
  /**
   * @brief Error declarations for entire Simply Database codebase
   */
  namespace Error {
    /**
     * @brief Error declarations for the .simdb file type
     */
    namespace SimDBFile {
      const std::string INVALID_STRING_SIZE = "STRING_SIZE must be in the range: (0, 16,777,215)";
      const std::string INVALID_FILENAME = "Invalid filename entered. File cannot contain (/)"; // TODO: List all invalid filename chars here
    }
  }
}

#endif // ERRORS_HPP
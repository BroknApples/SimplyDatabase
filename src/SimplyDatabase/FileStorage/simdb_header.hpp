#ifndef SIMDB_HEADER_HPP
#define SIMDB_HEADER_HPP

/**
 * 
 * This file defines how the header of a .simdb file works
 * 
 * /**
 * Formatted as such:
 * [0x00000000] [1 byte] [1 byte] [0x11111111]
 * 
 */

#include <stdexcept>
#include "../Utils/utils.hpp"

namespace SimDB {
  /** Set size per header token in bits */
  constexpr unsigned int TOKEN_SIZE = Bits::BYTE;

  /**
   * @brief Defines different types present in the header of a .simdb file
   * along with a few helper constants
   */
  namespace HeaderTokens {
    enum Token : unsigned char {
      HEADER_START = 0x00,  /** 0b0000'0000 */
      BOOLEAN,
      CHAR,
      STRING,               /** NOTE: If a string occurs in the header, then the next 3 bytes of the header will define the string length */
      SHORT_INT,            /** 2-Bytes */
      INT,                  /** 4-Bytes */
      LONG_INT,             /** 8-Bytes */
      FLOAT,                /** IEEE-754 Single-Precision */
      DOUBLE,               /** IEEE-754 Double-Precision */
      HEADER_END = 0xFF     /** 0b1111'1111 */
    };

    constexpr int SHORT_INT_BYTE_SIZE = 2;  /** Bytes per short-int type */
    constexpr int INT_BYTE_SIZE = 4;        /** Bytes per int type */
    constexpr int LONG_INT_BYTE_SIZE = 8;   /** Bytes per long int type */
  };
  

  /**
   * @brief Calculate the numebr of bits in the data segment for the corresponding HeaderToken
   * @param TOKEN: Token to be evaluated
   * @param STRING_SIZE: Size of the String Token, IS NOT used if the token entered is not a string.
   *                     Given from the next 3 bytes after a String token occurs
   * @returns int: Number of bits in the data segment that each header token represents
   * @throws std::invalid_argument(SimDB::Error)
   */
  constexpr int getHeaderTokenBitSizeInDataSegment(const HeaderTokens::Token token, const unsigned int string_size = 0) {
    // STRING_SIZE must be in the range: (0, 16,777,215) (3-byte range)
    if (string_size < 0 || string_size > 0xFFFFFF) {
      throw std::invalid_argument(Error::SimDBFile::INVALID_STRING_SIZE);
    }

    switch(token) {
      case HeaderTokens::Token::BOOLEAN: {
        // Each bool is one bit
        return Bits::BIT;
      }
      case HeaderTokens::Token::CHAR: {
        // Each char is one byte
        return Bits::BYTE;
      }
      case HeaderTokens::Token::STRING: {
        // The number of bits in the code is the (size of the string) * (bits in a byte)
        return string_size * Bits::BYTE;
      }
      case HeaderTokens::Token::SHORT_INT: {
        // Each short int has a set byte size, multiply it with the bits in a byte
        return HeaderTokens::SHORT_INT_BYTE_SIZE * Bits::BYTE;
      }
      case HeaderTokens::Token::INT: {
        // Each int has a set byte size, multiply it with the bits in a byte
        return HeaderTokens::INT_BYTE_SIZE * Bits::BYTE;
      }
      case HeaderTokens::Token::LONG_INT: {
        // Each long int has a set byte size, multiply it with the bits in a byte
        return HeaderTokens::LONG_INT_BYTE_SIZE * Bits::BYTE;
      }
      case HeaderTokens::Token::FLOAT: {
        // Uses IEE-754 Single Precision, so 4-bytes or 32-bits
        return 4 * Bits::BYTE;
      }
      case HeaderTokens::Token::DOUBLE: {
        // Uses IEE-754 Double Precision, so 8-bytes or 64-bits
        return 8 * Bits::BYTE;
      }
    }

    // Return 0 by default as it is either a token that doesn't exist in the actual data
    // or it has not been defined yet
    return 0;
  }
  
  constexpr int getHeaderTokenBitSizeInDataSegment(const HeaderTokens::Token token, const unsigned int string_size = 0) {
    // STRING_SIZE must be in the range: (0, 16,777,215) (3-byte range)
    if (string_size < 0 || string_size > 0xFFFFFF) {
      throw std::invalid_argument(Error::SimDBFile::INVALID_STRING_SIZE);
    }

    switch(token) {
      case HeaderTokens::Token::BOOLEAN: {
        // Each bool is one bit
        return Bits::BIT;
      }
      case HeaderTokens::Token::CHAR: {
        // Each char is one byte
        return Bits::BYTE;
      }
      case HeaderTokens::Token::STRING: {
        // The number of bits in the code is the (size of the string) * (bits in a byte)
        return string_size * Bits::BYTE;
      }
      case HeaderTokens::Token::SHORT_INT: {
        // Each short int has a set byte size, multiply it with the bits in a byte
        return HeaderTokens::SHORT_INT_BYTE_SIZE * Bits::BYTE;
      }
      case HeaderTokens::Token::INT: {
        // Each int has a set byte size, multiply it with the bits in a byte
        return HeaderTokens::INT_BYTE_SIZE * Bits::BYTE;
      }
      case HeaderTokens::Token::LONG_INT: {
        // Each long int has a set byte size, multiply it with the bits in a byte
        return HeaderTokens::LONG_INT_BYTE_SIZE * Bits::BYTE;
      }
      case HeaderTokens::Token::FLOAT: {
        // Uses IEE-754 Single Precision, so 4-bytes or 32-bits
        return 4 * Bits::BYTE;
      }
      case HeaderTokens::Token::DOUBLE: {
        // Uses IEE-754 Double Precision, so 8-bytes or 64-bits
        return 8 * Bits::BYTE;
      }
    }

    // Return 0 by default as it is either a token that doesn't exist in the actual data
    // or it has not been defined yet
    return 0;
  }
}

#endif // SIMDB_HEADER_HPP
#ifndef DATA_SIZES_HPP
#define DATA_SIZES_HPP

/**
 * 
 * NOTE: This file declares sizes for different basic data types like Megabytes and Kilobytes
 * 
 */

#include <cstdint>

namespace SimDB {
  /**
   * @brief This namespace declares how many bits are in each data type
   * 
   * e.g.
   * Byte = 8 bits, KB = 1024 Bytes, etc.
   */
  namespace Bits {
    constexpr uint32_t BIT = 1;
    constexpr uint32_t BYTE = 8 * BIT;
    constexpr uint32_t KILOBYTE = 1024 * BYTE;
    constexpr uint32_t MEGABYTE = 1024 * KILOBYTE;
    constexpr uint64_t GIGABYTE = 1024 * MEGABYTE;
  }
}

#endif // DATA_SIZES_HPP
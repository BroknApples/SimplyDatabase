#ifndef STRING_UTILS_HPP
#define STRING_UTILS_HPP

/**
 * This file declares utility functions based on strings
 */

#include <string>
#include <string_view>

/**
 * @brief Check string for pattern
 * @param str: String to check if pattern exists in
 * @param pattern: Pattern to find in the string
 * @returns bool: True/False of if the pattern exists in the string
 */
const bool stringContains(const std::string& str, const std::string_view pattern) {
  const int STR_SIZE = str.length(); // Length of the strinig to check
  const int PATTERN_SIZE = pattern.length(); // Length of the pattern to find

  // Check string for pattern
  for (int i = 0; i < STR_SIZE - PATTERN_SIZE; i++) {
    const std::string SUBSTR = str.substr(i, i + PATTERN_SIZE);
    if (SUBSTR == pattern) return true;
  }

  return false;
}

#endif // STRING_UTILS_HPP
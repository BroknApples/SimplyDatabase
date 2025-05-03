#ifndef STRING_UTILS_HPP
#define STRING_UTILS_HPP

/**
 * 
 * This file declares utility functions based on strings
 * 
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
  const int STR_LENGTH = str.length(); // Length of the strinig to check
  const int PATTERN_LENGTH = pattern.length(); // Length of the pattern to find

  // Check string for pattern
  for (int i = 0; i < STR_LENGTH - PATTERN_LENGTH; i++) {
    const std::string SUBSTR = str.substr(i, i + PATTERN_LENGTH);
    if (SUBSTR == pattern) return true;
  }

  return false;
}

/**
 * @brief Change all characters to lowercase in a string
 * @param str: String to modify
 */
inline const void stringToLowercase(std::string& str) {
  for (auto& c : str) c = std::tolower(c);
}

/**
 * @brief Change all characters to uppercase in a string
 * @param str: String to modify
 */
inline const void stringToUppercase(std::string& str) {
  for (auto& c : str) c = std::toupper(c);
}

#endif // STRING_UTILS_HPP
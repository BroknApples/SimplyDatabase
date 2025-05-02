#ifndef DATABASE_STACK_HPP
#define DATABASE_STACK_HPP

/**
 * Defines the DatabaseStack type which is what all database information is stored in while the program is running
 */

#include <memory>
#include "simdb_header.hpp"

namespace SimDB {
  /**
   * @brief Data structure which stores all database information while the program is running. Doubly-Chained linked list
   */
  class DatabaseStack {
   private:
    /** Header token stored at this chain in the stack */
    HeaderTokens::Token _token;

    /** Pointer to a the next position above this in the stack */
    std::unique_ptr<DatabaseStack> _upper_stack;

    /** Pointer to the next position under this in the stack */
    std::unique_ptr<DatabaseStack> _lower_stack;

    /** Is this DatabaseStack chain link valid? */
    bool _valid;

   public:
    DatabaseStack();
    DatabaseStack(HeaderTokens::Token token);
    DatabaseStack(HeaderTokens::Token token, DatabaseStack* lower_stack);
    DatabaseStack(HeaderTokens::Token token, DatabaseStack* lower_stack, DatabaseStack* upper_stack);

    void pushToken(HeaderTokens::Token token);
    const long int getBitOffsetOfRow(HeaderTokens::Token row);
    const long int getBitOffsetOfColumnOfRow(HeaderTokens::Token row, HeaderTokens::Token column);
  };
}

#endif // DATABASE_STACK_HPP
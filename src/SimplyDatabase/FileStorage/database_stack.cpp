#include "database_stack.hpp"

namespace SimDB {
  
/*************************************************************************/
/******************************** Private ********************************/
/*************************************************************************/



/*************************************************************************/
/******************************** Public *********************************/
/*************************************************************************/

  /**
   * @brief Default constructor. Set to uninitilalized
   */
  DatabaseStack::DatabaseStack()
  : _upper_stack(nullptr)
  , _lower_stack(nullptr)
  , _valid(false) {}

  DatabaseStack::DatabaseStack(HeaderTokens::Token token)
    : _token(token)
    , _upper_stack(nullptr)
    , _lower_stack(nullptr)
    , _valid(true) {}
  
  DatabaseStack::DatabaseStack(HeaderTokens::Token token, DatabaseStack* lower_stack)
  : _token(token)
  , _upper_stack(nullptr)
  , _lower_stack(lower_stack)
  , _valid(true) {}

  DatabaseStack::DatabaseStack(HeaderTokens::Token token, DatabaseStack* lower_stack, DatabaseStack* upper_stack)
  : _token(token)
  , _upper_stack(upper_stack)
  , _lower_stack(lower_stack)
  , _valid(true) {}

  void DatabaseStack::pushToken(HeaderTokens::Token token) {
    if (!_valid) {
      _token = token;
    }
    else {
      _upper_stack = std::make_unique<DatabaseStack>(new DatabaseStack(token, this));
    }
  }

  const long int DatabaseStack::getBitOffsetOfRow(HeaderTokens::Token row) {
    // DatabaseStack is invalid, so don't even check
    if (!_valid) return 0;
  }

  const long int DatabaseStack::getBitOffsetOfColumnOfRow(HeaderTokens::Token row, HeaderTokens::Token column) {
    // DatabaseStack is invalid, so don't even check
    if (!_valid) return 0;
  }
}

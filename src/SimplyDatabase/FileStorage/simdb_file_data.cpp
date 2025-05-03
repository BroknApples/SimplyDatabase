#include "simdb_file_data.hpp"

namespace SimDB {

/*************************************************************************/
/******************************** Private ********************************/
/*************************************************************************/

  /**
   * @brief Refresh the table to include the correct amount of rows
   * NOTE: Simply sets the size of the table to the current '_row_count'
   */
  void SimDBData::_refreshTableRowSize() {
    _table_data.resize(_row_count);
  }

  /**
   * @brief Refresh the table to include the correct amount of columns in each row
   *  NOTE: Simply sets the size of the table rows to the current '_column_count'
   */
  void SimDBData::_refreshTableColumnSize() {
    for (auto& row : _table_data) {
      row.resize(_column_count);
    }
  }

/*************************************************************************/
/******************************** Public *********************************/
/*************************************************************************/

  /**
   * @brief Default Constructor. All values unintialized or set to 0
   */
  SimDBData::SimDBData()
  : _token_array()
  , _data_array()
  , _table_data()
  , _row_count(0)
  , _column_count(0) {}

  /**
   * @brief Initialize database with some size, data arrays still filled with 0
   * @param row_count: How many rows to have in the database
   * @param column_count: How many columns to have in the database
   */
  SimDBData::SimDBData(const size_t row_count, const size_t column_count)
  : _token_array()
  , _data_array()
  , _table_data()
  , _row_count(row_count)
  , _column_count(column_count) {}

  /**
   * @brief Copy constructor. Copy all values into a new object
   */
  SimDBData::SimDBData(const SimDBData& other)
  : _token_array(other._token_array)
  , _data_array(other._data_array)
  , _table_data(other._table_data)
  , _row_count(other._row_count)
  , _column_count(other._column_count) {}


  /**
   * @brief Set new row count of the table
   * @param row_count: New row count of the table
   * @returns bool: True/False of setting row count (Setting to a value less than the current row count displays a confirm message)
   */
  bool SimDBData::setRowCount(const size_t row_count) {
    if (row_count < _row_count) {
      std::cout << "Setting row count (" << row_count << ") to a value less than the current value (" << _row_count << ") may delete table data.\n"
                << "Do you wish to continue? (Enter 1 or Yes to confirm, enter anything else to deny): ";
      std::string input;
      std::cin >> input;

      // Clear buffer and add newline
      std::cout << std::endl;
      
      // Force lowercase string to compare with "yes"
      stringToLowercase(input);

      if (input == "1" || input == "yes") return false;
    }

    _row_count = row_count;
    _refreshTableRowSize();
  } 

  /**
   * @brief Set new column count of the table
   * @param column_count: New column count of the table
   * @returns bool: True/False of setting column count (Setting to a value less than the current column count displays a confirm message)
   */
  bool SimDBData::setColumnCount(const size_t column_count) {
    if (column_count < _column_count) {
      std::cout << "Setting column count (" << column_count << ") to a value less than the current value (" << _column_count << ") may delete table data.\n"
                << "Do you wish to continue? (Enter 1 or Yes to confirm, enter anything else to deny): ";
      std::string input;
      std::cin >> input;

      // Clear buffer and add newline
      std::cout << std::endl;
      
      // Force lowercase string to compare with "yes"
      stringToLowercase(input);

      if (input == "1" || input == "yes") return false;
    }

    _column_count = column_count;
    _refreshTableColumnSize();
  } 

  /**
   * @brief Add one more row to the table
   */
  void SimDBData::addRow() {
    _row_count++;
    _refreshTableRowSize();
  }

  /**
   * @brief Add some number of rows to the table
   */
  void SimDBData::addRows(const size_t additional_rows) {
    _row_count += additional_rows;
    _refreshTableRowSize();
  }

  /**
   * @brief Add one more column to the table
   */
  void SimDBData::addColumn() {
    _column_count++;
    _refreshTableColumnSize();
  }

  /**
   * @brief Add some number of columns to the table
   */
  void SimDBData::addColumns(const size_t additional_columns) {
    _column_count += additional_columns;
    _refreshTableColumnSize();
  }

  /**
   * @brief Remove a row from the end of the table
   */
  void SimDBData::removeRow() {
    _row_count--;
    _refreshTableRowSize();
  }

  /**
   * @brief Remove a row from the end of the table
   * @param index: Index to remove at
   */
  void SimDBData::removeRowAtIndex(const size_t index) {
    // TODO: Implement
  }

  /**
   * @brief Remove a colun from the end of the table
   */
  void SimDBData::removeColumn() {
    _column_count--;
    _refreshTableColumnSize();
  }

  /**
   * @brief Remove a row from the end of the table
   * @param index: Index to remove at
   */
  void SimDBData::removeColumnAtIndex(const size_t index) {
    // TODO: Implement
  }

  /**
     * @brief Get the entire row of data at some index
     * @param row: Row number to get data from
     * @returns vector<any>: Array of some data types
     * @throws std::invalid_argument() When row index is invalid
     */
    const std::vector<std::any>& SimDBData::getDataAtRow(size_t row) const {
      // Check if arguments are valid
      if (row < _row_count || row <= 0) {
        // Row entered was out of range
        const size_t STARTING_ROW_INDEX = (_row_count > 0) ? 1 : 0;
        const std::string ERR_STR = "Row out of range: (" + std::to_string(STARTING_ROW_INDEX) + ", " + std::to_string(_row_count) + ").";
        throw std::invalid_argument(ERR_STR);
      }

      // Remove one to index since indexing starts at 0 in this database framework
      row--;

      return _table_data[row];
    }

    /**
     * @brief Get the entire row of data at some index
     * @param row: Row number to get data from
     * @param column: Column number to get data from
     * @returns vector<any>: Array of some data types
     * @throws std::invalid_argument() When row or column index is invalid
     */
    const std::any& SimDBData::getDataAtPosition(size_t row, size_t column) const { 
      // Check if arguments are valid
      if (row < _row_count || row <= 0) {
        // Row entered was out of range
        const size_t STARTING_ROW_INDEX = (_row_count > 0) ? 1 : 0;
        const std::string ERR_STR = "Row out of range: (" + std::to_string(STARTING_ROW_INDEX) + ", " + std::to_string(_row_count) + ").";
        throw std::invalid_argument(ERR_STR);
      } 
      else if (column < _column_count || column <= 0) {
        // Column entered was out of range
        const size_t STARTING_COLUMN_INDEX = (_column_count > 0) ? 1 : 0;
        const std::string ERR_STR = "Column out of range: (" + std::to_string(STARTING_COLUMN_INDEX) + ", " + std::to_string(_column_count) + ").";
        throw std::invalid_argument(ERR_STR);
      }

      // Remove one to index since indexing starts at 0 in this database framework
      row--;
      column--;

      return _table_data[row][column];
    }

    /**
     * @brief Insert some data at a position in the database table
     * @param row: Row number to get data from
     * @param column: Column number to get data from
     * @param data: The data to insert at [row][column]
     * @throws std::invalid_argument() When row or column index is invalid
     */
    void SimDBData::insertDataAtPosition(size_t row, size_t column, const std::any& data) {
      // Check if arguments are valid
      if (row < _row_count || row <= 0) {
        // Row entered was out of range
        const size_t STARTING_ROW_INDEX = (_row_count > 0) ? 1 : 0;
        const std::string ERR_STR = "Row out of range: (" + std::to_string(STARTING_ROW_INDEX) + ", " + std::to_string(_row_count) + ").";
        throw std::invalid_argument(ERR_STR);
      } 
      else if (column < _column_count || column <= 0) {
        // Column entered was out of range
        const size_t STARTING_COLUMN_INDEX = (_column_count > 0) ? 1 : 0;
        const std::string ERR_STR = "Column out of range: (" + std::to_string(STARTING_COLUMN_INDEX) + ", " + std::to_string(_column_count) + ").";
        throw std::invalid_argument(ERR_STR);
      }

      // Remove one to index since indexing starts at 0 in this database framework
      row--;
      column--;

      _table_data[row][column] = data;
    }
}
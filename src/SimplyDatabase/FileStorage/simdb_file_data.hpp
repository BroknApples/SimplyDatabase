#ifndef SIMDB_FILE_DATA_HPP
#define SIMDB_FILE_DATA_HPP

/**
 * 
 * This file defines a class that stores all data from a database
 * 
 */

#include <iostream>
#include <string>
#include <any>
#include <vector>
#include "simdb_header.hpp"

namespace SimDB {
  /**
   * @brief Stores all data from a .simdb database, including the headertokens and raw data
   * 
   * NOTE: When indexing data, the table does not start at index '0', it starts at index '1'
   * so the more "common folk" can understand easily
   */
  class SimDBData {
   private:
    /** Header tokens array */
    std::vector<HeaderTokens::Token> _token_array;

    /** Array that stores all the data of the file */
    std::vector<unsigned char> _data_array;

    /** Holds all the data of the table in it's given rows + columns. Used to display the table state */
    std::vector<std::vector<std::any>> _table_data;

    size_t _row_count;     /** How many rows are in the table */
    size_t _column_count;  /** How many columns are in each row of the table */

    void _refreshTableRowSize();
    void _refreshTableColumnSize();

   public:
    SimDBData();
    SimDBData(const size_t row_count, const size_t column_count);
    SimDBData(const SimDBData& other);

    

    /**
     * @brief Get the number of rows in the database
     * @returns size_t: Row amount
     */
    const size_t getRowCount() const { return _row_count; }

    /**
     * @brief Get the number of columns in the database
     * @returns size_t: Column amount
     */
    const size_t getColumnCount() const { return _column_count; }

    /**
     * @brief Get the entire database table
     * @returns const-qualified vector<vector<any>>: 2D Array of data
     */
    const std::vector<std::vector<std::any>>& getTable() const { return _table_data; }

    bool setRowCount(const size_t row_count);
    bool setColumnCount(const size_t column_count);

    void addRow();
    void addRows(const size_t additional_rows);
    void addColumn();
    void addColumns(const size_t additional_columns);

    void removeRow();
    void removeRowAtIndex(const size_t index);
    void removeColumn();
    void removeColumnAtIndex(const size_t index);

    const std::vector<std::any>& getDataAtRow(size_t row) const;
    const std::any& getDataAtPosition(size_t row, size_t column) const;
    void insertDataAtPosition(size_t row, size_t column, const std::any& data);
  };  
}

#endif // SIMDB_FILE_DATA_HPP
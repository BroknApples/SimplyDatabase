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
   */
  class SimDBData {
   private:
    /** Header tokens array */
    std::vector<HeaderTokens::Token> _token_array;

    /** Array that stores all the data of the file */
    std::vector<unsigned char> _data_array;

    /** Holds all the data of the table in it's given rows + columns. Used to display the table state */
    std::vector<std::vector<std::any>> _table_data;

    int _row_count;     /** How many rows are in the table */
    int _column_count;  /** How many columns are in each row of the table */

    void _refreshTableRowSize();
    void _refreshTableColumnSize();

   public:
    SimDBData();
    SimDBData(const int row_count, const int column_count);
    SimDBData(const SimDBData& other);

    /**
     * @brief Get the number of rows in the database
     * @returns int: Row amount
     */
    const int getRowCount() const { return _row_count; }

    /**
     * @brief Get the number of columns in the database
     * @returns int: Column amount
     */
    const int getColumnCount() const { return _column_count; }

    /**
     * @brief Get the entire database table
     * @returns const-qualified vector<vector<any>>: 2D Array of data
     */
    const std::vector<std::vector<std::any>>& getTable() const { return _table_data; }

    bool setRowCount(const int row_count);
    bool setColumnCount(const int column_count);

    void addRow();
    void addRows(const int additional_rows);
    void addColumn();
    void addColumns(const int additional_columns);

    void removeRow();
    void removeRowAtIndex(const int index);
    void removeColumn();
    void removeColumnAtIndex(const int index);

    const std::vector<std::any> getDataAtRow(const int row);
    const std::any getDataAtPosition();
    void insertAtPosition(const int row, const int column);
  };  
}

#endif // SIMDB_FILE_DATA_HPP
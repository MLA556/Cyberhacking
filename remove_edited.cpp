#include <iostream>
#include <sqlite3.h>
#include <string>
#include <vector>
#include <cstdlib>

// Function to handle SQLite errors
void checkSqliteError(int rc, const std::string& context) {
    if (rc != SQLITE_OK) {
        std::cerr << "SQLite Error in " << context << ": " << sqlite3_errmsg(sqlite3_db_handle(nullptr)) << std::endl;
        // Note: In a real app, you'd pass the db handle to get specific error.
        exit(1);
    }
}

// Function to execute SQL and return results
std::vector<std::string> executeQuery(sqlite3* db, const std::string& sql) {
    std::vector<std::string> results;
    char* errMsg = nullptr;
    int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);
    
    if (rc != SQLITE_OK) {
        std::cerr << "SQL Error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Query executed successfully." << std::endl;
    }
    return results;
}

// Function to clear edit keys from messages
void removeEditedLabel(sqlite3* db) {
    // SQL to update the messages table.
    // We set edit_key_from_me and edit_key_to_me to NULL.
    // This removes the "Edited" tag for both sent and received messages.
    
    const char* sql = 
        "UPDATE messages "
        "SET edit_key_from_me = NULL, "
        "    edit_key_to_me = NULL, "
        "    edit_version = NULL "
        "WHERE edit_key_from_me IS NOT NULL OR edit_key_to_me IS NOT NULL;";

    char* errMsg = nullptr;
    int rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        std::cerr << "Failed to update messages: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Successfully cleared 'Edited' labels from all messages." << std::endl;
        
        // Verify the number of rows affected
        int changes = sqlite3_changes(db);
        std::cout << "Rows updated: " << changes << std::endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <path_to_msgstore.db>" << std::endl;
        return 1;
    }

    const char* dbPath = argv[1];
    sqlite3* db;
    int rc;

    // Open the database
    rc = sqlite3_open(dbPath, &db);
    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    } else {
        std::cout << "Opened database successfully: " << dbPath << std::endl;
    }

    // Optional: Check if the table exists and has the right columns
    // This is a basic check. In production, you might want to query sqlite_master.
    
    // Remove the edited labels
    removeEditedLabel(db);

    // Close the database
    rc = sqlite3_close(db);
    if (rc != SQLITE_OK) {
        std::cerr << "Error closing database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    } else {
        std::cout << "Database closed successfully." << std::endl;
    }

    return 0;
}

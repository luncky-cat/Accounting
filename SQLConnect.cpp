#ifndef MYSQL_CONNECTION_H
#define MYSQL_CONNECTION_H

#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>
using namespace std;

class MySQLConnection {
public:
    // 获取唯一的数据库连接实例
    static MySQLConnection& getInstance(const std::string& host = "tcp://127.0.0.1:3306",
        const std::string& user = "root",
        const std::string& password = "root",
        const std::string& database = "LedgerDatabase") {
        static MySQLConnection instance(host, user, password, database);
        return instance;
    }

    // 执行查询并返回结果集
    sql::ResultSet* executeQuery(const std::string& query) {
        try {
            sql::Statement* stmt = con->createStatement();
            return stmt->executeQuery(query);
        }
        catch (sql::SQLException& e) {
            std::cerr << "Query Error: " << e.what() << std::endl;
            return nullptr;
        }
    }

    // 执行删除并返回结果
    sql::ResultSet* DeleteById(const std::string& querys) {
        string query = "DELETE FROM OverheadItems WHERE itemID=" + querys;
        try {
            sql::Statement* stmt = con->createStatement();
            return stmt->executeQuery(query);
        }
        catch (sql::SQLException& e) {
            std::cerr << "Query Error: " << e.what() << std::endl;
            return nullptr;
        }
    }


private:
    // 私有构造函数，确保只能通过 getInstance() 创建实例
    MySQLConnection(const std::string& host, const std::string& user, const std::string& password, const std::string& database) {
        try {
            driver = sql::mysql::get_mysql_driver_instance();
            con = driver->connect(host, user, password);
            con->setSchema(database);
        }
        catch (sql::SQLException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    // 私有拷贝构造函数和赋值操作符，禁止拷贝
    MySQLConnection(const MySQLConnection&) = delete;
    MySQLConnection& operator=(const MySQLConnection&) = delete;

    // 析构函数，释放连接资源
    ~MySQLConnection() {
        delete con;
    }

    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;
};
#endif // MYSQL_CONNECTION_H

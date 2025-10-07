#pragma once
#include <string>
#include <vector>
#include <pqxx/pqxx>


class SqlQuery
{
public:
    std::vector<std::string> columns;

    std::string from;

    std::vector<std::pair<std::string, std::string>> where;

};


class SqlSelectQueryBuilder
{
private:
    SqlQuery sqlquery_;

    public:

    SqlSelectQueryBuilder();

    SqlSelectQueryBuilder& AddColumn(std::string columnName);

    SqlSelectQueryBuilder& AddFrom(std::string from);

    SqlSelectQueryBuilder& AddWhere(std::string columnName, std::string value);

    std::string BuildQuery();
};


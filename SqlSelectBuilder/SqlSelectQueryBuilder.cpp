#include "SqlSelectQueryBuilder.h"


SqlSelectQueryBuilder::SqlSelectQueryBuilder()
{

};

SqlSelectQueryBuilder &SqlSelectQueryBuilder::AddColumn(std::string columnName)
{
    sqlquery_.columns.push_back(columnName);
    return *this;
}

SqlSelectQueryBuilder &SqlSelectQueryBuilder::AddFrom(std::string from)
{
    sqlquery_.from = from;
    return *this;
}

SqlSelectQueryBuilder &SqlSelectQueryBuilder::AddWhere(std::string columnName, std::string value)
{
    sqlquery_.where.push_back(std::make_pair(columnName, value));
    return *this;
}

std::string SqlSelectQueryBuilder::BuildQuery() {
    std::string query = "SELECT ";
    if (sqlquery_.columns.empty())
    {
        query += " * FROM";
    }
    else
    {
        for (int i = 0; i < sqlquery_.columns.size() - 1; i++)
        {
            query +=  sqlquery_.columns[i] + " , ";
        }
        query +=  sqlquery_.columns[sqlquery_.columns.size() - 1] + " FROM";
    }

    query += " " + sqlquery_.from + " WHERE ";

    for (int i = 0; i < sqlquery_.where.size() - 1; i++)
    {
        query +=  sqlquery_.where[i].first + " = " + sqlquery_.where[i].second + " AND ";
    }
    query +=  sqlquery_.where[sqlquery_.where.size() - 1].first + " = " + sqlquery_.where[sqlquery_.where.size() - 1].second;



    query += ";";
    return query;
}

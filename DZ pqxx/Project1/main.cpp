#include <iostream>
#include <pqxx/pqxx>

using namespace std;

class ControlDB
{
private:
	pqxx::connection&  Con;
public:
	
	
	ControlDB(pqxx::connection &Connect) : Con(Connect)
	{
	};

	void createDB()
	{
		pqxx::work tx(Con);

		tx.exec("create table if not exists User_ ("
		"id SERIAL PRIMARY KEY, first_name VARCHAR(60), last_name VARCHAR(60), email VARCHAR(60)); ");
		tx.exec("create table if not exists Phone ("
		" id SERIAL PRIMARY KEY, phone_number VARCHAR(60), id_user INTEGER REFERENCES User_(id)); ");
		tx.commit();
	}

	void DropDB()
	{
		pqxx::work tx(Con);
		tx.exec("DROP TABLE IF EXISTS Phone;");
		tx.exec("DROP TABLE IF EXISTS User_;");
	}

	void newClient(string first_name, string last_name, string email)
	{
		pqxx::work tx(Con);
		tx.exec("insert into User_(first_name, last_name, email)"
		"VALUES('" + tx.esc(first_name) + "','" + tx.esc(last_name) + "','" + tx.esc(email) + "')");
		tx.commit();
	}

	void newPhone(string phone_number, string OwnerID)
	{
		pqxx::work tx(Con);
		tx.exec("insert into Phone(phone_number, id_user)"
			"VALUES('" + tx.esc(phone_number) + "'," + tx.esc(OwnerID) + ")");
		tx.commit();
	}

	void setClient(string ClientID , string first_name = "", string last_name = "", string email = "")
	{
		pqxx::work tx(Con);
		tx.exec("UPDATE User_ SET first_name = '" + tx.esc(first_name) + "', last_name = '" +
		tx.esc(last_name) + "', email = '" + tx.esc(email) + "' WHERE " + "id =" + tx.esc(ClientID) + " ;");
		tx.commit();
	}

	void deletePhone(string PhoneID = "", string phone_number = "", string OwnerID = "")
	{
		pqxx::work tx(Con);
		string query = "DELETE FROM Phone WHERE ";
		vector<string> conditions;

		if (!PhoneID.empty()) {
			conditions.push_back("id = " + tx.quote(PhoneID));
		}

		if (!phone_number.empty()) {
			conditions.push_back("phone_number = " + tx.quote(phone_number));
		}

		if (!OwnerID.empty()) {
			conditions.push_back("id_user = " + tx.quote(OwnerID));
		}

		if (conditions.empty()) {
			cout << "0 params" << endl;
			tx.commit();
			return;
		}

		for (size_t i = 0; i < conditions.size(); ++i) {
			if (i != 0) {
				query += " OR ";
			}
			query += conditions[i];
		}

		tx.exec(query);
		tx.commit();
	}

	void deleteClient(string ClientID = "", string first_name = "", string last_name = "", string email = "")
	{
		pqxx::work tx(Con);

		string query = "DELETE FROM User_ WHERE ";
		bool firstCondition = true;

		if (!ClientID.empty()) {
			query += "id = " + tx.esc(ClientID);
			firstCondition = false;
		}

		if (!first_name.empty()) {
			if (!firstCondition) query += " OR ";
			query += "first_name = " + tx.esc(first_name);
			firstCondition = false;
		}

		if (!last_name.empty()) {
			if (!firstCondition) query += " OR ";
			query += "last_name = " + tx.esc(last_name);
			firstCondition = false;
		}

		if (!email.empty()) {
			if (!firstCondition) query += " OR ";
			query += "email = " + tx.esc(email);
			firstCondition = false;
		}

		if (firstCondition) {
			cout << "0 params" << endl;
			tx.commit();
			return;
		}

		query += ";";
		tx.exec(query);
		tx.commit();
		
	}

	pqxx::result findClient(string first_name = "",string last_name = "", string email = "", string phone_number = "") {
		pqxx::work tx(Con);
		string query = R"(
        SELECT u.* FROM User_ u
        LEFT JOIN Phone p ON u.id = p.id_user
        WHERE 1=1
    )";

		
		if (!first_name.empty()) {
			query += " AND u.first_name = " + tx.quote(first_name);
		}
		if (!last_name.empty()) {
			query += " AND u.last_name = " + tx.quote(last_name);
		}
		if (!email.empty()) {
			query += " AND u.email = " + tx.quote(email);
		}
		if (!phone_number.empty()) {
			query += " AND p.phone_number = " + tx.quote(phone_number);
		}

		query += " LIMIT 1;";
		return tx.exec(query);
	}
};


int main()
{
	setlocale(LC_ALL, "rus");
	try
	{
		pqxx::connection c(
			"host=localhost "
			"port=5432 "
			"dbname=homework "
			"user=postgres "
			"password=11111111");
		
		if (!c.is_open()) {
			cerr << "Connection failed!" << endl;
			return 1;
		}

		ControlDB a(c);
	
		a.createDB();

		


		return 0;
	}
	catch (pqxx::sql_error e)
	{
		std::cout << e.what() << std::endl;
	}
}
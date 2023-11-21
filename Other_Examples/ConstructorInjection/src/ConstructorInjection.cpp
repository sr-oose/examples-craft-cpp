#include <iostream>

using namespace std;

class AbstractConnection {
public:
	virtual void send(std::string& str) = 0;
	virtual ~AbstractConnection() = default;
};

class ProdConnection : public AbstractConnection {
public:
	virtual void send(std::string& str) override {
		// send string
	}
};

class TestConnection : public AbstractConnection {
	virtual void send(std::string& str) override {
		// do nothing
	}
};

class DataTransmitter {
public:
	DataTransmitter(AbstractConnection& connection) : _connection(connection) { }

	void transmitData(){
		std::string data = "";
		_connection.send(data);
	}

private:
	AbstractConnection& _connection;
};


int main() {
	TestConnection conn;
	DataTransmitter transmitter(conn);
	transmitter.transmitData();
	return 0;
}

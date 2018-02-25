#include <iostream>

using namespace std;

class Connector {
protected:
    int status = 0;
public:
    virtual int check() = 0;
};

class Transmitter: protected Connector {
};

class Receiver: protected Connector {
};

class Socket: Transmitter, Receiver {
public:
    int check() {
        return status;
    }
};

int main()
{
    Socket* s = new Socket();
    s->check();
    return 0;
}

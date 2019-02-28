#include <iostream>

using namespace std;

class Connector {
protected:
    int status = 0;

public:
    virtual int check() = 0;
    virtual ~Connector() { }
};

class Transmitter: virtual protected Connector {
};

class Receiver: virtual protected Connector {
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
    delete s;
    return 0;
}

#ifndef ADT_H
#define ADT_H

#include <string>
using namespace std;

//ADT abstract class
class ADT {
public:
    //Returns the type of the ADT
    virtual string type() = 0;

    //Returns the size of the ADT
    virtual uint32_t length() = 0;
};

#endif
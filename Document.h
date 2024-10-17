#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>
class Document
{
private:
    std::string name;
    int id;
    int license_limit;

public:
    
    Document(std::string name, int id, int license_limit);
    bool borrow();
    void returnCopy();

    //encapsulate method
    int getid() const;
    int get_license_limit();

};
#endif
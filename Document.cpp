#include "Document.h"

Document::Document(std::string name, int id, int license_limit) 
                : name(name), id(id), license_limit(license_limit) {}

//check if can borrow or not
bool Document::borrow() {
    if (license_limit > 0) {
        license_limit--;
        return true;
    }
    return false;
}

void Document::returnCopy() {
    license_limit++;
}

int Document::getid() const {
    return id;
}

int Document::get_license_limit() {
    return license_limit;
}
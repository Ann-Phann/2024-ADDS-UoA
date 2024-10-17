#ifndef DOCUMENTMANAGER_H
#define DOCUMENTMANAGER_H

#include "Document.h"
#include <string>
#include <unordered_map>
#include <unordered_set>
class DocumentManager
{
private:
    //maps document name and id
    std::unordered_map <std::string, int> documentName_ID;

    //store document objects by id
    std::unordered_map <int, Document> storeDocument;

    //store patron ID
    std::unordered_set <int> patrons;

    //store borrow document
    //std::unordered_map<
 
public:
    void addDocument(std::string name, int id, int license_limit);

    void addPatron(int patronID);

    int search(std::string name); // returns docid if name is in the document collection or 0 if the name is not in the collection

    bool borrowDocument(int docid, int patronID);  // returns true if document is borrowed, false if it can not be borrowed (invalid patronid or the number of copies current borrowed has reached the license limit)

    void returnDocument(int docid, int patronID);
};
#endif
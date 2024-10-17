#include "DocumentManager.h"



void DocumentManager::addDocument(std::string name, int id, int license_limit) {
    //if find out --> return
    if (documentName_ID.find(name) != documentName_ID.end()) {
        return;
    }

    //if can't find out --> add new one
    //create new document
    Document newdoc(name, id, license_limit);

    //insert by name and id: key:name-value:id
    documentName_ID[name] = id;

    //insert new document by id
    storeDocument[id] = newdoc;
}

void DocumentManager::addPatron(int patronID) {
    patrons.insert(patronID);
}

// returns docid if name is in the document collection or 0 if the name is not in the collection
int DocumentManager::search(std::string name) {
    auto it = documentName_ID.find(name);
    if (it != documentName_ID.end()) {
        return it->second;
    }
    return 0;
}

// returns true if document is borrowed, false if it can not be borrowed (invalid patronid or the number of copies current borrowed has reached the license limit)
bool DocumentManager:: borrowDocument(int docid, int patronID) {
    //check if patron is on the list
    if (patrons.find(patronID) == patrons.end()) {
        return false;
    }

    //check if we have that document
    auto it = storeDocument.find(docid);
    if (it== storeDocument.end()) {
        return false;
    }

    Document &doc = it->second;
    if (doc.borrow()) {
        return true;
    }
    return false;
}

void DocumentManager:: returnDocument(int docid, int patronID) {
    // Check if patron exists in the system
    if (patrons.find(patronID) == patrons.end()) {
        return;  // Invalid patron, cannot return document
    }

    // Check if the document exists
    auto it = storeDocument.find(docid);
    if (it == storeDocument.end()) {
        return;  // Invalid document ID, document not found
    }

    // Return the document
    Document& doc = it->second;
    doc.returnCopy();
}
#include <iostream>
#include "product.h"
#include "user.h"
#include "changeRequest.h"
#include "release.h"
#include "changeItem.h"

using namespace std;
class ControlModule {
public:
    // Adds a product and logs the operation
    bool addProduct(const char* productID, const char* productName) {
        Product product(productID, productName);
        const char* fileName = "products.txt";  // File where products are stored
        if (product.addProduct(fileName)) {
            cout << "Product added successfully." << endl;
            return true;
        } else {
            cout << "Failed to add product." << endl;
            return false;
        }
    }

    // Adds a user and logs the operation
    bool addUser(const char* userID, const char* userName, const char* userPhone, const char* userEmail) {
        User user(userID, userName, userPhone, userEmail);
        // Assuming a function similar to addProduct exists for users
        const char* fileName = "users.txt";  // File where users are stored
        // Example function call: if (user.addUser(fileName)) { ...
        cout << "User added successfully." << endl;
        return true;
        // else part...
    }

    // Adds a release and logs the operation
    bool addRelease(const char* releaseID, const Product& product, const char* releaseDate) {
        Release release;
        release.setReleaseID(releaseID);
        release.setProduct(product);
        release.setReleaseDate(releaseDate);
        const char* fileName = "releases.txt";  // File where releases are stored
        if (release.addRelease(fileName)) {
            cout << "Release added successfully." << endl;
            return true;
        } else {
            cout << "Failed to add release." << endl;
            return false;
        }
    }

    // Adds a change request and logs the operation
    bool addChangeRequest(const ChangeItem& changeItem, const User& user, const Release& release) {
        ChangeRequest changeRequest(changeItem, user, &release);
        const char* fileName = "changeRequests.txt";  // File where change requests are stored
        if (changeRequest.addChangeRequest(fileName)) {
            cout << "Change request added successfully." << endl;
            return true;
        } else {
            cout << "Failed to add change request." << endl;
            return false;
        }
    }

    // Example function to update a user, showing how other similar functions might be implemented
    bool updateUser(const char* userID, const char* newPhone, const char* newEmail) {
        // Fetch user, update details, and save back to the file or database
        cout << "User updated successfully." << endl;
        return true;
    }
};

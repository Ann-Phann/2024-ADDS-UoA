// #include <vector>
// #include <iostream>
// #include <algorithm>
// template <typename T>
// class ADT_example {
// private:
//     std::vector <T> items;

// public:
//     void addItem(T item) {
//         items.push_back(item);
//     }

//     //return the item that was removed
//     T removeItem(T item) {
//         auto search = std::find(items.begin(), items.end(), item);
//         if(search != items.end()) {
//             items.erase(search);
//         }
//         return item;
//     }


//     T another_removeItem(T item) {
//         for (int i = 0; i <items.size(); i++) {
//             if(items[i] == item) {
//                 items.erase(items.begin() + i);
//                 break;
//             }
//         }
//         return item;
//     }
//     //randomly remove an item from the bag
//     T removeItem() {
//         int random = rand() % items.size();
//         //get item at random index
//         T item = items[random];
//         //remove item from the bag
//         items.erase(items.begin() + random);
//         return item;
//     }
// };

// int main () {
//     ADT_example<int> bag;
//     bag.addItem(1);
//     bag.addItem(2);
//     bag.addItem(3);
//     bag.addItem(4);
//     bag.addItem(5);

//     std::cout << bag.removeItem(2) << std::endl;
//     //std::cout << bag.removeItem() << std::endl;
//     std::cout << bag.another_removeItem(4) << std::endl;
//     return 0;
// }

//redo the BagOfHolding class using a vector

#include <vector>
#include <algorithm>
#include <iostream>
template <class T>
class ADT_example {
private: 
    std::vector<T> items;

public:
    void addItem(T item) {
        items.push_back(item);
    }

    void removeItem(T item) {
        if (items.empty()) {
            throw std::out_of_range("No items to remove");
        }
        for (int pos = 0; pos < items.size(); pos++) {
            if(items[pos] == item)
            {
                items.erase(items.begin() + pos);
                break;
            }
        }
    }

    T remove(T item) {
        if (items.empty()) {
            throw std::out_of_range("No items to remove");
        }
        auto search = std::find(items.begin(), items.end(), item);
        if(search != items.end()) {
            items.erase(search);
        }
        return item;
    }

    T remove() {
        if (items.empty()) {
            throw std::out_of_range("No items to remove");
        }

        int random = rand() % items.size();
        T choose_item = items[random];
        items.erase(items.begin() + random);
        return choose_item;
    }

    size_t size() {
        return items.size();
    }

    //allows instances of your class to be indexed like arrays
    T& operator[] (int index) {
        return items[index];
    }
    //operator[]: This is the name of the function. In C++, operator[] is a special member function that is used to overload the array subscript operator [].
};

int main ()
{
    ADT_example<int> bag;
    bag.addItem(1);
    bag.addItem(2);
    bag.addItem(3);
    bag.addItem(4);

    bag.removeItem(1);
    std::cout << "size: " << bag.size() << std::endl;
    for (int i = 0; i < bag.size(); i++) {
        std::cout <<bag[i] << " ";
    }
    std:: cout << "\n";
    std::cout << bag.remove(2) << std::endl;
    std::cout << bag.remove() << std::endl;
    std::cout << "size: " << bag.size() << std::endl;
    
    return 0;
}
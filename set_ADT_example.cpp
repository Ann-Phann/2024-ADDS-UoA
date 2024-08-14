#include <iostream>
#include <vector>
#include <unordered_map>

#include <chrono> // use to measure the time taken to run the code
template <typename T>

class Set{
private:
    //helper functions need to put in private access specifier
    virtual bool isMember(T value) = 0;
public:
    virtual void add(T value) = 0;
    virtual void remove(T value) = 0;
    virtual size_t size() = 0;
};

template <typename T>
class VectorSet :public Set<T> {
private:
    std::vector<T> members;

    bool isMember(T value) {
        for (auto current_value : this->members){
            if (current_value == value) {
                return true;
            }
        }
        return false;
    }
public:
    void add(T value) {
        if(!isMember(value)) {
            this->members.push_back(value);
        }
    }

    void remove(T value) {
        for (int pos = 0; pos < this->members.size(); pos++) {
            if (this->members.at(pos) == value) {
                this->members.erase(this->members.begin() + pos);
                break;
            }
        }
    }

    size_t size() {
        return this->members.size();
    }

};

//if there r thousands of new values being added, we use map for more efficient 
template <typename T>
class MapSet :public Set<T> {
private:
    std::unordered_map <T, int> members;

    bool isMember(T value) {
        auto it = this->members.find(value);
        if(it != this->members.end()) {
            return true;
        }
        return false;
    }

public:
    void add(T value){
        if(!isMember(value))
        {
            this->members.insert({value,1});
        }
    }

    void remove(T value) {
        auto it = this->members.find(value);

        if (it != this->members.end()) {
            this->members.erase(it);
        }
    }

    size_t size() {
        return this->members.size();
    }
};

int main () {
    //Set<int>* set = new VectorSet<int>();
    Set<int>* set = new MapSet<int>(); 
    // set->add(1);
    // set->add(2);
    // set->add(3);
    // set->add(3);

    // std::cout << set->size() << std::endl; //3
    // set->remove(2);
    // std::cout << set->size() << std::endl; //2


    //test map set
    //Set<int>* mapset = new MapSet<int>(); 
    // mapset->add(10);
    // mapset->add(20);
    // mapset->add(30);

    auto start = std::chrono::high_resolution_clock::now();

    //add 1000 values to the set
    for (int i = 0; i < 1000; i++)
    {
        set->add(i+1);
    }
    //get ending timepoint
    auto stop = std::chrono::high_resolution_clock::now();

    //get duration. substract timepoints to get duration
    //to cast it to proper unit --> use duration cast method
    auto duration = std::chrono::duration_cast<std::chrono::microseconds> (stop - start);
    std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;

    std::cout << set->size() << std::endl; //1000
}
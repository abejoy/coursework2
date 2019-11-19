#include <iostream>
#include "BiArray.h"

// default constructor
BiArray::BiArray(): size(0), currentCapacity(INITIALCAP){
    data = new int[getCapacity()];
    emptyHead = getCapacity()/2;
    emptyTail = getCapacity()/2;
    data += getCapacity()/2;
}

// value constructor
BiArray::BiArray(int arr[], int size) : size(size), emptyHead(size), emptyTail(size), currentCapacity((LO_THRESHOLD*size > INITIALCAP) ? LO_THRESHOLD*size : INITIALCAP){
    // IMPLEMENT ME
    data = new int[getCapacity()];
    int initMiddle = getSize();
    if(getSize() == 1){
        initMiddle = getCapacity()/2;
    }

    data += initMiddle;

    for(int i = 0; i < size; i++){
        *(data+i) =  arr[i];
    }
}

// destructor
BiArray::~BiArray() {
}

// copy constructor
BiArray::BiArray(const BiArray &other): size(other.getSize()), currentCapacity(other.getCapacity()), emptyHead(other.getHeadEmptyCount()), emptyTail(other.emptyTail){
    data = new int[getCapacity()];
    for(int i = 0; i < getCapacity(); i++){
        if(i >= getHeadEmptyCount() && i < getHeadEmptyCount() + getSize()){
            *(data+i) = *(other.data - other.getHeadEmptyCount() +i);
        }
    }
    data += getHeadEmptyCount();

/*    size = other.size;
    currentCapacity = other.currentCapacity;


    //Create new array
    data = new int[currentCapacity];

    //copy values of other array into new arr_
    for(int i = 0; i < size; i++){
        data[i] = other.data[i];
    }*/

}

// move constructor
BiArray::BiArray(BiArray &&other) {
    size = other.size;
    currentCapacity = other.currentCapacity;
    emptyHead = other.getHeadEmptyCount();
    emptyTail = other.emptyTail;

    //Create new array
    data = new int[currentCapacity];

    //copy values of other array into new arr_
    for(int i = 0; i < size; i++){
        data[i] = other.data[i];
    }

    other.~BiArray();
}

// copy assignment
BiArray &BiArray::operator=(const BiArray &other) {
    // IMPLEMENT ME
    // below are just stub code
    BiArray &removeMe = *this;
    return removeMe;
}

// move assignment
BiArray &BiArray::operator=(BiArray &&other) {
    // IMPLEMENT ME
    // below are just stub code
    BiArray &removeMe = *this;
    return removeMe;
}

bool BiArray::get(int i, int &v) const {
    // IMPLEMENT ME
    // below are just stub code
    bool removeMe = false;
    return removeMe;
}

bool BiArray::set(int i, int v) {
    // IMPLEMENT ME
    // below are just stub code
    bool removeMe = false;
    return removeMe;
}

int BiArray::operator[](int i) const {
    // IMPLEMENT ME
    // below are just stub code

    return data[i];
}

int &BiArray::operator[](int i) {
    // IMPLEMENT ME
    // below are just stub code

    return data[i];
}

void BiArray::push_back(int v) {
    // IMPLEMENT ME
}

bool BiArray::pop_back() {
    // IMPLEMENT ME
    // below are just stub code
    bool removeMe = false;
    return removeMe;
}

void BiArray::push_front(int v) {
    // IMPLEMENT ME
}

bool BiArray::pop_front() {
    // IMPLEMENT ME
    // below are just stub code
    bool removeMe = false;
    return removeMe;
}

int BiArray::getSize() const {
    return size;
}

int BiArray::getCapacity() const {

   return currentCapacity;
}

int BiArray::getHeadEmptyCount() const {
    return emptyHead;
}

string BiArray::print() const {
    // IMPLEMENT ME
    // below are just stub code
    string toReturn = "[";
    for(int i = 0; i < getSize(); i++){
        toReturn +=  to_string(*(data+i));
        if(i != getSize()-1){
            toReturn += " ";
        }
    }
    toReturn += "]";
    return toReturn;
}

string BiArray::printAll() const {
    string toReturn = "[";
    for(int i = 0; i< getCapacity(); i++){
        if(i < emptyHead || i >= emptyHead + size){
            toReturn += "X";
        }else {
            toReturn += to_string(*(data - emptyHead + i));
        }
        if(i != getCapacity()-1){
            toReturn += " ";
        }
    }
    toReturn += "]";
    return toReturn;
}

bool operator==(const BiArray &lhs, const BiArray &rhs) {
    // IMPLEMENT ME
    // below are just stub code
    bool removeMe = false;
    return removeMe;
}

bool operator!=(const BiArray &lhs, const BiArray &rhs) {
    // IMPLEMENT ME
    // below are just stub code
    bool removeMe = false;
    return removeMe;
}

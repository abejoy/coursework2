#include <iostream>
#include "BiArray.h"

// default constructor
BiArray::BiArray(): size(0), start(INITIALCAP/2){
    data = new int[getCapacity()];
}

// value constructor
BiArray::BiArray(int arr[], int size) : size(size){
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
    delete data;
}

// copy constructor
BiArray::BiArray(const BiArray &other) {
    // IMPLEMENT ME
}

// move constructor
BiArray::BiArray(BiArray &&other) {
    // IMPLEMENT ME
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
    // IMPLEMENT ME
    // below are just stub code
    return size;
}

int BiArray::getCapacity() const {
    // IMPLEMENT ME
    // below are just stub code
   return (LO_THRESHOLD*size > INITIALCAP) ? LO_THRESHOLD*size : INITIALCAP;
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
    // IMPLEMENT ME
    // below are just stub code
    string removeMe = "";
    return removeMe;
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

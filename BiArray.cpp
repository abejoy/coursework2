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
BiArray::BiArray(int arr[], int size) : size(size), currentCapacity(calculateCapacity()){
    // IMPLEMENT ME
    data = new int[getCapacity()];
    if(getSize() == 1){
        data += getCapacity()/2;
        emptyHead = getCapacity()/2;
        emptyTail = getCapacity()/2;
    }
    else{
        data += getSize();
        emptyHead = getSize();
        emptyTail = getSize();
    }

    for(int i = 0; i < size; i++){
        *(data+i) =  arr[i];
    }
}

// destructor
BiArray::~BiArray() {
}

// copy constructor
BiArray::BiArray(const BiArray &other): size(other.getSize()), currentCapacity(other.getCapacity()), emptyHead(other.getHeadEmptyCount()), emptyTail(other.emptyTail){

    size = other.size;
    currentCapacity = other.currentCapacity;

    //Create new array
    data = new int[currentCapacity];

    //copy values of other array into new arr_
    for(int i = 0; i < size; i++){
        data[i] = other.data[i];
    }

}

// move constructor
BiArray::BiArray(BiArray &&other) {
    copyOther(other);

    other.~BiArray();
}

// copy assignment
BiArray &BiArray::operator=(const BiArray &other) {
    copyOther(other);

    return *this;
}

// move assignment
BiArray &BiArray::operator=(BiArray &&other) {
    copyOther(other);

    other.~BiArray();

    return *this;
}

bool BiArray::get(int i, int &v) const {
    if(i > getSize() - 1 || i < 0){
        return false;
    }else{
        v = data[i];
        return true;
    }
}

bool BiArray::set(int i, int v) {
    if(i > getSize() - 1 || i < 0){
        return false;
    }else{
        data[i] = v;
        return true;
    }
}

int BiArray::operator[](int i) const {
    return data[i];
}

int &BiArray::operator[](int i) {
    return data[i];
}

void BiArray::push_back(int v) {
    //check if can push back
    if(getHeadEmptyCount() + getSize() < getCapacity()){
        //can push
        *(data+getSize()) = v;
        size++;
    }else{
        //cannot push without making aray bigger
        const int newCapacity = calculateCapacity();
        int temparr[getSize()];
        for(int i = 0; i < getSize(); i++){
            temparr[i] = data[i];
        }
        data = new int[newCapacity];
        data += getSize();
        for(int i = 0; i < getSize(); i++){
            data[i] = temparr[i];
        }
        currentCapacity  = newCapacity;
        emptyHead = getSize();
        push_back(v);
    }
}

bool BiArray::pop_back() {
    //bi array is empty
    if(getSize() == 0){
        return false;
    }

    //the popping from back
    size = getSize() - 1;

    //check if needing resize
    if(getCapacity() > HI_THRESHOLD * getSize()){
        int newCapacity = calculateCapacity();
        int tempArr[getSize()];
        for(int i = 0; i < getSize(); i++){
            tempArr[i] = data[i];
        }

        data = new int[newCapacity];
        currentCapacity = newCapacity;
        if(getSize() == 1){
            data += getCapacity()/2;
            emptyHead = getCapacity()/2;
        }else{
            data += getSize();
            emptyHead = getSize();
        }

        for(int i = 0; i < getSize(); i++){
            data[i] = tempArr[i];
        }

    }

    return true;
}

void BiArray::push_front(int v) {
    if(getHeadEmptyCount() != 0){
        //can push
        if(size > 0) {
            data--;
            emptyHead--;
        }
        *(data) = v;
        size++;

    }else{
        //cannot push without making aray bigger
        const int newCapacity = calculateCapacity();
        int temparr[getSize()];
        for(int i = 0; i < getSize(); i++){
            temparr[i] = data[i];
        }
        data = new int[newCapacity];
        data += getSize();
        for(int i = 0; i < getSize(); i++){
            data[i] = temparr[i];
        }
        currentCapacity  = newCapacity;
        emptyHead = getSize();
        push_front(v);

    }
}

bool BiArray::pop_front() {
    //bi array is empty
    if(getSize() == 0){
        return false;
    }

    //the popping from front
    data++;
    size--;
    emptyHead++;

    //check if needing resize
    if(getCapacity() > HI_THRESHOLD * getSize()){
        int newCapacity = calculateCapacity();
        int tempArr[getSize()];
        for(int i = 0; i < getSize(); i++){
            tempArr[i] = data[i];
        }

        data = new int[newCapacity];
        currentCapacity = newCapacity;
        if(getSize() == 1){
            data += getCapacity()/2;
            emptyHead = getCapacity()/2;
        }else{
            data += getSize();
            emptyHead = getSize();
        }

        for(int i = 0; i < getSize(); i++){
            data[i] = tempArr[i];
        }

    }

    return true;
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
    if(lhs.getSize() != rhs.getSize()){
        return false;
    }
    for(int i=0; i < lhs.getSize(); i++){
        if(lhs[i] != rhs[i]){
            return false;
        }
    }

    return true;
}

bool operator!=(const BiArray &lhs, const BiArray &rhs) {
    return !operator==(lhs, rhs);
}

int BiArray::calculateCapacity() {
    return (LO_THRESHOLD*size > INITIALCAP) ? LO_THRESHOLD*size : INITIALCAP;
}

void BiArray::copyOther(BiArray other) {
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
}

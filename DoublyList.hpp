#ifndef DOUBLY_LIST_HPP
#define DOUBLY_LIST_HPP

#include "List.hpp"
#include <iostream>
using namespace std;

template <typename T>
class DoublyList : public List<T> {
    protected:
        // represents an element in the doubly linked list
        struct Node {
            T value;
            Node* next;
            Node* prev;

            Node(T v = T(), Node* n = nullptr, Node* p = nullptr)
            : value(v), next(n), prev(p) { }
        };

        // sentinel pointers
        Node *header, *trailer;

    private:
        // copy the state of the argument list to `this`
        void copy(const DoublyList<T>&);

    public:
        // default constructor
        DoublyList();

        // copy constructor
        DoublyList(const DoublyList<T>&);

        // overloaded assignment operator
        DoublyList<T>& operator=(const DoublyList<T>&);

        // destructor
        virtual ~DoublyList();

        // add the argument to the end of the list
        virtual void append(const T&) override;

        // remove all elements in the list, resetting to the initial state
        virtual void clear() override;

        // return the element at the given position (argument)
        virtual T getElement(int) const override;

        // return the current length of the list
        virtual int getLength() const override;

        // insert the given element (argument 2) at
        // the given position (argument 1)
        virtual void insert(int, const T&) override;

        // determine if the list currently empty
        virtual bool isEmpty() const override;

        // remove the element at the given position (argument)
        virtual void remove(int) override;

        // replace the element at the given position (argument 1) with
        // the value given (argument 2)
        virtual void replace(int, const T&) override;

        // check if an element exists that contains the given value (argument)
        virtual bool search(const T&) const;

        // overloaded stream insertion operator to make printing easier
        template <typename U>
        friend ostream& operator<<(ostream&, const DoublyList<U>&);
};

template <typename T>
DoublyList<T>::DoublyList()
    : header(new Node), trailer(new Node) {
    header->next = trailer;
    trailer->prev = header;
}

template <typename T>
DoublyList<T>::DoublyList(const DoublyList<T>& copyObj)
    : header(new Node), trailer(new Node) {
    copy(copyObj);
}

template <typename T>
DoublyList<T>& DoublyList<T>::operator=(const DoublyList<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
DoublyList<T>::~DoublyList() {
    clear();
    delete header;
    delete trailer;
    header = trailer = nullptr;
}

template <typename T>
void DoublyList<T>::append(const T& elem) {

    Node* newNode = new Node(elem, trailer, trailer->prev);

    trailer->prev->next = newNode;
    trailer->prev = newNode;

    this->length++;
}

template <typename T>
void DoublyList<T>::clear() {
    for (Node* curr = nullptr; header->next != trailer; ) {
        curr = header->next->next;
        delete header->next;
        header->next = curr;
    }

    trailer->prev = header;
    this->length = 0;
}

template <typename T>
void DoublyList<T>::copy(const DoublyList<T>& copyObj) {
    this->length = copyObj.length;
    Node* myCurr = header;
    Node* copyCurr = copyObj.header->next;

    while (copyCurr != copyObj.trailer) {
        Node* n = new Node(copyCurr->value);
        myCurr->next = n;
        n->prev = myCurr;
        myCurr = n;
        copyCurr = copyCurr->next;
    }

    myCurr->next = trailer;
    trailer->prev = myCurr;
}

template <typename T>
T DoublyList<T>::getElement(int position) const {
    if (position < 0 || position >= this->length) {
        throw string("getElement: position out of bounds");
    }

    Node* curr = header->next;

    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }

    return curr->value;
}


template <typename T>
void DoublyList<T>::insert(int position, const T& elem) {

    if (position < 0 || position > this->length) {
        throw string("insert: position out of bounds");
    }

    Node* curr = header->next;

    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }

    Node* newNode = new Node(elem, curr, curr->prev);

    curr->prev->next = newNode;
    curr->prev = newNode;

    this->length++;
}


template <typename T>
bool DoublyList<T>::isEmpty() const {
    return this->length == 0
        && header->next == trailer
        && trailer->prev == header;
}

template <typename T>
void DoublyList<T>::remove(int position) {

    if (position < 0 || position >= this->length) {
        throw string("remove: position out of bounds");
    }

    Node* curr = header->next;

    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;

    delete curr;
    this->length--;
}

template <typename T>
bool DoublyList<T>::search(const T& elem) const {

    Node* curr = header->next;

    while (curr != trailer) {
        if (curr->value == elem) {
            return true;
        }
        curr = curr->next;
    }

    return false;
}

template <typename T>
void DoublyList<T>::replace(int position, const T& elem) {

    if (position < 0 || position >= this->length) {
        throw string("replace: position out of bounds");
    }

    Node* curr = header->next;

    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }

    curr->value = elem;
}

template <typename T>
ostream& operator<<(ostream& outStream, const DoublyList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        typename DoublyList<T>::Node* curr = myObj.header->next;
        while (curr != myObj.trailer) {
            outStream << curr->value;
            if (curr->next != myObj.trailer) {
                outStream << " <--> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }

    return outStream;
}

#include "DoublyList.tpp"
#endif

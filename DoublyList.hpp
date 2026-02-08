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

#include "DoublyList.tpp"
#endif

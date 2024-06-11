#ifndef LIST_H
#define LIST_H


using namespace std;

template <typename T>
class List
    : public error_code {

public:
    List();
    void pop_front();
    void pop_back();
    void clear();
    void push_back(T data);
    void push_front(T data);
    void insert(T data, int index);
    void remove(int index);
    int getSIZE() { return SIZE; }
    T& operator[](const int index);

private:

    template <typename t>
    struct Node {
    public:
        T data;
        Node* next;
        Node(T data = T(), Node* next = nullptr) {
            this->data = data;
            this->next = next;
        }
    };
    int SIZE;
    Node<T>* head;
};

template<typename T>
List<T>::List()
{
    cout << "Constructor" << this << endl;
    SIZE = 0;
    head = nullptr;
}


template<typename T>
void List<T>::push_back(T data) {
    if (head == nullptr) {
        head = new Node<T>(data);
    }
    else {
        Node<T>* current = this->head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node<T>(data);
    }
    SIZE++;
}

template<typename T>
T& List<T>::operator[](const int index) {
    int counter = 0;
    Node<T>* current = this->head;
    while (current != nullptr) {
        if (counter == index) {
            return current->data;
        }
        current = current->next;
        counter++;
    }
}

template<typename T>
void List<T>::pop_front() {
    Node<T>* temp = head;
    head = head->next;
    delete temp;
    SIZE--;
}

template<typename T>
void List<T>::clear() {
    while (SIZE) {
        pop_front();
    }
}

template<typename T>
void List<T>::push_front(T data) {
    head = new Node<T>(data, head);
    SIZE++;
}

template<typename T>
void List<T>::insert(T data, int index) {

    if (index == 0) {
        push_front(data);
    }
    else {
        Node<T>* prev = this->head;

        for (int i = 0; i < (index - 1); i++) {
            prev = prev->next;
        }
        Node<T>* newNode = new Node<T>(data, prev->next);
        prev->next = newNode;
        SIZE++;
    }
}

template<typename T>
void List<T>::remove(int index) {
    if (index == 0) {
        pop_front();
    }
    else {
        Node<T>* prev = this->head;

        for (int i = 0; i < (index - 1); i++) {
            prev = prev->next;
        }
        Node<T>* delNode = prev->next;
        prev->next = delNode->next;
        delete delNode;
        SIZE--;
    }
}

template<typename T>
void List<T>::pop_back() {
    remove((SIZE - 1));
}

#endif //LIST_H
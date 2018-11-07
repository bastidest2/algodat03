#include <iostream>
#include <exception>

template <class T>
class Queue {
private:
    const size_t m_sMaxSize;
    size_t m_sFront;
    size_t m_sBack;
    size_t m_sCurrentSize;
    T* m_pArr;

public:
    Queue(size_t size)
    : m_sMaxSize(size)
    , m_sFront(0)
    , m_sBack(-1)
    , m_pArr(new T[size]) {

    }

    ~Queue() {
        delete[] m_pArr;
    }

    size_t size() const {
        return m_sCurrentSize;
    }

    void enqueue(T element) {
        if(size() >= m_sMaxSize) {
            throw std::runtime_error("maximum queue size reached");
        }
        m_sBack = (m_sBack + 1) % m_sMaxSize;
        m_pArr[m_sBack] = element;
        m_sCurrentSize++;
    }

    T dequeue() {
        if(size() <= 0) {
            throw std::runtime_error("queue is empty");
        }
        T ret = m_pArr[m_sFront];
        m_sFront = (m_sFront + 1) % m_sMaxSize;
        m_sCurrentSize--;
        return ret;
    }

    T peek() const {
        return m_pArr[m_sFront];
    }
};

int main() {
    Queue<int> q(3);
    q.enqueue(1);
    std::cout << q.size() << std::endl;
    q.enqueue(2);
    std::cout << q.size() << std::endl;
    q.enqueue(3);
    std::cout << q.dequeue() << std::endl;
    q.enqueue(4);
    std::cout << q.size() << std::endl;
    std::cout << q.dequeue() << std::endl;
    std::cout << q.dequeue() << std::endl;
    std::cout << q.dequeue() << std::endl;
    return 0;
}

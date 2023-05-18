#include <iostream>

// Определение структуры узла списка
struct Node {
    int data;
    Node* next;
};

// Класс стека
class Stack {
private:
    Node* top; // Указатель на вершину стека

public:
    // Конструктор
    Stack() {
        top = nullptr; // Инициализация вершины как пустого списка
    }

    // Добавление элемента в стек
    void push(int value) {
        // Создание нового узла
        Node* newNode = new Node;
        newNode->data = value;

        // Присоединение нового узла к вершине стека
        newNode->next = top;
        top = newNode;
    }

    // Удаление элемента из стека
    void pop() {
        if (top == nullptr) {
            std::cout << "Стек пуст!" << std::endl;
            return;
        }

        // Сохранение указателя на вершину для удаления
        Node* temp = top;

        // Перемещение указателя вершины на следующий элемент
        top = top->next;

        // Освобождение памяти удаленного узла
        delete temp;
    }

    // Вывод содержимого стека
    void printStack() {
        if (top == nullptr) {
            std::cout << "Стек пуст!" << std::endl;
            return;
        }

        std::cout << "Содержимое стека: ";
        Node* current = top;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Поиск минимального элемента в стеке
    int findMin() {
        if (top == nullptr) {
            std::cout << "Стек пуст!" << std::endl;
            return -1;
        }

        int minElement = top->data;
        Node* current = top->next;
        while (current != nullptr) {
            if (current->data < minElement) {
                minElement = current->data;
            }
            current = current->next;
        }
        return minElement;
    }
};

int main() {
    Stack stack;

    // Добавление элементов в стек
    stack.push(4);
    stack.push(3);
    stack.push(1);
    stack.push(2);
    stack.push(4);

    // Вывод содержимого стека
    stack.printStack();

    // Удаление элемента из стека
    stack.pop();

    // Вывод содержимого стека после удаления
    stack.printStack();

    // Поиск минимального элемента
    int minElement = stack.findMin();
    if (minElement != -1) {
        std::cout << "Минимальный элемент в стеке: " << minElement << std::endl;
    }

    return 0;
}

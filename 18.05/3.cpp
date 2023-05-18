#include <iostream>

/*
1. В коде стек реализован с помощью односвязного списка. Структура `Node` представляет узел списка, содержащий значение элемента и указатель на следующий узел. Класс `Stack` содержит указатель на вершину стека, который инициализируется как `nullptr` в конструкторе.
2. Операция `push` добавляет новый элемент в стек. Создается новый узел, его значение устанавливается на добавляемое значение, а указатель `next` устанавливается на текущую вершину стека. Затем указатель вершины обновляется, указывая на новый узел, чтобы он стал новой вершиной стека.
3. Операция `pop` удаляет элемент из стека. Если стек пустой, выводится сообщение об ошибке. В противном случае, указатель вершины обновляется, чтобы указывать на следующий элемент стека, а удаленный узел освобождается из памяти.
4. Операция `printStack` выводит содержимое стека, начиная с вершины. Если стек пустой, выводится сообщение об ошибке.
5. Операция `findMin` находит минимальный элемент в стеке. Если стек пустой, выводится сообщение об ошибке. Алгоритм просто проходит по всем элементам стека, сравнивая значения и обновляя минимальное значение при необходимости.
КОД
1. Первый код реализует стек с помощью односвязного списка
2. Первый код имеет явное управление памятью для создания и удаления узлов списка
4. Первый код имеет более подробные сообщения об ошибках, включая вывод сообщений, если стек пустой при выполнении операций `pop`, `printStack` и `findMin`. 
5. Код выполняет заданные операции: добавление элементов, удаление элементов, вывод содержимого стека и поиск минимального элемента, но используют разные подходы для достижения того же результата.

*/

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
    
    void push(int value);
    void pop();
    void printStack();
    int findMin();
    
};

void Stack::push(int value) {
        // Создание нового узла
        Node* newNode = new Node;
        newNode->data = value;

        // Присоединение нового узла к вершине стека
        newNode->next = top;
        top = newNode;
    }

// Удаление элемента из стека
void Stack::pop() {
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
void Stack::printStack() {
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
int Stack::findMin() {
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

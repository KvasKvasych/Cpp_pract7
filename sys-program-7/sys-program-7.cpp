#include <iostream>
#include "Matrix.h"
#include "Stack.h"
#include "Complex.h"
#include "Book.h"
#include "Point3D.h"
#include "LinkedList.h"
#include "QuadraticEquation.h"
#include "Graph.h"
#include "DynamicArray.h"
#include "Triangle.h"


using namespace std;

int main() {
    setlocale(LC_ALL, "Ru");
    
    Matrix m1(2, 3, 1.5);
    Matrix m2(2, 3, 2.5);

    cout << "Матрица 1:" << endl;
    m1.print();

    cout << "\nМатрица 2:" << endl;
    m2.print();

    cout << "\nСумма матриц:" << endl;
    (m1 + m2).print();

  
    
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    s.print();

    cout << "\nВерхний элемент: " << s.peek() << endl;
    cout << "Извлеченный элемент: " << s.pop() << endl;
    s.print();

 
  
    Complex c1(3, 4);
    Complex c2(1, -2);

    cout << "Число 1: ";
    c1.print();
    cout << "\nЧисло 2: ";
    c2.print();

    cout << "\nСумма: ";
    (c1 + c2).print();
    cout << "\nПроизведение: ";
    (c1 * c2).print();
   
    LinkedList list;
    list.append("Первый");
    list.append("Второй");
    list.append("Третий");

    list.print();
    cout << "Содержит 'Второй': " << boolalpha << list.contains("Второй") << endl;

    list.remove("Второй");
    list.print();
    cout << "Содержит 'Второй': " << boolalpha << list.contains("Второй") << endl;

  
    Point3D p1(1, 2, 3);
    Point3D p2(4, 5, 6);

    p1.print();
    p2.print();
    cout << "Расстояние между точками: " << p1.distanceTo(p2) << endl;
    cout << "p1 ближе к началу координат чем p2: " << boolalpha << (p1 < p2) << endl;

    p1.move(1, 1, 1);
    cout << "После перемещения: ";
    p1.print();

    
    Book book1("Война и мир", "Лев Толстой", 1869);
    Book book2("Преступление и наказание", "Федор Достоевский", 1866);

    book1.print();
    book2.print();
    cout << "book1 издана позже book2: " << boolalpha << (book2 < book1) << endl;

    book1.saveToFile("book1.txt");
    Book book3;
    book3.loadFromFile("book1.txt");
    cout << "Загруженная книга: ";
    book3.print();
    
    Triangle t1(3, 4, 5);
    Triangle t2(5, 5, 5);

    t1.print();
    t2.print();
    cout << "t1 < t2: " << (t1 < t2 ? "да" : "нет") << endl;

    
    DynamicArray arr;
    arr.push_back(5);
    arr.push_back(2);
    arr.push_back(8);
    arr.push_back(1);

    arr.print();
    arr.bubbleSort();
    cout << "После сортировки: ";
    arr.print();
    cout << "Индекс элемента 8: " << arr.find(8) << endl;

    
    QuadraticEquation eq1(1, -3, 2);
    QuadraticEquation eq2(1, 2, 5);

    eq1.print();
    eq2.print();

    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    g.print();
    g.BFS(0);
    g.DFS(0);
    cout << "Граф связный: " << (g.isConnected() ? "да" : "нет") << endl;
    return 0;
}
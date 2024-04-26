#include <iostream>

#include <function.h>
#include <function_static.h>
#include <test_lib1.h>

#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    std::cout << "hello, vscode" << std::endl;
    int a = 3;
    int b = 8;
    std::cout << a << " + " << b << " = " << add(a, b) << std::endl;

    a = 20;
    b = 33;
    std::cout << a << " - " << b << " = " << sub(a, b) << std::endl;

    a = 100;
    b = 404;
    std::cout << a << " * " << b << " = " << mul(a, b) << std::endl;

    QApplication app(argc, argv);

    QLabel label("hello, qt");
    label.setFixedWidth(400);
    label.setFixedHeight(300);

    

    label.show();


    return app.exec();
}
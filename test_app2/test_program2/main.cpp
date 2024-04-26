#include <iostream>

#include <function.h>
#include <function_static.h>
#include <test_lib2.h>

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

    a = 1000;
    b = 404;
    std::cout << a << " * " << b << " = " << div_int(a, b) << std::endl;

    QApplication app(argc, argv);

    QLabel label("hello, 2nd app");
    label.setFixedWidth(200);
    label.setFixedHeight(100);

    

    label.show();


    return app.exec();
}
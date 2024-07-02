#include "mainwindow.h" // Corrected the include directive
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv); // Initializes the QApplication object with command-line arguments
    MainWindow<int> w;               // Creates an instance of BaseMainWindow
    w.setWindowTitle("App");    // Sets the window title to "App"
    w.resize(800, 600);         // Resizes the window to 800x600 pixels
    w.show();                   // Makes the window visible

    return a.exec(); // Enters the main event loop and waits until exit() is called
}

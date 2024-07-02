// BaseMainWindow.h
#ifndef BASEMAINWINDOW_H
#define BASEMAINWINDOW_H

#include <QMainWindow>

class BaseMainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit BaseMainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {}
    virtual ~BaseMainWindow() {}
};

#endif // BASEMAINWINDOW_H

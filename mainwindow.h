// MainWindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "BaseMainWindow.h" // Include the base class header
#include "Tree.hpp" // Assuming Tree.hpp is your custom Tree class implementation
#include <QTreeWidget>

template <typename T>
class MainWindow : public BaseMainWindow {
public:
    explicit MainWindow(QWidget *parent = nullptr) : BaseMainWindow(parent) {
        QTreeWidget *treeWidget = new QTreeWidget(this);
        setCentralWidget(treeWidget);
        treeWidget->setHeaderLabel("Tree View");

        // Create your tree and add some nodes
        Tree<int> myTree;
        myTree.add_root(1);
        myTree.add_sub_node(1, 2);
        myTree.add_sub_node(1, 3);
        myTree.add_sub_node(2, 4);
        myTree.add_sub_node(2, 5);
        myTree.add_sub_node(3, 6);
        myTree.add_sub_node(3, 7);

        // Convert your tree to QTreeWidgetItems
        addNodesToTreeWidget(treeWidget, nullptr, myTree.getRoot());
    }
    virtual ~MainWindow() {}

private:
    void addNodesToTreeWidget(QTreeWidget *treeWidget, QTreeWidgetItem *parentItem, typename Tree<T>::Node *node){
        if (!node)
            return;

        QTreeWidgetItem *treeItem;
        if (parentItem) {
            treeItem = new QTreeWidgetItem(parentItem);
        } else {
            treeItem = new QTreeWidgetItem(treeWidget);
        }
        treeItem->setText(0, QString::number(node->key));

        for (auto *child : node->children) {
            if (child) {
                addNodesToTreeWidget(treeWidget, treeItem, child);
            }
        }
    };
};

#endif // MAINWINDOW_H

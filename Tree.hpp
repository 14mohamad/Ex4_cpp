#ifndef TREE_H
#define TREE_H

#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <stdexcept>
#include <vector>

template <typename T, int K = 2>
class Tree
{
public:
    class Node
    {
    public:
        T key;
        std::vector<Node *> children;

        Node(T val) : key(val), children(K, nullptr) {}
    };

    class IteratorBase
    {
    public:
        virtual ~IteratorBase() {}
        virtual bool hasNext() = 0;
        virtual T next() = 0;
    };

    class PreOrderIterator : public IteratorBase
    {
    private:
        std::stack<Node *> stack;

    public:
        PreOrderIterator(Node *root)
        {
            if (root)
                stack.push(root);
        }

        bool hasNext() override
        {
            return !stack.empty();
        }

        T next() override
        {
            Node *node = stack.top();
            stack.pop();
            for (int i = K - 1; i >= 0; --i)
            {
                if (node->children[i])
                {
                    stack.push(node->children[i]);
                }
            }
            return node->key;
        }
    };

    class PostOrderIterator : public IteratorBase
    {
    private:
        std::stack<Node *> stack;
        std::stack<Node *> output;

    public:
        PostOrderIterator(Node *root)
        {
            if (root)
                stack.push(root);
            while (!stack.empty())
            {
                Node *node = stack.top();
                stack.pop();
                output.push(node);
                for (Node *child : node->children)
                {
                    if (child)
                    {
                        stack.push(child);
                    }
                }
            }
        }

        bool hasNext() override
        {
            return !output.empty();
        }

        T next() override
        {
            Node *node = output.top();
            output.pop();
            return node->key;
        }
    };

    class InOrderIterator : public IteratorBase
    {
    private:
        std::stack<Node *> stack;
        Node *current;

    public:
        InOrderIterator(Node *root) : current(root) {}

        bool hasNext() override
        {
            return current || !stack.empty();
        }

        T next() override
        {
            while (current)
            {
                stack.push(current);
                current = current->children[0];
            }
            current = stack.top();
            stack.pop();
            Node *node = current;
            current = (current->children.size() > 1) ? current->children[1] : nullptr;
            return node->key;
        }
    };

    class BFSIterator : public IteratorBase
    {
    private:
        std::queue<Node *> queue;

    public:
        BFSIterator(Node *root)
        {
            if (root)
                queue.push(root);
        }

        bool hasNext() override
        {
            return !queue.empty();
        }

        T next() override
        {
            Node *node = queue.front();
            queue.pop();
            for (Node *child : node->children)
            {
                if (child)
                {
                    queue.push(child);
                }
            }
            return node->key;
        }
    };

    class DFSIterator : public IteratorBase
    {
    private:
        std::stack<Node *> stack;

    public:
        DFSIterator(Node *root)
        {
            if (root)
                stack.push(root);
        }

        bool hasNext() override
        {
            return !stack.empty();
        }

        T next() override
        {
            Node *node = stack.top();
            stack.pop();
            for (int i = K - 1; i >= 0; --i)
            {
                if (node->children[i])
                {
                    stack.push(node->children[i]);
                }
            }
            return node->key;
        }
    };

    Tree() : root(nullptr) {}
    ~Tree()
    {
        deleteSubTree(root);
    }

    void add_root(T key)
    {
        if (!root)
        {
            root = new Node(key);
        }
        else
        {
            root->key = key;
        }
    }

    void add_sub_node(T parent_key, T child_key)
    {
        Node *parent_node = findNode(root, parent_key);
        if (parent_node)
        {
            for (Node *&child : parent_node->children)
            {
                if (!child)
                {
                    child = new Node(child_key);
                    return;
                }
            }
            throw std::runtime_error("Maximum children reached");
        }
        else
        {
            throw std::runtime_error("Parent not found");
        }
    }

    IteratorBase *begin_pre_order()
    {
        return new PreOrderIterator(root);
    }

    IteratorBase *end_pre_order()
    {
        return nullptr;
    }

    IteratorBase *begin_post_order()
    {
        return new PostOrderIterator(root);
    }

    IteratorBase *end_post_order()
    {
        return nullptr;
    }

    IteratorBase *begin_in_order()
    {
        return new InOrderIterator(root);
    }

    IteratorBase *end_in_order()
    {
        return nullptr;
    }

    IteratorBase *begin_bfs_scan()
    {
        return new BFSIterator(root);
    }

    IteratorBase *end_bfs_scan()
    {
        return nullptr;
    }

    IteratorBase *begin_dfs_scan()
    {
        return new DFSIterator(root);
    }

    IteratorBase *end_dfs_scan()
    {
        return nullptr;
    }

    void print(Node *node, int depth = 0, bool isLeft = true) const
    {
        if (node == nullptr)
        {
            return;
        }
        
        // Print the right subtree first
        if (node->children.size() > 1 && node->children[1] != nullptr)
        {
            print(node->children[1], depth + 1, false);
        }

        // Print the current node
        for (int i = 0; i < depth; ++i)
        {
            std::cout << "    ";
        }
        if (depth > 0)
        {
            std::cout << (isLeft ? "└── " : "┌── ");
        }
        std::cout << node->key << std::endl;

        // Print the left subtree
        if (node->children.size() > 0 && node->children[0] != nullptr)
        {
            print(node->children[0], depth + 1, true);
        }
    }

    void print() const
    {
        print(root);
    }

private:
    Node *root;

    Node *findNode(Node *node, T key)
    {
        if (!node)
            return nullptr;
        if (node->key == key)
            return node;
        for (Node *child : node->children)
        {
            Node *found = findNode(child, key);
            if (found)
                return found;
        }
        return nullptr;
    }

    void deleteSubTree(Node *node)
    {
        if (!node)
            return;
        for (Node *child : node->children)
        {
            deleteSubTree(child);
        }
        delete node;
    }
};

#endif // TREE_H

#include <iostream>
#include <list>
#include <string>
#include <algorithm>

class Tree {
public:
    explicit Tree(std::string name) : name(std::move(name)), parent(nullptr) {}

    Tree* addSubdirectory(const std::string& name) {
        Tree* newDir = new Tree(name);
        newDir->parent = this;
        subdirectories.push_back(newDir);
        return subdirectories.back();
    }

    void listSubdirectories() const {
        for(const auto& t : subdirectories) {
            std::cout << t->name << '\n';
        }
    }

    Tree* cd(const std::string& name) {
        auto it = std::find_if(subdirectories.begin(), subdirectories.end(),
                               [&name](const Tree* dir) {
                                   return dir->name == name;
                               });

        return it != subdirectories.end() ? *it : nullptr;
    }

    void pwd() const {
        if(!parent) {
            std::cout << '/';
        } else {
            parent->pwd();
            std::cout << name << '/';
        }
    }

    std::string name;

private:
    std::list<Tree*> subdirectories;
    Tree* parent;
};

// This program provides a simple file management system that allows users to:
// 1. List the contents of a directory
// 2. Create a new file
// 3. Delete an existing file
// 4. Open and read the contents of a file
// The user can interact with the program through a menu-driven interface.

#include <iostream>
#include <dirent.h>
#include <string>

void listDirectoryContents(const std::string& path) {
    DIR* dir = opendir(path.c_str());
    if (dir == nullptr) {
        std::cerr << "Error opening directory: " << path << std::endl;
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        std::cout << entry->d_name << std::endl;
    }

    closedir(dir);
}

int main() {
    std::string path;
    std::cout << "Enter directory path: ";
    std::cin >> path;

    listDirectoryContents(path);

    return 0;
}
void createFile(const std::string& path) {
    std::ofstream file(path);
    if (!file) {
        std::cerr << "Error creating file: " << path << std::endl;
    } else {
        std::cout << "File created: " << path << std::endl;
    }
}

void deleteFile(const std::string& path) {
    if (remove(path.c_str()) != 0) {
        std::cerr << "Error deleting file: " << path << std::endl;
    } else {
        std::cout << "File deleted: " << path << std::endl;
    }
}

void openFile(const std::string& path) {
    std::ifstream file(path);
    if (!file) {
        std::cerr << "Error opening file: " << path << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
}

int main() {
    std::string path;
    int choice;

    while (true) {
        std::cout << "1. List directory contents\n";
        std::cout << "2. Create a file\n";
        std::cout << "3. Delete a file\n";
        std::cout << "4. Open a file\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter directory path: ";
                std::cin >> path;
                listDirectoryContents(path);
                break;
            case 2:
                std::cout << "Enter file path to create: ";
                std::cin >> path;
                createFile(path);
                break;
            case 3:
                std::cout << "Enter file path to delete: ";
                std::cin >> path;
                deleteFile(path);
                break;
            case 4:
                std::cout << "Enter file path to open: ";
                std::cin >> path;
                openFile(path);
                break;
            case 5:
                return 0;
            default:
                std::cerr << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
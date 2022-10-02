#include <iostream>
#include <vector>
#include <fstream>

bool lines = false;
bool bytes = false;
bool words = false;
bool chars = false;

int count_lines(std::string& l){
    int counter = 0;
    std::ifstream file(l);
    std::string a;

    while (std::getline(file, a)) {
        counter++;
    }
    file.close();
    return counter;
}
int count_bytes(std::string& b){
    int counter = 0;
    std::ifstream file;
    file.open(b);
    char a;
    while(file.get(a)) {
        if (a != '\r\n'){
            counter++;
        }
        else {
            counter += 2;
        }
    }
    file.close();
    return counter;

}
int count_words(std::string& w){
    int counter = 0;
    std::ifstream file;
    file.open(w);
    int ind = 0;
    char a;
    while(file.get(a)) {
        if ((a != ' ') && (a != '\n') && (a != '\r') && (a != '\r\n')) {
            ind = 1;
        }
        else if (ind == 1) {
            counter++;
            ind = 0;
        }
    }
    if ((counter != 0) && (ind == 1)) {
        counter ++;
    }
    file.close();
    return counter;
}
int count_chars(std::string& c){
    int counter = 0;
    std::ifstream file(c);
    char a;
    while(file.get(a)) {
        if((a != ' ') && (a != '\n') && (a != '\r') && (a != '\r\n')) {
            counter++;
        }
    }
    file.close();
    return counter;
}

void needs(std::string arg) {
    for (int k = 1; k < arg.size(); k++)
    {
        if (arg[k] == 'l')
        {
            lines = true;
        }
        if (arg[k] == 'c')
        {
            bytes = true;
        }
        if (arg[k] == 'w')
        {
            words = true;
        }
        if (arg[k] == 'm')
        {
            chars = true;
        }
    }
}

int main(int argc, char* argv[])
{
    std::vector<std::string> files;
    for (int i = 1; i < argc; i++)
    {
        std::string new_line = argv[i];
        if (new_line == "--lines")
        {
            lines = true;
        }
        else if (new_line == "--bytes")
        {
            bytes = true;
        }
        else if (new_line == "--words")
        {
            words = true;
        }
        else if (new_line == "--chars")
        {
            chars = true;
        }
        else if (new_line[0] == '-')
        {

            needs(new_line);
        }
        else
        {
            files.push_back(new_line);
        }
    }
    for (int i = 0; i < files.size(); i++)
    {
        if (lines == true)
        {
            std:: cout << count_lines(files[i]) << ' ';
        }
        if (bytes == true)
        {
            std:: cout << count_bytes(files[i]) << ' ';
        }
        if (words == true)
        {
            std:: cout << count_words(files[i]) << ' ';
        }
        if (chars == true)
        {
            std:: cout << count_chars(files[i]) << ' ';
        }
        std:: cout << files[i] << '\n';
    }
    return 0;
}


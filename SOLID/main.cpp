#include <iostream>
#include "Printable.h"

int main()
{
    HTMLData html("Hello World");
    JSONData json("Test Data");
    TextData text("Simple text");

    std::ofstream file1("output.html");
    std::ofstream file2("output.json");
    std::ofstream file3("output.txt");

    saveToAsHTML(file1, html);
    saveToAsJSON(file2, json);
    saveToAsText(file3, text); 
}
#include <iostream>
#include <string>
#include "html.h"

int main()
{
    auto text_block = new ItalicText(new Paragraph(new Text()));
    text_block->render("Hello world");
    std::cout<< std::endl;
    auto text_block2 = new ItalicText(new Paragraph(new Reversed(new Text())));
    text_block2->render("Hello world");
    std::cout<< std::endl;
    auto text_block3 = new Link( new BoldText(new Reversed(new Paragraph(new Text()))));
    text_block3->render("netology.ru","Hello world");
    return 0;
}
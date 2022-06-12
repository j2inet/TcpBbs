#pragma once
#include <vector>
#include <string>
#include <memory>
#include "TextElement.h"

class Screen 
{
public:
    Screen():Screen(80,25){}
    Screen(int width, int height);
    std::string GetText();
    std::vector<std::shared_ptr<TextElement>> elementList;

    void AddElement(std::shared_ptr<TextElement> element);
    std::string Render();
    
private:
    int width = 80;
    int height = 25;
};
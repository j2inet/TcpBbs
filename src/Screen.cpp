#include "Screen.h"
#include <string>
#include <iostream>
#include <sstream>


const std::string EmptyCharacter = ".";
Screen::Screen(int width, int height)
{
    this->width = width;
    this->height = height;
}


void Screen::AddElement(std::shared_ptr<TextElement> element)
{
    elementList.push_back(element);
}


std::string Screen::Render()
{
    std::stringstream ss;
    for(int ky=0;ky<height;++ky)
    {
        for(int kx = 0;kx < width; ++ kx)
        {
            std::string s;
            for(int i = 0;i<elementList.size();++i)
            {
                s = elementList[i]->GetCharAt(kx,ky);
                if(s.size())
                {
                    break;
                }
            }
            if(s.size() == 0)
            {
                s = EmptyCharacter;
            }
            ss << s;
        }
        ss << '\n';
    }
    return ss.str();
}
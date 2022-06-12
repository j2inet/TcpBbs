#include "TextElement.h"
#include <string>
#include <sstream>

TextElement::TextElement(Dimension position, Dimension size)
{
    this->position = position;
    this->size = size;
}

Dimension TextElement::getPosition()
{
    return position;
}

void TextElement::setPosition(Dimension newPosition)
{
    position = newPosition;
}

bool TextElement::HasCharAt(int x, int y)
{
    return (x>=position.x && x < (position.x+size.x)) &&
            (y>=position.y && y < (position.y+size.y));
}



bool TextElement::HasCharAt(Dimension pos)
{
    return HasCharAt(pos.x, pos.y);
}

std::string TextElement::GetLine(int line)
{

    std::string result;
    int currentLine = 0;
    int adjustedLine = line - position.x;
    if(adjustedLine <= 0 || adjustedLine > (position.x + size.x))
    {
        return "";
    }
    std::istringstream textStream(text);
    while(std::getline(textStream,result, '\n'))
    {
        if(currentLine == line)
        {
            return result;
        }
    }
    return "";
}

std::string TextElement::GetCharAt(int x, int y)
{
    //I'm not implementing word wrapping. 

    int adjustedX = x - position.x;
    int adjustedY = y - position.y;

    auto line = GetLine(y);
    if (adjustedX < 0 || adjustedX >= line.size())
    {
        return "";
    }
    if(line.size()<adjustedX)
        return std::string(1, line[adjustedX]);
    return "";
}

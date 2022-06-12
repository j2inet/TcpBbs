#pragma once
#include <string>

struct Dimension {
    int x;
    int y;
};

class TextElement
{
public:
    TextElement(Dimension position, Dimension size);
    Dimension getPosition();
    void setPosition(Dimension newPosition);
    bool HasCharAt(int x, int y);
    bool HasCharAt(Dimension pos);
    std::string GetCharAt(int x, int y);
    std::string GetLine(int line);

    int GetZOrder() { return zOrder; }
    void SetZOrder(int z) { zOrder = z; }
private:
    bool highlight = false;
    Dimension position;
    Dimension size;
    std::string text;
    int zOrder=0;
};
#include <iostream>

#ifndef TELECOMCOLORCODER_H_
#define TELECOMCOLORCODER_H_

#define MAX_COLORS 5

namespace TeleComColorCoder
{
    enum MajorColor { WHITE, RED, BLACK, YELLOW, VIOLET };
    enum MinorColor { BLUE, ORANGE, GREEN, BROWN, SLATE };

    // Added extern to avoid multiple redefinition
    extern const char *MajorColorNames[MAX_COLORS];
    extern const char *MinorColorNames[MAX_COLORS];
    extern int numberOfMinorColors;
    extern int numberOfMajorColors;

    class ColorPair
    {
    private:
        MajorColor majorColor;
        MinorColor minorColor;

    public:
        ColorPair(MajorColor major, MinorColor minor) : majorColor(major), minorColor(minor)
        {
        }
        MajorColor getMajor()
        {
            return majorColor;
        }
        MinorColor getMinor()
        {
            return minorColor;
        }
        std::string ColorPair::ToString()
        {

            std::string colorPairStr = MajorColorNames[majorColor];
            colorPairStr += " ";
            colorPairStr += MinorColorNames[minorColor];
            return colorPairStr;
        }
    };

    ColorPair GetColorFromPairNumber(int pairNumber);
    int GetPairNumberFromColor(MajorColor major, MinorColor minor);
    void DisplayColorFormat();

}

#endif // TELECOMCOLORCODER_H_
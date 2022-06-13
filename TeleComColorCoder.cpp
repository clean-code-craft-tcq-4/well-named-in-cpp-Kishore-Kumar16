#include "TeleComColorCoder.hpp"

namespace TeleComColorCoder
{
    const char *MajorColorNames[MAX_COLORS] = {
        "White", "Red", "Black", "Yellow", "Violet"};

    const char *MinorColorNames[MAX_COLORS] = {
        "Blue", "Orange", "Green", "Brown", "Slate"};

    int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);

    int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

    ColorPair GetColorFromPairNumber(int pairNumber)
    {
        int zeroBasedPairNumber = pairNumber - 1;
        MajorColor majorColor =
            (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
        MinorColor minorColor =
            (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
        return ColorPair(majorColor, minorColor);
    }

    int GetPairNumberFromColor(MajorColor major, MinorColor minor)
    {
        return major * numberOfMinorColors + minor + 1;
    }

    void DisplayColorFormat()
    {

        int index1, index2, pairNumber;

        std::cout << "PairNumber \t" << "Major Color\t" << "Minor Color\t" << std::endl;
        for (index1 = 0; index1 < numberOfMajorColors; index1++)
        {
            for (index2 = 0; index2 < numberOfMinorColors; index2++)
            {
                pairNumber = GetPairNumberFromColor(
                    (MajorColor)index1,
                    (MinorColor)index2);
                std::cout << pairNumber << "\t\t";
                std::cout << MajorColorNames[index1] << "\t\t";
                std::cout << MinorColorNames[index2] << std::endl;
            }
        }
    }
} // namespace TeleComColorCoder
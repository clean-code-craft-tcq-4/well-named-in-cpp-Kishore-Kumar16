#include "TeleComColorCoder.hpp"

std::string TeleComColorCoder::ColorPair::ToString()
{
    std::string colorPairStr = MajorColorNames[majorColor];
    colorPairStr += " ";
    colorPairStr += MinorColorNames[minorColor];
    return colorPairStr;
}

TeleComColorCoder::ColorPair TeleComColorCoder::GetColorFromPairNumber(int pairNumber) {
    int zeroBasedPairNumber = pairNumber - 1;
    TeleComColorCoder::MajorColor majorColor = 
        (TeleComColorCoder::MajorColor)(zeroBasedPairNumber / TeleComColorCoder::numberOfMinorColors);
        TeleComColorCoder::MinorColor minorColor =
        (TeleComColorCoder::MinorColor)(zeroBasedPairNumber % TeleComColorCoder::numberOfMinorColors);
    return TeleComColorCoder::ColorPair(majorColor, minorColor);
}
int TeleComColorCoder::GetPairNumberFromColor(TeleComColorCoder::MajorColor major, TeleComColorCoder::MinorColor minor) {
    return major * TeleComColorCoder::numberOfMinorColors + minor + 1;
}
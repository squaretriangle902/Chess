#include "Color.h"

Color NextColor(Color color)
{
    switch (color)
    {
    case white:
        return black;
        break;
    case black:
        return white;
        break;
    }
}

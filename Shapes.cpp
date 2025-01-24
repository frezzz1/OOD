#include "stdafx.h"
#include "ShapeController.h"

int main()
{
    ShapeController sController;
    sController.ReadShapes(INPUT_FILE);
    sController.DrawShapes();
    sController.PrintShapesInfo(OUTPUT_FILE);
    return 0;
}
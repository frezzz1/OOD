#include "ShapeController.h"
#include "stdafx.h"

int main() {
    setlocale(LC_ALL, "Russian");

    ShapeController shapeController;
    shapeController.ReadShapes(INPUT_FILE);
    shapeController.DrawShapes();
    shapeController.PrintShapesInfo(OUTPUT_FILE);
    return 0;
}
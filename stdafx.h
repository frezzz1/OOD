#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <regex>
#include <fstream>
#include <random>
#include "IShape.h"

const std::string INPUT_FILE = "input.txt";
const std::string OUTPUT_FILE = "output.txt";

const int MIN_RGB_COLOR_VALUE = 0;
const int MAX_RGB_COLOR_VALUE = 255;


const std::string ERROR_FORMAT_RECTANGLE = "Некорректный формат прямоугольника";
const std::string ERROR_FORMAT_CIRCLE = "Некорректный формат круга";
const std::string ERROR_FORMAT_TRIANGLE = "Некорректный формат треугольника";



const int WIDTH_WINDOW = 1200;
const int HEIGHT_WINDOW = 800;
const std::string TITLE_WINDOW = "Drow Shapes OOD lab1";

const std::string ERROR_OPEN_INPUT =  "Ошибка при окрытии файла"; 
const std::string ERROR_OPEN_OUTPUT = "Ошибка при окрытии файла";
const std::string UNKNOWN_FORMAT_LINE = "Неизвестный формат строки";
const std::string UNKNOWN_TYPE_FIGURE = "Неизвестный тип фигуры: ";
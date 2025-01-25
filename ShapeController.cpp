#include "ShapeController.h"
#include "ShapeCreator.h"
#include "AreaAndPerimeterPrinter.h"
#include <fstream>

void ShapeController::ReadShapes(const std::string& fileName) {
    std::ifstream input(fileName);
    if (!input.is_open()) {
        std::cerr << ERROR_OPEN_INPUT << fileName << std::endl;
        return;
    }

    std::string line;
    while (std::getline(input, line)) {
        try {
            auto shape = ShapeCreator::CreateShape(line);
            m_shapes.push_back(shape);
        }
        catch (const std::invalid_argument& ex) {
            std::cerr << "Error: " << ex.what() << " in line: " << line << std::endl;
        }
    }
}

void ShapeController::DrawShapes() {
    m_window.setVerticalSyncEnabled(true);

    if (m_shapes.empty()) {
        std::cerr << UNKNOWN_TYPE_FIGURE << std::endl;
        return; 
    }

    while (m_window.isOpen()) {
        sf::Event event;
        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                m_window.close();
            }
        }

        m_window.clear(sf::Color::White);

        for (const auto& shape : m_shapes) {
            shape->Draw(m_window);
        }

        m_window.display();
    }
}

void ShapeController::PrintShapesInfo(const std::string& fileName) {
    if (m_shapes.empty()) {
        std::cerr << EMPTY_FIGURE_PRINT << std::endl;
        return; 
    }

    std::ofstream output(fileName);
    if (!output.is_open()) {
        std::cerr << OUTPUT_FILE << fileName << std::endl;
        return; 
    }

    AreaAndPerimeterPrinter printer(output);

    for (const auto& shape : m_shapes) {
        shape->Accept(printer);
    }
}

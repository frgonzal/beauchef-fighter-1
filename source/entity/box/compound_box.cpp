#include "entity/box/compound_box.h"




namespace bf
{

    void CompoundBox::addToCanvas(Nothofagus::Canvas& canvas)
    {
        for (auto& [box, offset] : mBoxes)
        {
            box.addToCanvas(canvas);
        }
    }

    void CompoundBox::update(Nothofagus::Canvas& canvas, float deltaTime)
    {
        for (auto& [box, offset] : mBoxes)
        {
            box.update(canvas, deltaTime);
        }
    }

    void CompoundBox::addBox(const Box& box, const glm::vec2& offset)
    {
        mBoxes.emplace_back(box, offset);
    }

    void CompoundBox::AddBoxes(const std::vector<Box>& boxes)
    {
        for (const auto& box : boxes)
        {
            addBox(box);
        }
    }

    void CompoundBox::setPosition(const glm::vec2& newPosition)
    {
        for (auto& [box, offset] : mBoxes)
        {
            box.setPosition(newPosition + offset);
        }
    }
}
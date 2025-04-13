#include "entity/box/compound_box.h"




namespace bf
{

    void CompoundBox::addToCanvas(Nothofagus::Canvas &canvas)
    {
        for (Box &box : mBoxes)
        {
            box.addToCanvas(canvas);
        }
    }

    void CompoundBox::update(Nothofagus::Canvas &canvas, float deltaTime)
    {
        for (Box &box : mBoxes)
        {
            box.update(canvas, deltaTime);
        }
    }

    CompoundBox& CompoundBox::addBox(const Box &box, const glm::vec2& offset)
    {
        mBoxes.emplace_back(box);
        mOffsets.emplace_back(offset);
        return *this;
    }

    CompoundBox& CompoundBox::setPosition(const glm::vec2& newPosition)
    {
        for (size_t i = 0; i < mBoxes.size(); ++i)
        {
            glm::vec2 offset = mOffsets[i];
            mBoxes[i].setPosition(newPosition + offset);
        }
        return *this;
    }

    const std::vector<Box> &CompoundBox::getBoxes() const
    {
        return mBoxes;
    }

    bool CompoundBox::collides(const Collidable *other) const
    {
        return other->collidesWithCompoundBox(this);
    }

    bool CompoundBox::collidesWithBox(const Box *box) const
    {
        for (const Box &b : mBoxes)
        {
            if (b.collidesWithBox(box))
            {
                return true;
            }
        }
        return false;
    }

    bool CompoundBox::collidesWithCompoundBox(const CompoundBox *compoundBox) const
    {
        for (const Box &box : compoundBox->getBoxes())
        {
            if (collidesWithBox(&box))
            {
                return true;
            }
        }
        return false;
    }

    void CompoundBox::reflectOverYAxis()
    {
        for (int i = 0; i < mBoxes.size(); ++i)
        {
            mOffsets[i].x = 2 * mPosition.x - mOffsets[i].x;
            mBoxes[i].setPosition(mPosition + mOffsets[i]);
        }
    }

    void CompoundBox::reflectOverYAxis(const float xPosition)
    {
        mPosition.x = 2 * xPosition - mPosition.x;
        reflectOverYAxis();
    }
}
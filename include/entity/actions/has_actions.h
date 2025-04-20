#pragma once
#include "action.h"


namespace bf
{
    class HasActions
    {
    public:
        virtual void setDefaultAction(Action action) = 0;
        virtual void startAction(Action action) = 0;
        virtual void stopAction() = 0;
    };
}
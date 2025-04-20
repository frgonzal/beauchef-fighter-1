#pragma once    


namespace bf
{
    enum class Action
    {
        STATIC,

        STAND,
        STEP_LEFT,
        STEP_RIGHT,

        LEFT_ARM_ATTACK,
        PREPARE_LEFT_ARM_ATTACK,

        LEFT_LEG_ATTACK,
        PREPARE_LEFT_LEG_ATTACK,

        BLOCK,
    };

    inline std::string getActionName(const Action action)
    {
        switch (action)
        {
            case Action::STATIC: return "STATIC";
            case Action::STAND: return "STAND";
            case Action::STEP_LEFT: return "STEP_LEFT";
            case Action::STEP_RIGHT: return "STEP_RIGHT";
            case Action::LEFT_ARM_ATTACK: return "LEFT_ARM_ATTACK";
            case Action::BLOCK: return "BLOCK";
            default: return "UNKNOWN_ACTION";
        }
    }
}
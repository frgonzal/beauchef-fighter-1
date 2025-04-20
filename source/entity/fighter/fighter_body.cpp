#include "entity/fighter/fighter.h"
#include "entity/actions/action.h"


namespace bf
{
    void Fighter::initBody()
    {
        /** STAND **/
        mMainBody.addBoxToSprite(Action::STAND, Box(2, 3), {1.0f, 11.5f})
                 .addBoxToSprite(Action::STAND, Box(1, 1), {0.5f,  9.5f})
                 .addBoxToSprite(Action::STAND, Box(3, 3), {0.5f,  7.5f})
                 .addBoxToSprite(Action::STAND, Box(1, 3), {0.5f,  4.5f})
                 .addBoxToSprite(Action::STAND, Box(2, 1), {0.0f,  2.5f})
                 .addBoxToSprite(Action::STAND, Box(2, 1), {0.0f,  1.5f})
                 .addBoxToSprite(Action::STAND, Box(3, 1), {0.5f,  0.5f});

        mRightLeg.addBoxToSprite(Action::STAND, Box(1, 5), { 0.5f, 6.5f})
                 .addBoxToSprite(Action::STAND, Box(1, 5), {-0.5f, 2.5f})
                 .addBoxToSprite(Action::STAND, Box(2, 1), { 0.0f,-0.5f});

        mLeftLeg.addBoxToSprite(Action::STAND, Box(1, 2), {0.5f, 8.0f})
                .addBoxToSprite(Action::STAND, Box(1, 4), {1.5f, 6.0f})
                .addBoxToSprite(Action::STAND, Box(1, 4), {0.5f, 2.5f})
                .addBoxToSprite(Action::STAND, Box(2, 1), {1.0f, 0.5f});

        mRightArm.addBoxToSprite(Action::STAND, Box(1, 3), {-0.5f, -0.5f})
                 .addBoxToSprite(Action::STAND, Box(3, 1), { 0.5f, -2.5f});

        mLeftArm.addBoxToSprite(Action::STAND, Box(2, 1), {0.0f, -1.5f})
                .addBoxToSprite(Action::STAND, Box(1, 2), {1.5f, -1.0f});


        /** STEP LEFT **/
        mRightLeg.addBoxToSprite(Action::STEP_LEFT, Box(1, 4), {-0.5f,  8.0f})
                 .addBoxToSprite(Action::STEP_LEFT, Box(1, 4), { 0.5f,  5.0f})
                 .addBoxToSprite(Action::STEP_LEFT, Box(1, 3), {-0.5f,  2.5f})
                 .addBoxToSprite(Action::STEP_LEFT, Box(2, 1), { 0.0f,  0.5f});

        mLeftLeg.addBoxToSprite(Action::STEP_LEFT, Box(1, 3), { 0.5f,  7.5f})
                .addBoxToSprite(Action::STEP_LEFT, Box(1, 7), { 1.5f,  3.5f})
                .addBoxToSprite(Action::STEP_LEFT, Box(2, 1), { 2.0f, -0.5f});

        mRightArm.addBoxToSprite(Action::STEP_LEFT, Box(1, 3), {-0.5f, -0.5f})
                 .addBoxToSprite(Action::STEP_LEFT, Box(3, 1), { 0.5f, -2.5f});

        mLeftArm.addBoxToSprite(Action::STEP_LEFT, Box(1, 4), { 0.5f, -1.0f})
                .addBoxToSprite(Action::STEP_LEFT, Box(2, 1), { 1.0f, -3.5f});

        /** STEP RIGHT **/
        mRightLeg.addBoxToSprite(Action::STEP_RIGHT, Box(1,  1), { 0.5f,  8.5f})
                 .addBoxToSprite(Action::STEP_RIGHT, Box(1, 10), {-0.5f,  5.0f})
                 .addBoxToSprite(Action::STEP_RIGHT, Box(2,  1), { 0.0f, -0.5f});

        mLeftLeg.addBoxToSprite(Action::STEP_RIGHT, Box(1, 2), {0.5f,  8.0f})
                .addBoxToSprite(Action::STEP_RIGHT, Box(1, 4), {1.5f,  6.0f})
                .addBoxToSprite(Action::STEP_RIGHT, Box(1, 4), {0.5f,  2.5f})
                .addBoxToSprite(Action::STEP_RIGHT, Box(2, 1), {1.0f,  0.5f});

        mRightArm.addBoxToSprite(Action::STEP_RIGHT, Box(1, 4), {-0.5f, -1.0f})
                 .addBoxToSprite(Action::STEP_RIGHT, Box(2, 1), { 0.0f, -3.5f});

        mLeftArm.addBoxToSprite(Action::STEP_RIGHT, Box(2, 1), {0.0f, -1.5f})
                .addBoxToSprite(Action::STEP_RIGHT, Box(1, 2), {1.5f, -1.0f});

        
        /** PREPARE LEFT ARM ATTACK **/
        mRightLeg.addBoxToSprite(Action::PREPARE_LEFT_ARM_ATTACK, Box(1, 5), { 0.5f,  6.5f})
                 .addBoxToSprite(Action::PREPARE_LEFT_ARM_ATTACK, Box(1, 5), {-0.5f,  2.5f})
                 .addBoxToSprite(Action::PREPARE_LEFT_ARM_ATTACK, Box(2, 1), { 0.0f, -0.5f});

        mLeftLeg.addBoxToSprite(Action::PREPARE_LEFT_ARM_ATTACK, Box(2, 1), {1.0f,  8.5f})
                .addBoxToSprite(Action::PREPARE_LEFT_ARM_ATTACK, Box(2, 1), {2.0f,  7.5f})
                .addBoxToSprite(Action::PREPARE_LEFT_ARM_ATTACK, Box(1, 3), {2.5f,  5.5f})
                .addBoxToSprite(Action::PREPARE_LEFT_ARM_ATTACK, Box(1, 3), {1.5f,  3.5f})
                .addBoxToSprite(Action::PREPARE_LEFT_ARM_ATTACK, Box(1, 3), {0.5f,  1.5f})
                .addBoxToSprite(Action::PREPARE_LEFT_ARM_ATTACK, Box(2, 1), {1.0f, -0.5f});

        mRightArm.addBoxToSprite(Action::PREPARE_LEFT_ARM_ATTACK, Box(2, 2), {0.0f,  0.0f})
                 .addBoxToSprite(Action::PREPARE_LEFT_ARM_ATTACK, Box(4, 1), {1.0f, -1.5f});

        mLeftArm.addBoxToSprite(Action::PREPARE_LEFT_ARM_ATTACK, Box(1, 1), {0.5f, -0.5f});


        /** LEFT ARM ATTACK **/
        mMainBody.addBoxToSprite(Action::LEFT_ARM_ATTACK, Box(2, 3), { 1.0f, 11.5f})
                 .addBoxToSprite(Action::LEFT_ARM_ATTACK, Box(1, 1), { 0.5f,  9.5f})
                 .addBoxToSprite(Action::LEFT_ARM_ATTACK, Box(1, 1), {-0.5f,  7.5f})
                 .addBoxToSprite(Action::LEFT_ARM_ATTACK, Box(2, 3), { 1.0f,  7.5f})
                 .addBoxToSprite(Action::LEFT_ARM_ATTACK, Box(1, 3), { 0.5f,  4.5f})
                 .addBoxToSprite(Action::LEFT_ARM_ATTACK, Box(2, 1), { 0.0f,  2.5f})
                 .addBoxToSprite(Action::LEFT_ARM_ATTACK, Box(2, 1), { 0.0f,  1.5f})
                 .addBoxToSprite(Action::LEFT_ARM_ATTACK, Box(3, 1), { 0.5f,  0.5f});

        mRightLeg.addBoxToSprite(Action::LEFT_ARM_ATTACK, Box(1, 5), { 0.5f,  6.5f})
                 .addBoxToSprite(Action::LEFT_ARM_ATTACK, Box(1, 5), {-0.5f,  2.5f})
                 .addBoxToSprite(Action::LEFT_ARM_ATTACK, Box(2, 1), { 0.0f, -0.5f});

        mLeftLeg.addBoxToSprite(Action::LEFT_ARM_ATTACK, Box(2, 1), {1.0f,  8.5f})
                .addBoxToSprite(Action::LEFT_ARM_ATTACK, Box(2, 1), {2.0f,  7.5f})
                .addBoxToSprite(Action::LEFT_ARM_ATTACK, Box(1, 7), {2.5f,  3.5f})
                .addBoxToSprite(Action::LEFT_ARM_ATTACK, Box(2, 1), {3.0f, -0.5f});

        mRightArm.addBoxToSprite(Action::LEFT_ARM_ATTACK, Box(2, 2), {0.0f, -1.0f})
                 .addBoxToSprite(Action::LEFT_ARM_ATTACK, Box(4, 1), {1.0f, -2.5f});

        mLeftArm.addBoxToSprite(Action::LEFT_ARM_ATTACK, Box(5, 1), {2.5f, 1.5f});


        /** PREPARE LEFT LEG ATTACK **/
        mMainBody.addBoxToSprite(Action::PREPARE_LEFT_LEG_ATTACK, Box(2, 3), { 0.0f, 11.5f})
                 .addBoxToSprite(Action::PREPARE_LEFT_LEG_ATTACK, Box(1, 1), {-0.5f,  9.5f})
                 .addBoxToSprite(Action::PREPARE_LEFT_LEG_ATTACK, Box(3, 3), {-0.5f,  7.5f})
                 .addBoxToSprite(Action::PREPARE_LEFT_LEG_ATTACK, Box(1, 3), { 0.5f,  4.5f})
                 .addBoxToSprite(Action::PREPARE_LEFT_LEG_ATTACK, Box(2, 1), { 0.0f,  2.5f})
                 .addBoxToSprite(Action::PREPARE_LEFT_LEG_ATTACK, Box(2, 1), { 0.0f,  1.5f})
                 .addBoxToSprite(Action::PREPARE_LEFT_LEG_ATTACK, Box(3, 1), { 0.5f,  0.5f});

        mRightLeg.addBoxToSprite(Action::PREPARE_LEFT_LEG_ATTACK, Box(1, 6), {-0.5f,  7.0f})
                 .addBoxToSprite(Action::PREPARE_LEFT_LEG_ATTACK, Box(1, 4), { 0.5f,  3.0f})
                 .addBoxToSprite(Action::PREPARE_LEFT_LEG_ATTACK, Box(1, 3), { 1.5f,  1.5f})
                 .addBoxToSprite(Action::PREPARE_LEFT_LEG_ATTACK, Box(2, 1), { 1.0f, -0.5f});

        mLeftLeg.addBoxToSprite(Action::PREPARE_LEFT_LEG_ATTACK, Box(2, 1), {0.0f,  8.5f})
                .addBoxToSprite(Action::PREPARE_LEFT_LEG_ATTACK, Box(1, 2), {1.5f,  9.0f})
                .addBoxToSprite(Action::PREPARE_LEFT_LEG_ATTACK, Box(1, 5), {2.5f,  6.5f})
                .addBoxToSprite(Action::PREPARE_LEFT_LEG_ATTACK, Box(2, 1), {3.0f,  3.5f});

        mRightArm.addBoxToSprite(Action::PREPARE_LEFT_LEG_ATTACK, Box(1, 3), {-0.5f, -0.5f})
                 .addBoxToSprite(Action::PREPARE_LEFT_LEG_ATTACK, Box(2, 1), { 0.0f, -2.5f});

        mLeftArm.addBoxToSprite(Action::PREPARE_LEFT_LEG_ATTACK, Box(1, 2), {-0.5f, -2.0f})
                .addBoxToSprite(Action::PREPARE_LEFT_LEG_ATTACK, Box(1, 3), { 0.5f, -0.5f});


        /** LEFT LEG ATTACK **/
        mMainBody.addBoxToSprite(Action::LEFT_LEG_ATTACK, Box(2, 3), {-1.0f, 11.5f})
                 .addBoxToSprite(Action::LEFT_LEG_ATTACK, Box(1, 2), {-1.5f,  9.0f})
                 .addBoxToSprite(Action::LEFT_LEG_ATTACK, Box(1, 1), {-0.5f,  8.5f})
                 .addBoxToSprite(Action::LEFT_LEG_ATTACK, Box(3, 2), {-0.5f,  7.0f})
                 .addBoxToSprite(Action::LEFT_LEG_ATTACK, Box(1, 3), { 0.5f,  4.5f})
                 .addBoxToSprite(Action::LEFT_LEG_ATTACK, Box(2, 1), { 0.0f,  2.5f})
                 .addBoxToSprite(Action::LEFT_LEG_ATTACK, Box(2, 1), { 0.0f,  1.5f})
                 .addBoxToSprite(Action::LEFT_LEG_ATTACK, Box(3, 1), { 0.5f,  0.5f});

        mRightLeg.addBoxToSprite(Action::LEFT_LEG_ATTACK, Box(1, 2), { 0.5f,  8.0f})
                 .addBoxToSprite(Action::LEFT_LEG_ATTACK, Box(1, 4), {-0.5f,  6.0f})
                 .addBoxToSprite(Action::LEFT_LEG_ATTACK, Box(1, 3), { 0.5f,  3.5f})
                 .addBoxToSprite(Action::LEFT_LEG_ATTACK, Box(1, 3), { 1.5f,  1.5f})
                 .addBoxToSprite(Action::LEFT_LEG_ATTACK, Box(2, 1), { 1.0f, -0.5f});

        mLeftLeg.addBoxToSprite(Action::LEFT_LEG_ATTACK, Box(1, 1), {0.5f, 10.5f})
                .addBoxToSprite(Action::LEFT_LEG_ATTACK, Box(1, 2), {1.5f, 11.0f})
                .addBoxToSprite(Action::LEFT_LEG_ATTACK, Box(1, 2), {2.5f, 12.0f})
                .addBoxToSprite(Action::LEFT_LEG_ATTACK, Box(2, 1), {4.0f, 13.5f})
                .addBoxToSprite(Action::LEFT_LEG_ATTACK, Box(2, 1), {6.0f, 14.5f})
                .addBoxToSprite(Action::LEFT_LEG_ATTACK, Box(1, 2), {7.5f, 15.0f});

        mRightArm.addBoxToSprite(Action::LEFT_LEG_ATTACK, Box(1, 3), {-1.5f, -0.5f})
                 .addBoxToSprite(Action::LEFT_LEG_ATTACK, Box(2, 1), { 0.0f, -1.5f});

        mLeftArm.addBoxToSprite(Action::LEFT_LEG_ATTACK, Box(1, 2), {-0.5f,  1.0f})
                .addBoxToSprite(Action::LEFT_LEG_ATTACK, Box(1, 2), { 0.5f,  2.0f});


        /** BLOCK ACTION **/
        mMainBody.addBoxToSprite(Action::BLOCK, Box(2, 3), {-1.0f, 11.5f})
                 .addBoxToSprite(Action::BLOCK, Box(1, 1), {-1.5f,  9.5f})
                 .addBoxToSprite(Action::BLOCK, Box(1, 2), {-1.5f,  8.0f})
                 .addBoxToSprite(Action::BLOCK, Box(1, 3), {-0.5f,  7.5f})
                 .addBoxToSprite(Action::BLOCK, Box(1, 2), { 0.5f,  7.0f})
                 .addBoxToSprite(Action::BLOCK, Box(1, 3), { 0.5f,  4.5f})
                 .addBoxToSprite(Action::BLOCK, Box(2, 1), { 0.0f,  2.5f})
                 .addBoxToSprite(Action::BLOCK, Box(2, 1), { 0.0f,  1.5f})
                 .addBoxToSprite(Action::BLOCK, Box(3, 1), { 0.5f,  0.5f});
        
        mRightArm.addBoxToSprite(Action::BLOCK, Box(1, 3), {3.5f,  1.5f})
                 .addBoxToSprite(Action::BLOCK, Box(2, 1), {3.0f, -0.5f});
                
        mLeftArm.addBoxToSprite(Action::BLOCK, Box(1, 3), {-0.5f, 3.5f})
                .addBoxToSprite(Action::BLOCK, Box(2, 1), {-1.0f, 1.5f});

        mRightLeg.addBoxToSprite(Action::BLOCK, Box(1, 5), { 0.5f,  6.5f})
                 .addBoxToSprite(Action::BLOCK, Box(1, 5), {-0.5f,  2.5f})
                 .addBoxToSprite(Action::BLOCK, Box(2, 1), { 0.0f, -0.5f});

        mLeftLeg.addBoxToSprite(Action::BLOCK, Box(2, 1), {1.0f,  8.5f})
                .addBoxToSprite(Action::BLOCK, Box(2, 1), {2.0f,  7.5f})
                .addBoxToSprite(Action::BLOCK, Box(1, 7), {2.5f,  3.5f})
                .addBoxToSprite(Action::BLOCK, Box(2, 1), {3.0f, -0.5f});
    }
}
#include "entity/fighter/fighter.h"
#include "audio.h"
#include <cstdlib>


namespace bf
{
    void Fighter::playStepSound()
    {
        int soundIndex = std::rand() % mStepSoundBuffers.size();
        mStepSoundPlayers[soundIndex]->play();
    }

    void Fighter::playAttackSound()
    {
        int soundIndex = std::rand() % mAttackSoundBuffers.size();
        mAttackSoundPlayers[soundIndex]->play();
    }

    void Fighter::playBlockSound()
    {
        mBlockSoundPlayer.play();
    }

    void Fighter::initSoundPlayer()
    {

        /** ATTACK SOUNDS **/
        RustyAudio::Builder attackSoundBuilder1;
        attackSoundBuilder1.appendSinusoids({
            { 20.0f, 0.80000f, 1200.0f },
            { 20.0f, 0.75000f, 1000.0f },
            { 20.0f, 0.70000f,  800.0f },
            { 20.0f, 0.60000f,  650.0f },
            { 20.0f, 0.50000f,  550.0f },
            { 20.0f, 0.40000f,  450.0f },
            { 20.0f, 0.30000f,  350.0f },
            { 20.0f, 0.20000f,  300.0f },
            { 20.0f, 0.15000f,  250.0f },
            { 20.0f, 0.10000f,  200.0f },

        });
        mAttackSoundBuffers.emplace_back(attackSoundBuilder1.generate(Audio::sampleRate, Audio::channels));
        mAttackSoundPlayers.emplace_back(std::make_unique<RustyAudio::Player>());

        RustyAudio::Builder attackSoundBuilder2;
        attackSoundBuilder2.appendSinusoids({
            {  5.0f, 1.00000f, 1000.0f },  
            {  5.0f, 0.90000f,  800.0f }, 
            {  5.0f, 0.80000f,  600.0f }, 
            {  5.0f, 0.70000f,  400.0f }, 
            { 80.0f, 0.60000f,   60.0f } 
        });
        mAttackSoundBuffers.emplace_back(attackSoundBuilder2.generate(Audio::sampleRate, Audio::channels));
        mAttackSoundPlayers.emplace_back(std::make_unique<RustyAudio::Player>());
        RustyAudio::Builder attackSoundBuilder3;
        attackSoundBuilder3.appendSinusoids({
            {  8.0f, 1.00000f, 1500.0f },
            {  8.0f, 0.90000f, 1000.0f },
            {  8.0f, 0.80000f,  500.0f },
            { 70.0f, 0.60000f,   80.0f }
        });
        mAttackSoundBuffers.emplace_back(attackSoundBuilder3.generate(Audio::sampleRate, Audio::channels));
        mAttackSoundPlayers.emplace_back(std::make_unique<RustyAudio::Player>());

        RustyAudio::Builder attackSoundBuilder4;
        attackSoundBuilder4.appendSinusoids({
            { 10.0f, 1.00000f, 400.0f },
            { 10.0f, 0.90000f, 300.0f },
            { 10.0f, 0.80000f, 200.0f },
            { 40.0f, 0.70000f, 250.0f },
            { 50.0f, 0.50000f, 200.0f }
        });
        mAttackSoundBuffers.emplace_back(attackSoundBuilder4.generate(Audio::sampleRate, Audio::channels));
        mAttackSoundPlayers.emplace_back(std::make_unique<RustyAudio::Player>());

        RustyAudio::Builder attackSoundBuilder5;
        attackSoundBuilder5.appendSinusoids({
            {  5.0f, 1.00000f, 1000.0f },  
            {  5.0f, 0.90000f,  800.0f }, 
            {  5.0f, 0.80000f,  600.0f }, 
            {  5.0f, 0.70000f,  400.0f }, 
            { 80.0f, 0.60000f,   60.0f } 
        });
        mAttackSoundBuffers.emplace_back(attackSoundBuilder5.generate(Audio::sampleRate, Audio::channels));
        mAttackSoundPlayers.emplace_back(std::make_unique<RustyAudio::Player>());

        for (int i = 0; i < mAttackSoundBuffers.size(); ++i)
        {
            mAttackSoundPlayers[i]->init(mAttackSoundBuffers[i]);
            mAttackSoundPlayers[i]->setLooping(false);
        }

        
        /** STEP SOUNDS **/
        RustyAudio::Builder stepSoundBuilder1;
        stepSoundBuilder1.appendSinusoids({
            { 15.0f, 0.75000f, 160.0f },
            { 25.0f, 0.50000f,  90.0f },
            { 50.0f, 0.25000f,  60.0f }
        });
        mStepSoundBuffers.emplace_back(stepSoundBuilder1.generate(Audio::sampleRate, Audio::channels));
        mStepSoundPlayers.emplace_back(std::make_unique<RustyAudio::Player>());

        RustyAudio::Builder stepSoundBuilder2;
        stepSoundBuilder2.appendSinusoids({
            { 10.0f, 0.90000f, 120.0f },
            { 30.0f, 0.70000f,  90.0f },
            { 50.0f, 0.40000f,  50.0f }
        });
        mStepSoundBuffers.emplace_back(stepSoundBuilder2.generate(Audio::sampleRate, Audio::channels));
        mStepSoundPlayers.emplace_back(std::make_unique<RustyAudio::Player>());

        RustyAudio::Builder stepSoundBuilder3;
        stepSoundBuilder3.appendSinusoids({
            { 20.0f, 0.90000f,  100.0f },
            { 40.0f, 0.60000f,  60.0f },
            { 20.0f, 0.30000f,  40.0f }
        });
        mStepSoundBuffers.emplace_back(stepSoundBuilder3.generate(Audio::sampleRate, Audio::channels));
        mStepSoundPlayers.emplace_back(std::make_unique<RustyAudio::Player>());

        RustyAudio::Builder stepSoundBuilder4;
        stepSoundBuilder4.appendSinusoids({
            { 15.0f, 0.80000f, 150.0f },
            { 25.0f, 0.50000f, 100.0f },
            { 50.0f, 0.20000f,  70.0f }
        });
        mStepSoundBuffers.emplace_back(stepSoundBuilder4.generate(Audio::sampleRate, Audio::channels));
        mStepSoundPlayers.emplace_back(std::make_unique<RustyAudio::Player>());

        for (int i = 0; i < mStepSoundBuffers.size(); ++i)
        {
            mStepSoundPlayers[i]->init(mStepSoundBuffers[i]);
            mStepSoundPlayers[i]->setLooping(false);
        }


        /** BLOCK SOUND **/
        RustyAudio::Builder blockSoundBuilder;
        blockSoundBuilder.appendSinusoids({
            { 10.0f, 0.80000f, 300.0f },
            { 10.0f, 0.70000f, 600.0f },
            { 15.0f, 0.60000f, 900.0f },
            { 20.0f, 0.50000f, 1200.0f },
            { 20.0f, 0.40000f, 1500.0f },
            { 25.0f, 0.30000f, 1800.0f },
            { 30.0f, 0.20000f, 2100.0f }
        });

        mBlockSoundBuffer = blockSoundBuilder.generate(Audio::sampleRate, Audio::channels);
        mBlockSoundPlayer.init(mBlockSoundBuffer);
        mBlockSoundPlayer.setLooping(false);
    }
}
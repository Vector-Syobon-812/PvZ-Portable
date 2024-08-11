#include "SDLSoundInstance.h"
#include "SDLSoundManager.h"

using namespace Sexy;

SDLSoundInstance::SDLSoundInstance(SDLSoundManager* theSoundManager, Mix_Chunk* theSourceSound)
{
	mSoundManagerP = theSoundManager;
	mMixChunk = theSourceSound;
	mReleased = false;
	mAutoRelease = false;
	mHasPlayed = false;
	mChannel = -1;

	mBaseVolume = 1.0;
	mBasePan = 0;

	mVolume = 1.0;
	mPan = 0;

	mDefaultFrequency = 44100;

	RehupVolume();
}

SDLSoundInstance::~SDLSoundInstance()
{
	
}

void SDLSoundInstance::RehupVolume()
{
	Mix_VolumeChunk(mMixChunk, (mBaseVolume * mVolume * mSoundManagerP->mMasterVolume) * 128);
}

void SDLSoundInstance::RehupPan()
{
	//if (mSoundBuffer != NULL)
		//mSoundBuffer->SetPan(mBasePan + mPan);
}

void SDLSoundInstance::Release()
{
	Stop();
	mReleased = true;
}

void SDLSoundInstance::SetBaseVolume(double theBaseVolume)
{
	mBaseVolume = theBaseVolume;
	RehupVolume();
}

void SDLSoundInstance::SetBasePan(int theBasePan)
{
	mBasePan = theBasePan;
	RehupPan();
}

void SDLSoundInstance::AdjustPitch(double theNumSteps)
{
	
}

void SDLSoundInstance::SetVolume(double theVolume)
{
	mVolume = theVolume;
	RehupVolume();
}

void SDLSoundInstance::SetPan(int thePosition) //-hundredth db to +hundredth db = left to right
{
	mPan = thePosition;
	RehupPan();
}

bool SDLSoundInstance::Play(bool looping, bool autoRelease)
{
	Stop();

	mHasPlayed = true;	
	mAutoRelease = autoRelease;	

	if (!mMixChunk)
		return false;

	mChannel = Mix_PlayChannel(-1, mMixChunk, (looping) ? -1 : 0);
	return mChannel != -1;
}

void SDLSoundInstance::Stop()
{
	if (mChannel != -1)
	{
		Mix_HaltChannel(mChannel);
		mAutoRelease = false;
	}
}

bool SDLSoundInstance::IsPlaying()
{
	if (!mMixChunk || !mHasPlayed || mChannel == -1)
		return false;
	return Mix_Playing(mChannel);
}

bool SDLSoundInstance::IsReleased()
{
	if ((!mReleased) && (mAutoRelease) && (mHasPlayed) && (!IsPlaying()))
		Release();

	return mReleased;
}

double SDLSoundInstance::GetVolume()
{
	return mVolume; 
}

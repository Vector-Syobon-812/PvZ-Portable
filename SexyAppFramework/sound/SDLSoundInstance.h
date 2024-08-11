#ifndef __SDLSOUNDINSTANCE_H__
#define __SDLSOUNDINSTANCE_H__

#include "SoundInstance.h"
#include <SDL.h>
#include <SDL_mixer.h>

namespace Sexy
{

class SDLSoundManager;

class SDLSoundInstance : public SoundInstance
{
	friend class SDLSoundManager;

protected:
	SDLSoundManager*		mSoundManagerP;
	Mix_Chunk*				mMixChunk;
	bool					mAutoRelease;
	bool					mHasPlayed;
	bool					mReleased;
	int						mChannel;

	int						mBasePan;
	double					mBaseVolume;

	int						mPan;
	double					mVolume;	

	uint32_t				mDefaultFrequency;

protected:
	void					RehupVolume();
	void					RehupPan();

public:
	SDLSoundInstance(SDLSoundManager* theSoundManager, Mix_Chunk* theSourceSound);
	virtual ~SDLSoundInstance();
	virtual void			Release();
		
	virtual void			SetBaseVolume(double theBaseVolume);
	virtual void			SetBasePan(int theBasePan);

	virtual void			AdjustPitch(double theNumSteps);

	virtual void			SetVolume(double theVolume); 
	virtual void			SetPan(int thePosition); //-hundredth db to +hundredth db = left to right

	virtual bool			Play(bool looping, bool autoRelease);
	virtual void			Stop();
	virtual bool			IsPlaying();
	virtual bool			IsReleased();
	virtual double			GetVolume();
};

}

#endif //__SOUNDINSTANCE_H__
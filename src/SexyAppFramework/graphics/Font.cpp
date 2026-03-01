#include "Font.h"

using namespace Sexy;

_Font::_Font()
{	
	mAscent = 0;
	mAscentPadding = 0;
	mHeight = 0;
	mLineSpacingOffset = 0;
}

_Font::_Font(const _Font& theFont) :
	mAscent(theFont.mAscent),
	mAscentPadding(theFont.mAscentPadding),
	mHeight(theFont.mHeight),
	mLineSpacingOffset(theFont.mLineSpacingOffset)
{
}

_Font::~_Font()
{
}

int	_Font::GetAscent()
{
	return mAscent;
}

int	_Font::GetAscentPadding()
{
	return mAscentPadding;
}

int	_Font::GetDescent()
{
	return mHeight - mAscent;
}

int	_Font::GetHeight()
{
	return mHeight;
}

int _Font::GetLineSpacingOffset()
{
	return mLineSpacingOffset;
}

int _Font::GetLineSpacing()
{
	return mHeight + mLineSpacingOffset;
}

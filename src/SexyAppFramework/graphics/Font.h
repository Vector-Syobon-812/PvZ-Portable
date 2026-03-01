#ifndef __FONT_H__
#define __FONT_H__

#include "Common.h"
#include "misc/Rect.h"
#include "Color.h"
#include <string>

namespace Sexy
{

class Graphics;

class _Font
{
public:
	int						mAscent;
	int						mAscentPadding; // How much space is above the avg uppercase char
	int						mHeight;
	int						mLineSpacingOffset; // This plus height should get added between lines
public:
	_Font();
	_Font(const _Font& theFont);
	virtual ~_Font();

	virtual int				GetAscent();
	virtual int				GetAscentPadding();
	virtual int				GetDescent();
	virtual int				GetHeight();
	virtual int				GetLineSpacingOffset();
	virtual int				GetLineSpacing();
	virtual int				StringWidth(const std::string& theString) = 0;
	virtual int				CharWidth(char32_t theChar) = 0;
	virtual int				CharWidthKern(char32_t theChar, char32_t thePrevChar) = 0;

	virtual void			DrawString(Graphics* g, int theX, int theY, const std::string& theString, const Color& theColor, const Rect& theClipRect) = 0;

	virtual _Font*			Duplicate() = 0;
};

}

#endif //__FONT_H__

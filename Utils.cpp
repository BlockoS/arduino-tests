/**************************************************************************//**
 * @file Utils.cpp
 *
 * @par Copyright: 
 * - Copyright (C) 2011 by Vincent Cruz.
 * All rights reserved.
 *
 * @author Vincent Cruz cruz.vincent@gmail.com
 *
 * @par Description:
 *  Simple Unit test framework. @n
 *  Based on UnitTest++ by Noel Llopis and Charles Nicholson. @n
 *  This is basically a stripped down version meant to be run on a
 *  microcontroller.
 *
 * @par History:
 * - Version 0.1, 28 Dec 2011.
 *
 * @par Licence: GPLv3
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version. @n
 * @n
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details. @n
 * @n
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *****************************************************************************/
#include "Utils.h"

namespace Dummy
{
    /**
     * @addtogroup DummyUnitTest
     * @{
     **/
	bool IsEqual(char const* expected, char const* value)
	{
		return (!strcmp(expected, value));
	}

	bool IsEqual(char* expected, char const* value)
	{
		return (!strcmp(expected, value));
	}

	bool IsEqual(char* expected, char* value)
	{
		return (!strcmp(expected, value));
	}
    /** @} **/
    
    /**
     * @defgroup Stringify String conversion functions.
     * @{
     **/
    int Stringify(char value, char* buffer, int bufferLen)
    {
        return snprintf(buffer, bufferLen, "%c", value);
    }
    
    int Stringify(int value, char* buffer, int bufferLen)
    {
        return snprintf(buffer, bufferLen, "%d", value);
    }
    
    int Stringify(float value, char* buffer, int bufferLen)
    {
        return snprintf(buffer, bufferLen, "%f", (double)value);
    }
    
    int Stringify(char const* value, char* buffer, int bufferLen)
    {
        char const* ptr = value;
        for(; *ptr && bufferLen; --bufferLen, ++ptr)
        {
            *buffer++ = *ptr;
        }
        if(bufferLen) *buffer = '\0';
        return (ptr - value);
    }

    int Stringify(char* value, char* buffer, int bufferLen)
    {
        return Stringify(const_cast<char const*>(value), buffer, bufferLen);
    }
    
    int Stringify(void const* value, char* buffer, int bufferLen)
    {
        return snprintf(buffer, bufferLen, "%p", value);
    }
    /** @} **/
    /** @} **/
}
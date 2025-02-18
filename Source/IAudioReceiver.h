/**
    bespoke synth, a software modular synthesizer
    Copyright (C) 2021 Ryan Challinor (contact: awwbees@gmail.com)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
**/
//
//  IAudioReceiver.h
//  modularSynth
//
//  Created by Ryan Challinor on 12/11/12.
//
//

#ifndef modularSynth_IAudioReceiver_h
#define modularSynth_IAudioReceiver_h

#include "ChannelBuffer.h"

class IAudioReceiver
{
public:
   enum InputMode
   {
      kInputMode_Mono,
      kInputMode_Multichannel
   };
   
   IAudioReceiver(int bufferSize) : mInputBuffer(bufferSize) {}
   virtual ~IAudioReceiver() {}
   virtual ChannelBuffer* GetBuffer() { return &mInputBuffer; }
   virtual InputMode GetInputMode() { return kInputMode_Multichannel; }
protected:
   void SyncInputBuffer();
private:
   ChannelBuffer mInputBuffer;
};

#endif

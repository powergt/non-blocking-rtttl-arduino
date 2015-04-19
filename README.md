# Non-blocking Ringtone Text Transfer melodies

This provides an implementation of a Non-blocking Arduino library to play RTTTL melodies  (Nokia Ringtones stored as a text string). It has been tested on Arduino Uno and [Shrimp](http://shrimping.it/blog/shrimp)

It is non-blocking in that calls can be made periodically to library functions to progressively update the hardware PWM tones being played by an ATMEGA chip to match with a loaded melody. 

Key functions:

* **pollSong()** since the hardware handles PWM playback, you can continue to service other microcontroller functions between calls to pollSong(), which will only change the PWM output if necessary (according to the melody) and then return immediately.
* **stepSong()** this progresses the melody, but also blocks until a single note is finished. It is useful, for example, to write simple code which couples lighting effects to notes.
* **finishSong()** this plays out the whole melody once, blocking until it's finished. It's useful if a tune needs to be completed before the next action should be taken (e.g. playout when a game has ended and before it resets).



# ICDB

In-Circuit Debugger; the world's most novelly named thing in the history of ever.

This is a hardware/software project I've started developing for use as a development tool for 65c02 computers. Specifically, I am creating this in response to "some bug" in my 65c02 SBC I recently put together ("the interrupt issue"). The idea is that you will place the 65c02 in this debugger and the debugger will take the place of the actual CPU in the computer being debugged. Then, the microcontroller will essentially run the whole show. It will drive the clock signal and it will have read (and probably, in some circumstances, write) access to the address and data buses. Theoretically it should allow me to extract quite literally every last bit of information I possibly can, in order to debug my design.

Longer-term, I hope to make this a useful tool throughout the "Navi65" project (my 65c02 SBC). I can imagine all sorts of fun shenanigans this tool could facilitate; it is, after all, WAY more powerful than the 65c02 system itself and has all sorts of peripherals, including USB. *wink wink*
